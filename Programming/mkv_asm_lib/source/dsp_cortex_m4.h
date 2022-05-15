#ifndef DSP_CORTEX_M4_H_
#define DSP_CORTEX_M4_H_

void asm_vector_mult_float(const float *p_src_1,
		const float *p_src_2,
		float *p_dst,
		unsigned int num_elements);


void asm_vector_mult_fixed(const int *p_src_1,
		const int *p_src_2,
		int *p_dst,
		unsigned int num_elements);

#endif /* DSP_CORTEX_M4_H_ */
