The project is used to drive DM556 based on data recieved form UART
	Hardware Resource£º
		///////////////////////////////
		1.UART			
			TX		PA9
			RX		PA10
		///////////////////////////////
		2.DM556_Driver_X			
			DIR		PC0 
			OE 		PC2 
			PUL		PC7 		al->TIM8_CH2,LCD_RW		
		///////////////////////////////
		3.Selector	default


		
	Software Resource:
		///////////////////////////////
		1.Structure "Frame"
			typedef struct{
				u8 par;
				/*|1 0 1 _|_ _ _ 1|*/
				//bit1: DIR		0->CW | 1->CCW;										CW  -> Clockwise | CCW -> Counter-Clockwise.
				//bit2: AXC		0->X  | 1->Y;										AXC -> axis of coordinates.
				//bit[3:4]: SPD 00->100Hz | 01->200Hz | 10->350Hz | 11->500Hz;		SPD -> Speed

				u8 step;						0~255
			}Frame;
		We define 16bit restricted by structure Frame as a Data_Frame.
		You should send Data_Frame whose Frame.step is 255 twice when you want to drive the step-moter 510 steps.
		When step-moter finish the motion,the MCU will send a 0x01 to PC via UART.
		Don't send next Data_Frame until recieve a 0x01 from the MCU.