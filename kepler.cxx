#include <cmath>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

//unterfunktionen
void symplectic(double* V0, double* V1, const double dt);


//Hauptfunktionen
int main(){
const double dt = 0.0005;
const double tend = 20*M_PI;
const int N = tend/dt;
double t = 0;
const double e = 0.5;
//Vektoren
double V0[4];//q1,q2,p1,p2
double V1[4];
//Randbedingungen
V0[0] = 1-e;
V0[1] = 0;
V0[2] = 0;
V0[3] = sqrt((1+e)/(1-e));

double H = 0.5 * (V0[2]*V0[2]+V0[3]*V0[3]) - 1/sqrt(V0[0]*V0[0]+V0[1]*V0[1]);

cout << t << "\t" << V0[0] << "\t" << V0[1] << "\t" << H <<endl;  

for(int n = 1; n < N; n++){
  
  symplectic(V0,V1,dt);
  //switchen
  for(int i = 0; i < 4; i++)
    V0[i] = V1[i];
  
  t += dt;
  double H = 0.5 * (V0[2]*V0[2]+V0[3]*V0[3]) - 1/sqrt(V0[0]*V0[0]+V0[1]*V0[1]);
  cout << t << "\t" << V0[0] << "\t" << V0[1] << "\t" << H <<endl; 
}
  return 0;
}


void symplectic(double* V0, double* V1, const double dt){
  
  //p-Werte
  V1[2] = V0[2] - dt*V0[0]/(pow(V0[0]*V0[0]+V0[1]*V0[1],1.5));
  V1[3] = V0[3] - dt*V0[1]/(pow(V0[0]*V0[0]+V0[1]*V0[1],1.5));
  //q-Werte
  V1[0] = V0[0] + dt*V1[2];
  V1[1] = V0[1] + dt*V1[3];
  
}