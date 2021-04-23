#include <omp.h>
#include <iostream>
 
int main (){
 
int nthreads;
int thread;
 
omp_set_num_threads(10); 

#pragma omp parallel private(nthreads, thread)
  {
  thread = omp_get_thread_num();
 
  nthreads = omp_get_num_threads();
 
  printf("Hola Mundo soy la hebra %d de %d que somos\n", thread, nthreads);
 
  }
 
}
