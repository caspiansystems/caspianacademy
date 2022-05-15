#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKV46F16.h"
#include "fsl_debug_console.h"
#include "fsl_ftm.h"

#include "dsp_cortex_m4.h"


#define FTM_SOURCE_CLOCK (CLOCK_GetFreq(kCLOCK_FastPeriphClk))

#define VECTOR_LENGTH		256
#define FIXED_POINT_SCALE	1024


/* Element-wise vector multiplication */
static void vector_mult_float(const float *p_src_1,
							  const float *p_src_2,
							  float *p_dst,
							  uint32_t num_elements) {
	register uint32_t itr;

	for (itr = 0; itr < num_elements; itr++)
		p_dst[itr] = p_src_1[itr] * p_src_2[itr];
}

static void vector_mult_fixed(const int32_t *p_src_1,
							  const int32_t *p_src_2,
							  int32_t *p_dst,
							  uint32_t num_elements) {
	register uint32_t itr;

	for (itr = 0; itr < num_elements; itr++)
		p_dst[itr] = p_src_1[itr] * p_src_2[itr];
}


int main(void) {

	ftm_config_t ftmInfo;
	uint32_t ctr_begin, ctr_end, ctr_diff;
	register uint32_t itr;
	static float var_1_float[VECTOR_LENGTH], var_2_float[VECTOR_LENGTH], out_var_float[VECTOR_LENGTH];
	static int32_t var_1_fixed[VECTOR_LENGTH], var_2_fixed[VECTOR_LENGTH], out_var_fixed[VECTOR_LENGTH];

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    /* Setup FTM */
    FTM_GetDefaultConfig(&ftmInfo);
    ftmInfo.prescale = kFTM_Prescale_Divide_1;
    FTM_Init(FTM0, &ftmInfo);

	/* Generate two random vectors in the range [-100 100] */
	for (itr = 0; itr < VECTOR_LENGTH; itr++) {
		var_1_float[itr] = (float)rand() / RAND_MAX * 200 - 100;
		var_1_fixed[itr] = var_1_float[itr] * FIXED_POINT_SCALE;
		var_2_float[itr] = (float)rand() / RAND_MAX * 200 - 100;
		var_2_fixed[itr] = var_2_float[itr] * FIXED_POINT_SCALE;
	}

    /* Set FTM timer period and start it. */
    FTM_SetTimerPeriod(FTM0, MSEC_TO_COUNT(1000U, FTM_SOURCE_CLOCK));
    FTM_StartTimer(FTM0, kFTM_SystemClock);

	ctr_begin = FTM0->CNT;
	vector_mult_float(&var_1_float[0], &var_2_float[0], &out_var_float[0], VECTOR_LENGTH);
	ctr_end = FTM0->CNT;
	ctr_diff = ctr_end - ctr_begin;
	printf("1) Custom implementation of floating-point multiplication. Clock cycles = %u\n", ctr_diff);

	ctr_begin = FTM0->CNT;
	asm_vector_mult_float(&var_1_float[0], &var_2_float[0], &out_var_float[0], VECTOR_LENGTH);
	ctr_end = FTM0->CNT;
	ctr_diff = ctr_end - ctr_begin;
	printf("2) Assembly floating-point multiplication. Clock cycles = %u\n", ctr_diff);

	ctr_begin = FTM0->CNT;
	vector_mult_fixed(&var_1_fixed[0], &var_2_fixed[0], &out_var_fixed[0], VECTOR_LENGTH);
	ctr_end = FTM0->CNT;
	ctr_diff = ctr_end - ctr_begin;
	printf("3) Custom implementation of fixed-point multiplication. Clock cycles = %u\n", ctr_diff);

	ctr_begin = FTM0->CNT;
	asm_vector_mult_fixed(&var_1_fixed[0], &var_2_fixed[0], &out_var_fixed[0], VECTOR_LENGTH);
	ctr_end = FTM0->CNT;
	ctr_diff = ctr_end - ctr_begin;
	printf("4) Assembly fixed-point multiplication. Clock cycles = %u\n", ctr_diff);

    return 0 ;
}
