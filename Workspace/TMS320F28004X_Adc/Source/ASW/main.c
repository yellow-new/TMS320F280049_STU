/*
 * @Author: YellowNew
 * @Date: 2021-11-12 21:32:07
 * @LastEditors: Do not edit
 * @LastEditTime: 2021-11-15 19:56:44
 * @FilePath: \TMS320F28004X_GPIO\Source\ASW\main.c
 * @Description: 
 * @Encoding: UTF-8
 */

#include "main.h"


#if 1
void main()
{

    BSW_InitSystem();

    BSW_InitGpio();


     //
     for(;;)
     {
         //
         // Turn on LED
         //
         LED_ON();

         //
         // Delay for a bit.
         //
         DELAY_US(500000);

         //
         // Turn off LED
         //
         LED_OFF();

         //
         // Delay for a bit.
         //
         DELAY_US(500000);
     }

}
#else

void main(void)
{
    //
    // Initializes system control, device clock, and peripherals
    //
    Device_init();

    //
    // Initializes PIE and clear PIE registers. Disables CPU interrupts.
    // and clear all CPU interrupt flags.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

    while(1);

}

#endif


