#include "vertical_controller.h"

VerticalController::VerticalController()
{
    f_t = 0.0;
}

void VerticalController::control(float z_r, float z, float w)
{
    float ac_zr = control_siso(z_r, z, w, kp_v, kd_v);
    f_t = m*(g+ ac_zr);
}

float VerticalController::control_siso(float pos_r, float pos, float vel, float kp, float kd){
    return kp*(pos_r - pos) + kd*(0.0-vel);
}