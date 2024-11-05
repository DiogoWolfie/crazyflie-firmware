#include "attitude_estimator.h"
#include <cmath>

//erros sistemáticos
float p_bias;
float q_bias;
float r_bias;

// classe contrutor
AttitudeEstimator::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL) {
  phi = 0.0;
  theta = 0.0;
  psi = 0.0;
  p = 0.0;
  q = 0.0;
  r = 0.0;
}

// inicializador da classe
void AttitudeEstimator ::init() {
  imu.init(); // inicializa o sensor imu
  for (int i = 0; i < 500; i++) {
    imu.read();
    p_bias = p_bias + imu.gx;
    q_bias = q_bias + imu.gy;
    r_bias = r_bias + imu.gz;
    wait(dt);
  }
  p_bias = p_bias / 500;
  q_bias = q_bias / 500;
  r_bias = r_bias / 500;
}



// Estimador dos angulos de euler e das velocidades angulares
void AttitudeEstimator::estimate() {
  imu.read();
  

  float phi_a = atan2((-imu.ay), (-imu.az));
  float deno = -((imu.az>0) - (imu.az<0))*sqrt(pow(imu.ay,2) + pow(imu.az,2));
  float theta_a = atan2((imu.ax), (deno));

  p = imu.gx - p_bias;
  q = imu.gy - q_bias;
  r = imu.gz - r_bias;
  float phi_g = phi + (p + sin(phi)*tan(theta)*q + cos(phi)*tan(theta)*r)*dt;
  float theta_g = theta + (cos(phi)*q - sin(phi)*r)*dt;
  float psi_g = psi + (sin(phi)*(1/cos(theta))*q + cos(phi)*(1/cos(theta))*r)*dt;

  phi = (1.0 - alpha) * phi_g + phi_a * alpha;
  theta = (1.0 - alpha) * theta_g + theta_a * alpha; // complementar
  psi = psi_g;
}