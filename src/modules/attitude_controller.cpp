#include "attitude_controller.h"

AttitudeController::AttitudeController()
{
    thau_phi = 0.0;
    thau_theta = 0.0;
    thau_psi = 0.0;


}

void AttitudeController::control(float phi_r, float theta_r, float psi_r, float phi, float theta, 
float psi, float p, float q, float r)
{
    thau_phi = control_siso(phi_r, phi, p, Kp, Kd)*I_xx;
    thau_theta = control_siso(theta_r, theta, q, Kp, Kd)*I_yy;
    thau_psi = control_siso(psi_r, psi, r, Kp_psi, Kd_psi)*I_zz; 

}

float AttitudeController::control_siso(float angle_r, float angle, float rate, float kp, float kd)
{
    return kp*(angle_r-angle) + kd*(0.0-rate);
}