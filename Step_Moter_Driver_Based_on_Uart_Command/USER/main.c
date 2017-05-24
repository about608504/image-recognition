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



//LED״̬���ú���
void led_set(u8 sta)
{
	LED1=sta;
} 
//�����������ò��Ժ���
void test_fun(void(*ledset)(u8),u8 sta)
{
	ledset(sta);
}  	
 int main(void)
 {	 
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	LCD_Init();
	usmart_dev.init(SystemCoreClock/1000000);	//��ʼ��USMART	
	Driver_Init();								//��ʼ��DM556
	TIM8_OPM_RCR_Init(999,72-1); 				//1MHz����Ƶ��  ������+�ظ�����ģʽ
	POINT_COLOR=RED;							
  	while(1) 
	{		 	  
		LED0=!LED0;
		delay_ms(500);	
	}			
 }

