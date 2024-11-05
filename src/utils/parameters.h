#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

//pwm
const float a2 = 1.2369e-7;
const float a1 = 4.9783e-12;

//constantes kd (cte de arrasto) e kl (cte de sustentação)
const float kl = 1.7e-8;
const float kd = 1.53e-10;


const float dt = 2.0e-3;
const float dt_range = 50.0e-3;
//filtro passa-baixa
const float wc = 1.0; //rad/s
const float alpha  = wc*dt/(1.0 + wc*dt);

//controle
const float Ts = 0.3;
const float Up = 0.005;
const float zeta = abs(log(Up))/sqrt(pow(pi,2)+pow(log(Up),2));
const float wn = 4/(Ts*zeta);
const float Kp = pow(wn,2);
const float Kd = 2*zeta*wn;

const float Ts_psi = 0.6;
const float Up_psi = 0.005;
const float zeta_psi = abs(log(Up_psi))/sqrt(pow(pi,2)+pow(log(Up_psi),2));
const float wn_psi = 4/(Ts_psi*zeta_psi);
const float Kp_psi = pow(wn_psi,2);
const float Kd_psi = 2*zeta_psi*wn_psi;

//parâmetros do estimador vertical
const float wv = 10.0;
const float zeta_v = sqrt(2.0)/2.0;
const float l1 = pow(wv,2);
const float l2 = 2.0*zeta_v*wv;


//controlador vertical
const float Ts_v = 2.0;
const float Up_v = 0.005;
const float zeta_v_controller = abs(log(Up_v))/sqrt(pow(pi,2)+pow(log(Up_v),2));
const float wv_c = 4/(Ts_v*zeta_v_controller);
const float kp_v = pow(wv_c,2);
const float kd_v = 2*zeta_v_controller*wv_c;

//controlador horizontal
const float ang = 42.0*pi/180.0;
const float delta = 2.0*tan(ang/2.0)/(420.0*dt);
const float wh = 50.0;

const float Ts_h = 2.0;
const float Up_h = 0.005;
const float zeta_h = abs(log(Up_h))/sqrt(pow(pi,2)+pow(log(Up_h),2));
const float wn_h = 4/(Ts_h*zeta_h);
const float kp_h = pow(wn_h,2);
const float kd_h = 2*zeta_h*wn_h;
#endif