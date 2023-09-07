/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 29/7/2023       ******************/
/************** SWC  : GI              ******************/
/************** Version : 1.0          ******************/
/********************************************************/

/* Lib layer */
#include "../../lib/STD_TYPES/STD_TYPES.h"
/*MCAL*/
#include "GI_interface.h"
#include "GI_private.h"

void GI_voidEnable(void)
{
	SREG|=(STD_TYPES_TRUE<<SREG_I_BIT);
}

void GI_voidDisable(void)
{
	SREG&=~(STD_TYPES_TRUE<<SREG_I_BIT);
}



