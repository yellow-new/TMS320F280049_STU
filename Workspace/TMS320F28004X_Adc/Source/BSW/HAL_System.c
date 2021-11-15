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
    //
    // Initialize device clock and peripherals
    //
    InitSysCtrl();

    //
    // Initialize GPIO and configure the GPIO pin as a push-pull output
    //
    InitGpio();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    DINT;
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    InitPieVectTable();

    //
    // Enable Global Interrupt (INTM) and realtime interrupt (DBGM)
    //
    EINT;
    ERTM;

}



