#include "horizontal_controller.h"

HorizontalController::HorizontalController()
{
    theta_r = 0.0;
    phi_r = 0.0;

}

void HorizontalController::control(float x_r, float y_r, float x, float y, float u, float v)
{
    theta_r = (1.0/g)*control_siso(x_r, x, u, kp_h, kd_h);
    phi_r = -(1.0/g)*control_siso(y_r, y, v, kp_h, kd_h);
}

float HorizontalController::control_siso(float position_r, float position, float velocity, float kp, float kd)
{
    return position_r = kp*(position_r-position) + kd*(0.0-velocity);
}