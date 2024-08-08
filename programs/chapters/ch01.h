#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
DigitalOut led1(LED_GREEN_L,false);
DigitalOut led2(LED_BLUE_L,false);
DigitalOut led3(LED_RED_L,false);
DigitalOut led4(LED_RED_R,false);

// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);


// Main program
int main()
{
    // Blink blue LED indicating inicialization (5 seconds)

    // Turn on red LEDs indicating motors are armed
    
    // Test all motors with different frequencies (to make different noises)

    // Turn off red LEDs indicating motors are disarmed
    
    // Blink green LEDs indicating end of program
    motor1.period(1.0/400);
    motor2.period(1.0/500);
    motor3.period(1.0/600);
    motor4.period(1.0/700);
    while(true)
    {
        for(int i = 0; i==5; i++){
            led2 = !led2;
            wait(1);
        }
        

        //turn on
        led4 = !led4;
        led3 = !led3;


        motor1 = 0.2;
        wait(2);
        motor1 = 0.0;
    
        motor2 = 0.2;
        wait(2);
        motor2 = 0.0;

        motor3 = 0.2;
        wait(2);
        motor3 = 0.0;
        
        motor4 = 0.2;
        wait(2);
        motor4 = 0.0;

        //turn out
        led4 = !led4;
        led3 = !led3;

        led1 = !led1;
        wait(0.5);
        led1 = !led1;
        wait(0.5);
        led1 = !led1;
        wait(0.5);
        led1 = !led1;
        wait(0.5);
    }
}
