/********************************************************/
/************** Name : Youssef Moghazy ******************/
/************** Date : 28/7/2023       ******************/
/************** SWC  : EXTI            ******************/
/************** Version : 1.0          ******************/
/********************************************************/
#ifndef EXTI_PRIVATE_h
#define EXTI_PRIVATE_h

/* Define for EXTI registers	*/

#define EXTI_u8_MCUCR						*((volatile u8 *)0x55)
#define EXTI_u8_MCUCSR						*((volatile u8 *)0x54)
#define EXTI_u8_GICR						*((volatile u8 *)0x5B)
#define EXTI_u8_GIFR						*((volatile u8 *)0x5A)
/* for Edge source*/
#define EXTI_u8_MCUCR_ISC00					0
#define EXTI_u8_MCUCR_ISC01					1
#define EXTI_u8_MCUCR_ISC10					2
#define EXTI_u8_MCUCR_ISC11					3
#define EXTI_u8_MCUCSR_ISC2					6
/*PIN 6 in GISR Register to Enable EXTI0 */
#define EXTI_u8_GICR_INT0					6
/*PIN 7 in GISR Register to Enable EXTI1 */
#define EXTI_u8_GICR_INT1					7
/*PIN 5 in GISR Register to Enable EXTI2 */
#define EXTI_u8_GICR_INT2					5
#endif
