#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*mplemente uma função que calcule a área da superfície e o volume de uma esfera
 de raio R. Essa função deve obedecer ao protótipo:
void calc_esfera(float R, float *area, float *volume)
A área da superfície e o volume são dados, respectivamente, por: A=4R2 e V=43R3
*/

void calc_esfera(float R, float *area, float *volume){
  float A, B, expA,expV, V, r, pi;
  pi = 3.14;


  expA = pow(R,2);
  A = 4*pi*expA;
  area = &A;
  printf("Area = %.2f",*area);
  expV = pow(R,3);
  V = (4*pi*expV)/3;
  volume = &V;
  printf("\nVolume = %.2f",*volume);

}

int main(){
  float r, *A, *V;
    printf("informe um valor de R: ");
    scanf("%f",&r);
    calc_esfera(r,A,V);//chamando a função

    return EXIT_SUCCESS;

}
