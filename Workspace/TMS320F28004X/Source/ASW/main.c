/*
 * main.c
 *
 *  Created on: 2021年11月12日
 *      Author: yello
 */

#include "F28x_Project.h"

#include "driverlib.h"
#include "device.h"

#if 1
void main()
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


