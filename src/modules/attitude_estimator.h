#ifndef attitude_estimator_h
#define attitude_estimator_h

#include "mbed.h"
#include "crazyflie.h"

//Attitude estimador classe
class AttitudeEstimator{
    public:
    AttitudeEstimator(); //contrutor da classe
    void init(); //iniccializa a classe
    void estimate(); //estimador dos angulos de euler e velocidades angulares
    float phi,theta, psi; //angulos de euler
    float p,q,r; //velcidades angulares

    private:
    //imu sensor object
    BMI088 imu;
};

#endif