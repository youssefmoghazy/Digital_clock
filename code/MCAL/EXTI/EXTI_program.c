/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 28/7/2023       ******************/
/************** SWC  : EXTI            ******************/
/************** Version : 1.0          ******************/
/********************************************************/
#include "../../lib/BIT_Math/BIT_MATH.h"
#include "../../lib/STD_TYPES/STD_TYPES.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

/*Global pointer to function */
static void(*EXTI_APFEXTI[EXTI_u8_INTI_NUM])(void)= {NULL,NULL,NULL};


u8 EXTI_u8EXTIEnable(u8 copy_u8EXTIIndex, u8 copy_u8EdgeIndex)
{
    u8 Local_u8ErrorState= STD_TYPES_OK;
    switch(copy_u8EXTIIndex)
    {
    case EXTI_u8_INTI0:
        switch(copy_u8EdgeIndex)
        {
        case EXTI_u8_RAISING_ADGE:
            EXTI_u8_MCUCR|=(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC00);
            EXTI_u8_MCUCR|=(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC01);
            /*Enable EXTI0 */
            EXTI_u8_GICR|=(STD_TYPES_TRUE<<EXTI_u8_GICR_INT0);
            break;
        case EXTI_u8_FALLING_ADGE:
            EXTI_u8_MCUCR&=~(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC00);
            EXTI_u8_MCUCR|=(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC01);
            /*Enable EXTI0 */
            EXTI_u8_GICR|=(STD_TYPES_TRUE<<EXTI_u8_GICR_INT0);
            break;
        case EXTI_u8_ANY_LOGICAL_CHANGE:
            EXTI_u8_MCUCR|=(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC00);
            EXTI_u8_MCUCR&=~(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC01);
            /*Enable EXTI0 */
            EXTI_u8_GICR|=(STD_TYPES_TRUE<<EXTI_u8_GICR_INT0);
            break;
        case EXTI_u8_LOW_LEVEL:
            EXTI_u8_MCUCR&=~(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC00);
            EXTI_u8_MCUCR&=~(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC01);
            /*Enable EXTI0 */
            EXTI_u8_GICR|=(STD_TYPES_TRUE<<EXTI_u8_GICR_INT0);
            break;
        default:
            Local_u8ErrorState =STD_TYPES_NOK;
        }
        break;
    case EXTI_u8_INTI1:
        switch(copy_u8EdgeIndex)
        {
        case EXTI_u8_RAISING_ADGE:
            EXTI_u8_MCUCR|=(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC10);
            EXTI_u8_MCUCR|=(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC11);
            /*Enable EXTI1 */
            EXTI_u8_GICR|=(STD_TYPES_TRUE<<EXTI_u8_GICR_INT1);
            break;
        case EXTI_u8_FALLING_ADGE:
            EXTI_u8_MCUCR&=~(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC10);
            EXTI_u8_MCUCR|=(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC11);
            /*Enable EXTI1 */
            EXTI_u8_GICR|=(STD_TYPES_TRUE<<EXTI_u8_GICR_INT1);
            break;
        case EXTI_u8_ANY_LOGICAL_CHANGE:
            EXTI_u8_MCUCR|=(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC10);
            EXTI_u8_MCUCR&=~(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC11);
            /*Enable EXTI1 */
            EXTI_u8_GICR|=(STD_TYPES_TRUE<<EXTI_u8_GICR_INT1);
            break;
        case EXTI_u8_LOW_LEVEL:
            EXTI_u8_MCUCR&=~(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC10);
            EXTI_u8_MCUCR&=~(STD_TYPES_TRUE<<EXTI_u8_MCUCR_ISC11);
            /*Enable EXTI1 */
            EXTI_u8_GICR|=(STD_TYPES_TRUE<<EXTI_u8_GICR_INT1);
            break;
        default:
            Local_u8ErrorState =STD_TYPES_NOK;
        }
        break;
    case EXTI_u8_INTI2:
        switch(copy_u8EdgeIndex)
        {
        case EXTI_u8_RAISING_ADGE:
            EXTI_u8_MCUCSR|=(STD_TYPES_TRUE<<EXTI_u8_MCUCSR_ISC2);
            /*Enable EXTI2 */
            EXTI_u8_GICR|=(STD_TYPES_TRUE<<EXTI_u8_GICR_INT2);
            break;
        case EXTI_u8_FALLING_ADGE:
            EXTI_u8_MCUCSR&=~(STD_TYPES_TRUE<<EXTI_u8_MCUCSR_ISC2);
            /*Enable EXTI2 */
            EXTI_u8_GICR|=(STD_TYPES_TRUE<<EXTI_u8_GICR_INT2);
            break;
        default:
            Local_u8ErrorState =STD_TYPES_NOK;
        }
        break;
    default:
        Local_u8ErrorState =STD_TYPES_NOK;

    }

    return Local_u8ErrorState;
}

u8 EXTI_u8EXTIDisable(u8 copy_u8EXTIIndex)
{
    u8 Local_u8ErrorState= STD_TYPES_OK;
    switch(copy_u8EXTIIndex)
    {
    case EXTI_u8_INTI0:
        /*Disable EXTI0*/
        EXTI_u8_GICR&=~(STD_TYPES_TRUE<<EXTI_u8_GICR_INT0);
        break;
    case EXTI_u8_INTI1:
        /*Disable EXTI1*/
        EXTI_u8_GICR&=~(STD_TYPES_TRUE<<EXTI_u8_GICR_INT1);
        break;
    case EXTI_u8_INTI2:
        /*Disable EXTI2*/
        EXTI_u8_GICR&=~(STD_TYPES_TRUE<<EXTI_u8_GICR_INT2);
        break;
    default:
        Local_u8ErrorState =STD_TYPES_NOK;
    }
    return Local_u8ErrorState;
}

u8 EXTI_u8EXTISetCallBack(u8 copy_u8EXTIIndex,void(*copy_pf)(void))
{
    u8 Local_u8ErrorState= STD_TYPES_OK;
    if((copy_u8EXTIIndex <=EXTI_u8_INTI2)&&(*copy_pf != NULL))
    {
        EXTI_APFEXTI[copy_u8EXTIIndex]=copy_pf;
    }
    else
    {
        Local_u8ErrorState= STD_TYPES_NOK;
    }
    return Local_u8ErrorState;
}

/*prototype for ISRof EXTI0*/
void __vector_1 (void)		__attribute__((signal));
void __vector_1	(void)
{
    if(EXTI_APFEXTI[EXTI_u8_INTI0] != NULL)
    {
        EXTI_APFEXTI[EXTI_u8_INTI0]();
    }
}

/*prototype for ISRof EXTI1*/
void __vector_2 (void)		__attribute__((signal));
void __vector_2	(void)
{
    if(EXTI_APFEXTI[EXTI_u8_INTI1] != NULL)
    {
        EXTI_APFEXTI[EXTI_u8_INTI1]();
    }
}

/*prototype for ISRof EXTI2*/
void __vector_3 (void)		__attribute__((signal));
void __vector_3	(void)
{
    if(EXTI_APFEXTI[EXTI_u8_INTI2] != NULL)
    {
        EXTI_APFEXTI[EXTI_u8_INTI2]();
    }
}








