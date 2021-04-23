#include <omp.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;
 
 
void tarea_uno(){
    sleep(2);
}
 
void tarea_dos(){
    sleep(4);
}
 
int main (){
 
    double timeIni, timeFin;
 
    timeIni = omp_get_wtime();
 
    cout<<"Ejecutando tarea 1"<<endl;
    tarea_uno();
 
    cout<<"Ejecutando tarea 2"<<endl;
    tarea_dos();
 
 
    timeFin = omp_get_wtime();
 
    cout<<"Tiempo tardado = "<< timeFin - timeIni <<" segundos"<<endl;
 
}
