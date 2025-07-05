#include "stm32f10x.h"                  // Device header
#include "Motor.h"

void SmartCar_Init(void)
{
	Motor_Init();
}
void Move_Forward(void)
{
	LeftMotor_Speed(50);
	RightMotor_Speed(50);
}
void Move_Backward(void)
{
	LeftMotor_Speed(-50);
	RightMotor_Speed(-50);
}
void Car_Stop(void)
{
	LeftMotor_Speed(0);
	RightMotor_Speed(0);
}
void Turn_Left(void)
{
	LeftMotor_Speed(0);
	RightMotor_Speed(80);
}
void Turn_Right(void)
{
	LeftMotor_Speed(80);
	RightMotor_Speed(0);
}
void Clockwise_Rotation(void)
{
	LeftMotor_Speed(100);
	RightMotor_Speed(-100);
}
void CounterClockwise_Rotation(void)
{
	LeftMotor_Speed(-100);
	RightMotor_Speed(100);
}
