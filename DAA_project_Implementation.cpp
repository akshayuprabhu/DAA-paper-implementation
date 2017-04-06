#include <iostream>
#include <cmath>
#include <cstdio>
#include <omp.h>
#define ll long long
using namespace std;

long long a[1000000000],n,i;

void merge(ll arr[], ll l, ll m, ll r)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 =  r - m;

    ll L[n1], R[n2];
 
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

void coordinate_recorded_mergeSort(ll a[],ll low,ll high){

	ll gap;

	ll	n=ceil(log2f(high-low+1));

	for(ll count=1;count<=n;count++){
		cout << pow(2,count) << endl; 
		gap=pow(2,count);

		// int i=0;
		#pragma omp parallel for
		for(i=0;i<high;i+=gap){
			merge(a, i, (i+gap/2-1) , (i+gap-1) );
			cout << " the value of i is "  << i << endl;
			// i+=gap;
		}
	}

}

int main(){

	cout << "enter the number of elements in the array " << endl;
	cin >> n;
	cout << "enter the elements" << endl;
	for(i=0;i<n;i++){
		cin >> a[i] ;
	}

	ll	num=ceil(log2f(n));
	ll lim=pow(2,num);

	for (i = n; i <= lim; ++i){
		a[i]=9999;
	}

	coordinate_recorded_mergeSort(a,0,lim-1);

  printf ( "  Number of processors available = %d\n", omp_get_num_procs ( ) );
  printf ( "  Number of threads =              %d\n", omp_get_max_threads ( ) );

	for (ll i = 0; i < n; ++i){
		cout << a[i] << " " ;
	}
	cout << endl;

return 0;
}
