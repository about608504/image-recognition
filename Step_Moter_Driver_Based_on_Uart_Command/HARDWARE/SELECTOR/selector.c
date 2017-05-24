#include"selector.h"


void AXC_SET_X(){
	GPIO_SetBits(GPIOE,GPIO_Pin_5);
}

void AXC_SET_Y(){
	GPIO_ResetBits(GPIOE,GPIO_Pin_5);
}

