#include "mbed.h"
#include "crazyflie.h"

PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);



//define velocidades angulares
float omega_1;
float omega_2;
float omega_3;
float omega_4;



//controlador do motor
float control_motor(float omega)
{
    float motor = a2*(omega*omega) + a1*(omega);
    return motor;
}

void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi){
    //trequinhos para a conta
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

void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi){
    mixer(f_t, tau_phi, tau_theta, tau_psi);
    motor1 = control_motor(omega_1);
    motor2 = control_motor(omega_2);
    motor3 = control_motor(omega_3);
    motor4 = control_motor(omega_4);
    
}

int main(){

    motor1.period(1.0/500.0);
    motor2.period(1.0/500.0);
    motor3.period(1.0/500.0);
    motor4.period(1.0/500.0);
    
    actuate(0.15,0,0,0);

    wait(5);

    actuate(0,0,0,0);

    while(true){
        //termina o programa
    }





}