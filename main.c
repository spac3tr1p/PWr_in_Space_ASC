#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "pid.h"


int main(void)
{
  PIDType pid = {THETA_TARGET - THETA_START, THETA_START, 0.0f, 0.0f, 0.0f, 0.0f};

  FILE *f = fopen("data.csv", "w");
  fprintf(f, "t,theta,u\n");

  for(uint32_t i = 0; i < STEPS; i++)
  {  
    PID_Iteration(&pid);
    printf("%d ms | %.4f theta | %.4f u\n", i, pid.theta, pid.u);
    fprintf(f, "%d,%.4f,%.4f\n", i, pid.theta, pid.u);
    PID_ThetaOmegaUpdate(&pid);
  }

  fclose(f);
  return 0;
}