#include <stdio.h>
#include <stdint.h>
#include "pid.h"


int main(void)
{
  PIDType pid = {
    .prev_error = THETA_TARGET - THETA_START, 
    .theta = THETA_START, 
    .omega = 0.0f,  
    .I = 0.0f, 
    .D = 0.0f, 
    .u = 0.0f
  };

  FILE *f = fopen("data.csv", "w");
  fprintf(f, "t,theta,u\n");

  for(uint32_t i = 0; i < STEPS; i++)
  {  
    PID_Iteration(&pid);
    fprintf(f, "%u,%.4f,%.4f\n", i, pid.theta, pid.u);
    PID_ThetaOmegaUpdate(&pid);
  }

  fclose(f);
  return 0;
}