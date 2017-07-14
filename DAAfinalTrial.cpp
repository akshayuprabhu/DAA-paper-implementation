#include <iostream>
#include <cmath>
#include <cstdio>
#include <omp.h>
#include<ctime>
// #include <climits>
// #define ll long long
using namespace std;

int a[10000006],n,i;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0;
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void coordinate_recorded_mergeSort(int a[],int low,int high){

	int gap;

	int	n=ceil(log2f(high-low+1));

	for(int count=1;count<=n;count++){
		cout << pow(2,count) << endl; 
		gap=pow(2,count);

		// int i=0;
		#pragma omp parallel for
		for(i=0;i<high;i+=gap){
			merge(a, i, (i+gap/2-1) , (i+gap-1) );
			// cout << " the value of i is "  << i << endl;
			// i+=gap;
		}
	}

}

int main(){
	int i;

	n=10000000; //increased the value of n
	int range=100000;
	srand(time(NULL));
	for( i=0;i<n;i++)
		a[i]=rand()%range;

#pragma omp parallel	
	#pragma omp single
	coordinate_recorded_mergeSort(a,0,lim-1);

	
	return 0;
}
