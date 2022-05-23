#include "xc.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/watchdog.h"
#include <stdio.h>


int main(void)
{
    /* Initialize the device */
    SYSTEM_Initialize();
      
    uint8_t tx_byte = 0;
    uint16_t adc_val = 0;
    
    while (1)
    {
        /* Turn ON LED2 */
        LATCbits.LATC9 = 1;
        
        /* Read ADC voltage and send it to UART */
        adc_val = ADC1_GetConversion(channel_AN0);
        tx_byte = (adc_val >> 8) & 0xFF;    /* Get the first byte (MSB) */
        UART1_Write(tx_byte++);
        tx_byte = (adc_val >> 0) & 0xFF;    /* Get the second byte (LSB) */
        UART1_Write(tx_byte++);
        
        /* Wait for steady-state power measurement */
        for (uint32_t itr = 0; itr < 3000000; itr++) {}
        
//        /* Turn OFF LED2 */
//        LATCbits.LATC9 = 0;
//        
//        SYSTEM_RegUnlock();     /* Unlocks the write protected register */
//        RNMICONbits.WDTS = 0;   /* Clear sleep WDTS flag */
//        RCONbits.WDTO = 0;      /* Clear WDTO flag */
//        SYSTEM_RegLock();       /* Locks the write protected register */
//        
//        /* Clear and start WDT */
//        WATCHDOG_TimerClear();
//        WATCHDOG_TimerSoftwareEnable();
//
//        /* Bring the system to sleep or idle mode */
//        asm volatile("wait");
//        
//        /* Stop WDT */
//        WDT_TimerSoftwareDisable();        
    }
    return 1; 
}
/**
 End of File
*/

