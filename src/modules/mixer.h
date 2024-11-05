#ifndef mixer_h
#define mixer_h

#include "mbed.h"
#include "crazyflie.h"

//Mixer class
class Mixer{
    public: 
        Mixer();//construtor
        void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi);
        void arm();
        void disarm();

    private:
        // pwm dos motores
        PwmOut motor1, motor2, motor3, motor4;
        bool armed;
        DigitalOut led1, led4;

        //velocidades angulares
        float omega_1, omega_2, omega_3, omega_4;
        void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi);
        float control_motor(float omega);
        void pisca_led();
        

};


#endif