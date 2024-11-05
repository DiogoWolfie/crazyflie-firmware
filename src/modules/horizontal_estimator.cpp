#include "horizontal_estimator.h"

HorizontalEstimator::HorizontalEstimator() : flow(PA_7, PA_6, PA_5, PB_4)
{
    x=0.0;
    y=0.0;
    u=0.0;
    v=0.0;
}

void HorizontalEstimator::init(){
    flow.init(); //inicia o sensor
}

void HorizontalEstimator::predict(float phi, float theta){

    x = x + u*dt;
    y = y + v*dt;
    u = u + g*theta*dt;
    v = v - g*phi*dt;
}

void HorizontalEstimator::correct(float phi, float theta, float p, float q, float z){

    float den = cos(phi)*cos(theta);
    if(den>0.5){
        float d = z/den;
        flow.read();
        float u_m = (delta*flow.px + q)*d;
        float v_m = (delta*flow.py - p)*d;
        u = u + wh*dt*(u_m-u);
        v = v + wh*dt*(v_m-v);
    }
}

