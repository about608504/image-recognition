#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "usmart.h"	
#include "driver.h"
#include "FrameStruct.h"
#include "selector.h"
/************************************************
************************************************/
Frame CMD;



//LED状态设置函数
void led_set(u8 sta)
{
	LED1=sta;
} 
//函数参数调用测试函数
void test_fun(void(*ledset)(u8),u8 sta)
{
	ledset(sta);
}  	
 int main(void)
 {	 
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
 	LED_Init();			     //LED端口初始化
	LCD_Init();
	usmart_dev.init(SystemCoreClock/1000000);	//初始化USMART	
	Driver_Init();								//初始化DM556
	TIM8_OPM_RCR_Init(999,72-1); 				//1MHz计数频率  单脉冲+重复计数模式
	POINT_COLOR=RED;							
  	while(1) 
	{		 	  
		LED0=!LED0;
		delay_ms(500);	
	}			
 }

