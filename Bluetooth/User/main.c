#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"
#include "SmartCar.h"
#include "Serial.h"
uint8_t RxData;
int main(void)
{
	SmartCar_Init();
	Serial_Init();
	while(1)
	{
		if(Serial_GetRxFlag()==1)
		{
			RxData=Serial_GetRxData();
		}
		if(RxData==0x40)
		{
			Move_Forward();
		}
		if(RxData==0x41)
		{
			Move_Backward();
		}
		if(RxData==0x42)
		{
			Car_Stop();
		}
		if(RxData==0x43)
		{
			Turn_Left();
		}
		if(RxData==0x44)
		{
			Turn_Right();
		}
		if(RxData==0x45)
		{
			Clockwise_Rotation();
		}
		if(RxData==0x46)
		{
			CounterClockwise_Rotation();
		}
	}
}


