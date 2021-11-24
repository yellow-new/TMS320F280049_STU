/*
 * @Author: YellowNew
 * @Date: 2021-11-21 20:09:10
 * @LastEditTime: 2021-11-24 13:28:50
 * @Description: 
 * @FilePath: \TMS320F28004X_Sci\Source\BSW\HAL_Sci.h
 * @Encoding: UTF-8
 */
#ifndef _HAL_SCI_H_
#define _HAL_SCI_H_

#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"
#include "BaseType.h"




union UNION_FLOAT_2UINT
{
    FLOAT32 f32data;
    UINT16 u16ata[2];
};


static inline void SciWriteBtye(Uint16 t_u16Btye)
{
    //while(0 == SciaRegs.SCICTL2.bit.TXRDY);
    SciaRegs.SCITXBUF.all = t_u16Btye;
    while(0 == SciaRegs.SCICTL2.bit.TXEMPTY);
}

static inline UINT16 DEV_SCIReadBtye(void)
{
    //SciaRegs.SCIRXST.bit.RXRDY
    return SciaRegs.SCIRXBUF.bit.SAR;
}


extern void BSW_InitScia(void);

void WriteArray(UINT16 *pData, UINT16 t_u16Length);
extern void VcanScope(UINT16 *pData, UINT16 t_u16Length);
extern void VcanScopeFolat(float *t_pf32Data,  UINT16 t_u16Length);







#endif /*_HAL_SCI_H_*/



