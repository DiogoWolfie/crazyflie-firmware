#include "mbed.h"
#include "crazyflie.h"

//declarando um objeto do tipo Mixer
Mixer mixer;

int main(){

    mixer.arm();
    mixer.acurate(0.15,0,0,0.001);
    wait(5);
    mixer.disarm();

    while(true){


    }

}