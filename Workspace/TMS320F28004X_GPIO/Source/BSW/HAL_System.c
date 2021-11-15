/*
 * @Author: YellowNew
 * @Date: 2021-11-13 15:28:29
 * @LastEditors: Do not edit
 * @LastEditTime: 2021-11-13 15:45:21
 * @FilePath: \TMS320F28004X\Source\BSW\HAL_System.c
 * @Description: 
 * @Encoding: UTF-8
 */



#include "HAL_System.h"

void BSW_InitSystem()
{
    //Step 1. Initialize System Control:
    //PLL, WatchDog,enabe Peripheral Clocks
    //This example function is found in the f28004x_sysctrl.c file.
    //
    InitSysCtrl();

    //
    //Step 2. Initialize GPIO
    //
    InitGpio();

    //
    //Step 3. Clear all __interrupts and initialize PIE vector table:
    //Disable CPU __interrupts
    //
    DINT;

    //
    //Initialize the PIE control registers to their default state.
    //The default state is all PIE interrupts disabled and flags
    //are cleared.
    //
    InitPieCtrl();

    //
    //Disable CPU interrupts and clear all CPU interrupt flags:
    //
    IER = 0x0000;
    IFR = 0x0000;

    //
    //Initialize the PIE vector table with pointers to the shell Interrupt
    //Service Routines (ISR).
    //
    InitPieVectTable();
}



