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

    omp_set_num_threads(4);

    #pragma omp parallel private(n_thread)
    {
	n_thread = omp_get_thread_num();

	#pragma omp sections nowait
	{
		#pragma omp section
		{
			printf("Hebra %d Ejecutando tarea 1\n", n_thread);
			tarea_uno();
		}

		#pragma omp section
		{
			printf("Hebra %d Ejecutando tarea 2\n", n_thread);
			tarea_dos();
		}
	}
	 printf("Hebra %d, salio del sections en el instante = %f\n", n_thread, omp_get_wtime() - timeIni);
    }

    timeFin = omp_get_wtime();
 
    cout<<"Tiempo tardado = "<< timeFin - timeIni <<" segundos"<<endl;

}
