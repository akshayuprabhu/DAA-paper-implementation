// DAAtrial.cpp

#include <iostream>
#include <cstdio>
#include <omp.h> 

using namespace std;

int main(){

	// #pragma omp for
	// for (int i = 0; i < 10; ++i)
	// {
	// 	cout << i << " " ;
	// }

#pragma omp parallel for
 for(int n=0; n<10; ++n)
 {
   printf(" %d", n);
 }
 printf(".\n");
 printf ( "\n" );
  printf ( "  Number of processors available = %d\n", omp_get_num_procs ( ) );
  printf ( "  Number of threads =              %d\n", omp_get_max_threads ( ) );

return 0;	
}
