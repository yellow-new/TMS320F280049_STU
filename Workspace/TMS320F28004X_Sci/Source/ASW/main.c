/*
 * @Author: YellowNew
 * @Date: 2021-11-12 21:32:07
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-11-24 16:03:32
 * @FilePath: \TMS320F28004X_Sci\Source\ASW\main.c
 * @Description: 
 * @Encoding: UTF-8
 */
#include "main.h"

UINT16 Number[10];
UINT16 i;
#if 1
void main()
{

    //
    // 系统初始化
    //
    BSW_InitSystem();

    //
    // Gpio初始化
    //
    BSW_InitGpio();

    //
    // Sci初始化
    //
    BSW_InitScia();


    for (  i = 0; i < 10; i++)
    {
        Number[i]= i;
        /* code */
    }
    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    EINT;
    ERTM;

     for(;;)
     {
         WriteArray(Number,10);        
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


