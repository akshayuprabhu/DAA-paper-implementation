#include <iostream>
#include <omp.h>
using namespace std;

void OddEvenSort (int a[], int n)
{
    for (int i = 0 ; i < n ; i++)
    {
         if (i & 1) // 'i' is odd
         {

         	#pragma omp parallel for
             for (int j = 2 ; j < n ; j += 2)
             {     
                  if (a[j] < a[j-1])
                      swap (a[j-1], a[j]) ;
             }
          }
          else
          {  
              #pragma omp parallel for
              for (int j = 1 ; j < n ; j += 2)
              {
                   if (a[j] < a[j-1])
                       swap (a[j-1], a[j]) ;
              } 
          }
    }
}

int main(){
	int n;
	cin >> n ;

	int a[n];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	OddEvenSort(a,n);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " " ;
	}

return 0;	
}


