#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "SmartCar.h"
#include "Serial.h"
#include "HCSR04.h"
#include "Servo.h"

uint16_t a,b,c,d,e,f,g;
int main(void)
{
	HCSR04_Init();
	OLED_Init();	
	SmartCar_Init();
	Servo_Init();
	Servo_SetAngle(90);
	OLED_ShowString(1,1,"Distance:");
	OLED_ShowString(2,4,"CM");
	Delay_ms(310);
	while(1)
	{
		Move_Forward();
		a=HCSR04_Distance();
		OLED_ShowNum(2,1,a,3);
		if(a<30)
		{
				Car_Stop();
				Servo_SetAngle(0);
				Delay_ms(1000);
				
				b=HCSR04_Distance();
				OLED_ShowNum(2,1,b,3);
				if(b>30)
				{
						Servo_SetAngle(90);
						Delay_ms(1000);
						Turn_Right();
						Delay_ms(1000);
						Move_Forward();	
				}
				else
				{
				
						Servo_SetAngle(180);
						Delay_ms(1000);
						
						c=HCSR04_Distance();
						OLED_ShowNum(2,1,c,3);
						if(c>30)
						{
							Servo_SetAngle(90);
							Delay_ms(1000);
							Turn_Left();
							Delay_ms(1000);
							Move_Forward();
				
						}
						else
						{
							Servo_SetAngle(90);
							Delay_ms(1000);
							CounterClockwise_Rotation();
							Delay_ms(1000);
							Car_Stop();
							d=HCSR04_Distance();
							OLED_ShowNum(2,1,d,3);	
							
								if(d>30)
								{
								Move_Forward();
								}
								else
								{
									Servo_SetAngle(0);
									Delay_ms(1000);
									e=HCSR04_Distance();
									OLED_ShowNum(2,1,e,3);
									if(e>30)
									{
									Servo_SetAngle(90);
									Delay_ms(1000);
									Turn_Right();
									Delay_ms(1000);
									Move_Forward();	
									}
									else
									{
									Servo_SetAngle(180);
									Delay_ms(1000);
									f=HCSR04_Distance();	
									OLED_ShowNum(2,1,f,3);	
						
										if(f>30)
										{
										Servo_SetAngle(90);
										Delay_ms(1000);
										Turn_Left();
										Delay_ms(1000);
										Move_Forward();	
										
										}
									else
									{
									Car_Stop();
									while(1);
									}
			
									}
								}
							}
					}
			}
	}
		
}
	
	


