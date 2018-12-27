#line 1 "D:/Clicks_git/B/BarGraph_3_Click/SW/example/c/ARM/STM/Click_BarGraph3_STM.c"
#line 1 "d:/clicks_git/b/bargraph_3_click/sw/example/c/arm/stm/click_bargraph3_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/b/bargraph_3_click/sw/example/c/arm/stm/click_bargraph3_config.h"
#line 1 "d:/clicks_git/b/bargraph_3_click/sw/example/c/arm/stm/click_bargraph3_types.h"
#line 3 "d:/clicks_git/b/bargraph_3_click/sw/example/c/arm/stm/click_bargraph3_config.h"
const uint32_t _BARGRAPH3_SPI_CFG[ 2 ] =
{
 _SPI_FPCLK_DIV256,
 _SPI_FIRST_CLK_EDGE_TRANSITION |
 _SPI_CLK_IDLE_LOW |
 _SPI_MASTER |
 _SPI_MSB_FIRST |
 _SPI_8_BIT |
 _SPI_SSM_ENABLE |
 _SPI_SS_DISABLE |
 _SPI_SSI_1
};
#line 1 "d:/clicks_git/b/bargraph_3_click/sw/library/__bargraph3_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 57 "d:/clicks_git/b/bargraph_3_click/sw/library/__bargraph3_driver.h"
extern const uint8_t _BARGRAPH3_INCREASE_LED;
extern const uint8_t _BARGRAPH3_CONTROL_ONE_LED;

extern const uint8_t _BARGRAPH3_DIRECTION_TOP_TO_BOTTOM;
extern const uint8_t _BARGRAPH3_DIRECTION_BOTTOM_TO_TOP;

extern const uint8_t _BARGRAPH3_DEVICE_ENABLE;
extern const uint8_t _BARGRAPH3_DEVICE_DISABLE;

extern const uint8_t _BARGRAPH3_LED_0;
extern const uint8_t _BARGRAPH3_LED_1;
extern const uint8_t _BARGRAPH3_LED_2;
extern const uint8_t _BARGRAPH3_LED_3;
extern const uint8_t _BARGRAPH3_LED_4;
extern const uint8_t _BARGRAPH3_LED_5;
#line 82 "d:/clicks_git/b/bargraph_3_click/sw/library/__bargraph3_driver.h"
void bargraph3_spiDriverInit( const uint8_t*  gpioObj,  const uint8_t*  spiObj);
#line 92 "d:/clicks_git/b/bargraph_3_click/sw/library/__bargraph3_driver.h"
void bargraph3_gpioDriverInit( const uint8_t*  gpioObj);
#line 99 "d:/clicks_git/b/bargraph_3_click/sw/library/__bargraph3_driver.h"
void bargraph3_enable(uint8_t state);
#line 104 "d:/clicks_git/b/bargraph_3_click/sw/library/__bargraph3_driver.h"
void bargraph3_reset();
#line 109 "d:/clicks_git/b/bargraph_3_click/sw/library/__bargraph3_driver.h"
void bargraph3_setPWM(uint8_t state);
#line 118 "d:/clicks_git/b/bargraph_3_click/sw/library/__bargraph3_driver.h"
void bargraph3_display(uint8_t ctrl, uint8_t dir, uint8_t counter);
#line 30 "D:/Clicks_git/B/BarGraph_3_Click/SW/example/c/ARM/STM/Click_BarGraph3_STM.c"
uint32_t leddriver5_pwmInit(uint16_t freq)
{
 uint32_t pwmPeriod;

 pwmPeriod = PWM_TIM5_Init(freq);

 return pwmPeriod;
}

void leddriver5_pwmSetDuty(uint16_t duty)
{
 PWM_TIM5_Set_Duty(duty, _PWM_NON_INVERTED, _PWM_CHANNEL1);
}

void leddriver5_pwmStart()
{
 PWM_TIM5_Start(_PWM_CHANNEL1, &_GPIO_MODULE_TIM5_CH1_PA0);
}

void leddriver5_pwmStop()
{
 PWM_TIM5_Stop( _PWM_CHANNEL1 );
}

void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_OUTPUT );

 mikrobus_spiInit( _MIKROBUS1, &_BARGRAPH3_SPI_CFG[0] );
 Delay_100ms();

 leddriver5_pwmInit( 100 );
 leddriver5_pwmSetDuty(30000);
 leddriver5_pwmStart();
 Delay_100ms();

}

void applicationInit()
{
 bargraph3_spiDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_SPI );
 bargraph3_enable( _BARGRAPH3_DEVICE_ENABLE );

}

void applicationTask()
{
 uint8_t bargraph_cnt;

 for (bargraph_cnt = 0; bargraph_cnt <= 5; bargraph_cnt++)
 {
 bargraph3_display(_BARGRAPH3_INCREASE_LED, _BARGRAPH3_DIRECTION_BOTTOM_TO_TOP, bargraph_cnt);
 Delay_1sec();
 }
}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
