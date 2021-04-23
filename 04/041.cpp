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
    int n_thread;
 
    timeIni = omp_get_wtime();
    omp_set_num_threads(2);

    #pragma omp parallel private(n_thread)
    {
	n_thread = omp_get_thread_num();

	#pragma omp sections
	{
		#pragma omp section
		{
			printf("Hebra %d Ejecutando tarea 1", n_thread);
			tarea_uno();
		}

		#pragma omp section
		{
			printf("Hebra %d Ejecutando tarea 2", n_thread);
			tarea_dos();
		}
	}
    }

    timeFin = omp_get_wtime();
 
    cout<<"Tiempo tardado = "<< timeFin - timeIni <<" segundos"<<endl;

}
