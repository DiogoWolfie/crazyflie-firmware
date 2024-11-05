#include "mbed.h"
#include "crazyflie.h"



// Define all motors as PWM objects
PwmOut motor1(MOTOR1);


float control_motor(float omega)
{
    float motor = a2*(omega*omega) + a1*(omega);
    return motor;
}
// Main program
int main()
{
    
    //pwm frequency
    motor1.period(1.0/500);
    //turn on motor
    motor1 = control_motor(1000);
 
    wait(2);
    motor1 = 0.0;
    while(true){

    }
    
    
        
}
