#ifndef __DRIVER_H
#define __DRIVER_H
#include "sys.h"
#include "stdlib.h"	

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�������вο���̳�������̵�һ����(http://www.openedv.com/thread-41832-1-1.html)
//ALIENTEKս��STM32������
//������������� ���Դ���			   
//lycreturn@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2016/05/12
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved	
//********************************************************************************
//�޸�����:2016/05/12
//////////////////////////////////////////////////////////////////////////////////
/********** ������ �˿ڶ��� **************
//DRIVER_DIR   PC0 
//DRIVER_OE    PC2 
//STEP_PULSE   PC7 (TIM8_CH2,LCD_RW)
******************************************/
#define DRIVER_DIR   PCout(0) // ��ת���� 
#define DRIVER_OE    PCout(2) // ʹ�ܽ� �͵�ƽ��Ч
#define RCR_VAL    255  //ÿ������RCR_VAL+1���Σ��ж�һ�Σ����ֵ��0~255�����ô�һЩ���Խ����ж�Ƶ��

typedef enum
{
	CW = 1,//�ߵ�ƽ˳ʱ��
	CCW = 0,//�͵�ƽ��ʱ��
}DIR_Type;//���з���

extern long target_pos;//�з��ŷ���
extern long current_pos;//�з��ŷ���

void Driver_Init(void);//��������ʼ��
void TIM8_OPM_RCR_Init(u16 arr,u16 psc);//TIM8_CH2 ���������+�ظ��������ܳ�ʼ��
void TIM8_Startup(u32 frequency);   //������ʱ��8
void Locate_Rle(long num,u32 frequency,DIR_Type dir); //��Զ�λ����
void Locate_Abs(long num,u32 frequency);//���Զ�λ����

#endif


