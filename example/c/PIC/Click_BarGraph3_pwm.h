#include "Click_BarGraph3_types.h"


uint32_t bargraph3_pwmInit(uint16_t freq)
{
	PWM2_Init( 5000 );
	return 0;
}

void bargraph3_pwmSetDuty(uint16_t duty)
{
    PWM2_Set_Duty( duty );
}

void bargraph3_pwmStart()
{
    PWM2_Start();
}

void bargraph3_pwmStop()
{
    PWM2_Stop();
}