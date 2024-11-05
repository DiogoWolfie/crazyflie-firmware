#include "mixer.h"

Mixer::Mixer() : motor1(MOTOR1), motor2(MOTOR2), motor3(MOTOR3), motor4(MOTOR4), led1(LED_GREEN_R,true), led4(LED_GREEN_L,true)
{
    motor1.period(1.0/500.0);
    motor2.period(1.0/500.0);
    motor3.period(1.0/500.0);
    motor4.period(1.0/500.0);
    motor1 = 0.0;
    motor2 = 0.0;
    motor3 = 0.0;
    motor4 = 0.0;
    armed = false;
    

} 

void Mixer::actuate(float f_t, float tau_phi, float tau_theta, float tau_psi){
    if(armed){
        mixer(f_t, tau_phi, tau_theta, tau_psi);
        motor1 = control_motor(omega_1);
        motor2 = control_motor(omega_2);
        motor3 = control_motor(omega_3);
        motor4 = control_motor(omega_4);
    }
    
}

void Mixer::mixer(float f_t, float tau_phi, float tau_theta, float tau_psi){
    float al = 1/(4.0*kl);
    float at = 1/(4.0*kd);

    float o1 = al*f_t - (al/l)*tau_phi -(al/l)*tau_theta - at*tau_psi;
    float o2 = al*f_t - (al/l)*tau_phi +(al/l)*tau_theta + at*tau_psi;
    float o3 = al*f_t + (al/l)*tau_phi +(al/l)*tau_theta - at*tau_psi;
    float o4 = al*f_t + (al/l)*tau_phi -(al/l)*tau_theta + at*tau_psi;
    if(o1 >= 0){
        omega_1 = sqrt(o1);
    }else{
        omega_1= 0.0;
    }

    if(o2 >= 0){
        omega_2 = sqrt(o2);
    }else{
        omega_2= 0.0;
    }

    if(o3 >= 0){
        omega_3 = sqrt(o3);
    }else{
        omega_3= 0.0;
    }

    if(o4 >= 0){
        omega_4 = sqrt(o4);
    }else{
        omega_4= 0.0;
    }
    
}

//converte a velocidade angular desejada para sinal de PWM
float Mixer::control_motor(float omega){
    float motor = a2*(omega*omega) + a1*(omega);
    return motor;
}

void Mixer::pisca_led(){

    for(int i = 0; i < 5; i++){
        led1 = !led1;
        led4 = !led4;
        wait(0.5);
        led1 = !led1;
        led4 = !led4;
        wait(0.5);
    }

}


void Mixer::arm(){

   
    // motor1.period(1.0/392.0);
    // motor1 = 0.1;
    // motor2.period(1.0/392.0);
    // motor2 = 0.1;
    // motor3.period(1.0/392.0);
    // motor3 = 0.1;
    // motor4.period(1.0/392.0);
    // motor4 = 0.1;
    // wait(1.0);

    // motor1.period(1.0/466.16);
    // motor1 = 0.1;
    // motor2.period(1.0/466.16);
    // motor2 = 0.1;
    // motor3.period(1.0/466.16);
    // motor3 = 0.1;
    // motor4.period(1.0/466.16);
    // motor4 = 0.1;
    // wait(0.3);

    // motor1.period(1.0/440.0);
    // motor1 = 0.1;
    // motor2.period(1.0/440.0);
    // motor2 = 0.1;
    // motor3.period(1.0/440.0);
    // motor3 = 0.1;
    // motor4.period(1.0/440.0);
    // motor4 = 0.1;
    // wait(0.5);

    // motor1.period(1.0/349.23);
    // motor1 = 0.1;
    // motor2.period(1.0/349.23);
    // motor2 = 0.1;
    // motor3.period(1.0/349.23);
    // motor3 = 0.1;
    // motor4.period(1.0/349.23);
    // motor4 = 0.1;
    // wait(1.0);

    // motor1.period(1.0/587.33);
    // motor1 = 0.1;
    // motor2.period(1.0/587.33);
    // motor2 = 0.1;
    // motor3.period(1.0/587.33);
    // motor3 = 0.1;
    // motor4.period(1.0/587.33);
    // motor4 = 0.1;
    // wait(0.5);

    // motor1.period(1.0/523.25);
    // motor1 = 0.1;
    // motor2.period(1.0/523.25);
    // motor2 = 0.1;
    // motor3.period(1.0/523.25);
    // motor3 = 0.1;
    // motor4.period(1.0/523.25);
    // motor4 = 0.1;
    // wait(1.2);

    // motor1.period(1.0/440.0);
    // motor1 = 0.1;
    // motor2.period(1.0/440.0);
    // motor2 = 0.1;
    // motor3.period(1.0/440.0);
    // motor3 = 0.1;
    // motor4.period(1.0/440.0);
    // motor4 = 0.1;
    // wait(1.2);

    // motor1.period(1.0/392.0);
    // motor1 = 0.1;
    // motor2.period(1.0/392.0);
    // motor2 = 0.1;
    // motor3.period(1.0/392.0);
    // motor3 = 0.1;
    // motor4.period(1.0/392.0);
    // motor4 = 0.1;
    // wait(1.0);

    // motor1.period(1.0/466.16);
    // motor1 = 0.1;
    // motor2.period(1.0/466.16);
    // motor2 = 0.1;
    // motor3.period(1.0/466.16);
    // motor3 = 0.1;
    // motor4.period(1.0/466.16);
    // motor4 = 0.1;
    // wait(0.3);

    // motor1.period(1.0/440.0);
    // motor1 = 0.1;
    // motor2.period(1.0/440.0);
    // motor2 = 0.1;
    // motor3.period(1.0/440.0);
    // motor3 = 0.1;
    // motor4.period(1.0/440.0);
    // motor4 = 0.1;
    // wait(0.5);

    // motor1.period(1.0/349.23);
    // motor1 = 0.1;
    // motor2.period(1.0/349.23);
    // motor2 = 0.1;
    // motor3.period(1.0/349.23);
    // motor3 = 0.1;
    // motor4.period(1.0/349.23);
    // motor4 = 0.1;
    // wait(1.0);

    // motor1.period(1.0/415.30);
    // motor1 = 0.1;
    // motor2.period(1.0/415.30);
    // motor2 = 0.1;
    // motor3.period(1.0/415.30);
    // motor3 = 0.1;
    // motor4.period(1.0/415.30);
    // motor4 = 0.1;
    // wait(0.5);

    // motor1.period(1.0/293.66);
    // motor1 = 0.1;
    // motor2.period(1.0/293.66);
    // motor2 = 0.1;
    // motor3.period(1.0/293.66);
    // motor3 = 0.1;
    // motor4.period(1.0/293.66);
    // motor4 = 0.1;
    // wait(1.6);

    // motor1.period(1.0/293.66);
    // motor1 = 0.1;
    // motor2.period(1.0/293.66);
    // motor2 = 0.1;
    // motor3.period(1.0/293.66);
    // motor3 = 0.1;
    // motor4.period(1.0/293.66);
    // motor4 = 0.1;
    // wait(0.5);



    // motor1 = 0.0;
    // motor2 = 0.0;
    // motor3 = 0.0;
    // motor4 = 0.0;

    pisca_led();
    armed = true;
         
}

void Mixer::disarm(){
    actuate(0.0, 0.0, 0.0, 0.0);
    armed = false;
    led4 = !led4;
    led1 = !led1;
    

}