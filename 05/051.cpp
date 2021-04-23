#include <omp.h>
#include <iostream>
#include <vector>
using namespace std;
 
int main (){
    unsigned int N;
    cout<<"introduce el tamaño del vector"<<endl;
    cin>>N;
    double timeIni, timeFin;
    vector<int> x(N), y(N);
 
    timeIni = omp_get_wtime();
    //Secuencial
    for(int i=1; i < N ; i++){
    	x[i] = y[i-1] * 2;
    	y[i] = y[i] + i;
    }
 
    timeFin = omp_get_wtime();
    cout<<"Tiempo tardado secuencial = "<< (timeFin - timeIni)*1000 <<"milisegundos"<<endl;
    timeIni = omp_get_wtime();
    //Paralelo
 
    #pragma omp parallel if( N > 10000 )
    {
    	#pragma omp single
  	cout<<"Numero de hebras = "<<omp_get_num_threads()<<endl;
 
  	#pragma omp for
  	for(int i=0; i < N ; i++){
      		y[i] = y[i] + i;
      		x[i+1] = y[i] * 2;
  	}
    } 
    timeFin = omp_get_wtime();
    cout<<"Tiempo tardado paralelo = "<< (timeFin - timeIni)*1000 <<" milisegundos"<<endl;
}
