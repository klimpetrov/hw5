#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

  void eulerfor(const int N, const double dt, double* ef);
  void eulerback(const int N, const double dt, double* eb);





int main(){
  const double pi=M_PI;
  double dt=3.14/10;
  const int N= 20*10;
  double ef[N*2];
  double eb[N*2];
  ef[0] = 1; // x(0) = 1
  ef[N] = 0; // x'(0) = 0
  eb[0] = 1;
  eb[N] = 0;
  
  
  eulerfor(N, dt, ef);
  eulerback(N, dt, eb);
  
  
  ofstream out("eb.txt");
 for(int i=0; i<N; i++){
   out << i*dt << "\t" << eb[i] << "\t" << eb[N+i] << endl;
   
}
   out.close();
   
  ofstream zeugs("ef.txt");
 for(int i=0; i<N; i++){
 zeugs << i*dt << "\t" << ef[i] << "\t" << ef[N+i] << endl;
 }
 
  zeugs.close();

 

return 0;
}
  
  

  
 void eulerfor(const int N, const double dt, double* ef){
   for(int i=0; i<N-1; i++){
     ef[i+1] = ef[i] + dt*ef[i+N]; // x() füllen
     ef[N+i+1] = ef[N+i]-dt*ef[i]; // x'() füllen
     
   }
 }
 void eulerback(const int N, const double dt, double* eb){
   for(int i=0; i<N-1; i++){
     eb[i+1] = (eb[i] + dt*eb[i+N])/(1+dt*dt); // x() füllen
     eb[N+i+1] = (eb[N+i]-dt*eb[i])/(1+dt*dt); // x'() füllen
   }
 }
  
   