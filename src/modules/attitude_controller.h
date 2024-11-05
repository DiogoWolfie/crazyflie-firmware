#ifndef attitude_controller_h
#define attitude_controller_h

#include "mbed.h"
#include "crazyflie.h"

//classe do controlador de atitude
class AttitudeController
{
    public:
    AttitudeController();

    void control(float phi_r,float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r);
    float thau_phi, thau_theta, thau_psi;

    private:
    float control_siso(float angle_r, float angle, float rate, float kp, float kd);
};

#endif