#include "mbed.h"
#include "crazyflie.h"

PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);


float control_motor(float omega)
{
    float motor = a2*(omega*omega) + a1*(omega);
    return motor;
}

int main(){

    motor1.period(1.0/500);
    motor2.period(1.0/500);
    motor3.period(1.0/500);
    motor4.period(1.0/500);
    while(true){

        
        motor1 = control_motor(2000);
        motor2 = control_motor(2000);
        motor3 = control_motor(2000);
        motor4 = control_motor(2000);
        wait(5);

        motor1 = 0.0;
        motor2 = 0.0;
        motor3 = 0.0;
        motor4 = 0.0;

        wait(5);


    }





}