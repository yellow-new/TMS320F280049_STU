/*
 * @Author: YellowNew
 * @Date: 2021-11-21 20:08:58
 * @LastEditTime: 2021-11-24 15:42:30
 * @Description: 
 * @FilePath: \TMS320F28004X_Sci\Source\BSW\HAL_Sci.c
 * @Encoding: UTF-8
 */

#include "HAL_Sci.h"

void BSW_InitScia(void)
{
	GPIO_SetupPinMux(28, GPIO_MUX_CPU1, 1);
	GPIO_SetupPinOptions(28, GPIO_INPUT, GPIO_PUSHPULL);
	GPIO_SetupPinMux(29, GPIO_MUX_CPU1, 1);
	GPIO_SetupPinOptions(29, GPIO_OUTPUT, GPIO_ASYNC);

	SciaRegs.SCICCR.all = 0x0007;               // 1 stop bit,  odd parity, No parity
                                  				// 8 char bits 
	SciaRegs.SCICTL1.all = 0x0003;           	// enable TX, RX, internal SCICLK,
                                			    // Disable RX ERR INT, SLEEP, TXWAKE，初始化SCI状态机和操作标志位
	SciaRegs.SCIHBAUD.all = 0x0000;             // SCI BAUD = LSPCLK(25M)/((BRR+1)*8)
	SciaRegs.SCILBAUD.all = 26;                 // BRR =  LSPCLK/(SCI BAUD*8)-1  26--115200

	SciaRegs.SCICTL2.bit.TXINTENA =0;		    //禁止中断
	SciaRegs.SCICTL2.bit.RXBKINTENA =0;

	SciaRegs.SCICTL1.all = 0x0023;    		    // enable SCI
}


void WriteArray(UINT16 *pData, UINT16 t_u16Length)
{
    UINT16 i = 0;
    for(i=0; i<t_u16Length; i++)
    {
        SciWriteBtye(pData[i]);
    }
}



