#include <omp.h>
#include <iostream>
 
#define N 100
#define nthreads 4
 
int main (){
	int pepe = 100;	
	int thread;
	omp_set_num_threads(nthreads);
	      
	#pragma omp parallel private(thread)
       	{
		thread = omp_get_thread_num();
			     
		#pragma omp for
		for (int i = 0 ; i < N; i++){
			printf("Soy el proceso %d ejecuto al iteracion %i y pepe es %d\n", thread, i, pepe);
		}
       	}
}
