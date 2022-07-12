#include <iostream>
#include <conio.h>
using namespace std;

void swap(int a[] , int x, int z){
	int temp;
	temp = a[x];
	a[x] = a[z];
	a[z] = temp;
}

int sort(int a[], int l, int h, int w){
	int i = l;
	int j = l;
	while( i <= h){
		if(a[i] > w){
			i++;
		}
		else{
			swap(a,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

void quickSort(int a[], int l, int h){
	if(l < h){
	int w = a[h];
	int var= sort(a, l, h, w);

	quickSort(a, l, var-1);
	quickSort(a, var+1, h);
	}
}

int main()
{
	int n ;
	cout << " enter the size of array";
	cin>>n;
	int a[n];
	for( int i = 0 ; i < n; i++){
		cin>> a[i];
	}
	quickSort(a, 0 , n-1);
	cout<<"The sorted array is: ";
	for( int i = 0 ; i < n; i++){
		cout<< a[i]<<"\t";
	}

}
