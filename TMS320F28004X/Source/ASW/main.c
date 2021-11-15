/*
 * @Author: YellowNew
 * @Date: 2021-11-12 21:32:07
 * @LastEditors: Do not edit
 * @LastEditTime: 2021-11-14 11:27:32
 * @FilePath: \TMS320F28004X\Source\ASW\main.c
 * @Description: 
 * @Encoding: UTF-8
 */

#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"
#include "main.h"

#if 1
void main()
{
//
// 初始化系统
//
    BSW_InitSystem();
    while(1)
    {
        ESTOP0;
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


