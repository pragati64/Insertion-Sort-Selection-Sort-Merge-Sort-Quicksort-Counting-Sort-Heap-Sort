#include <iostream>
#include <conio.h>
using namespace std;
void insertion(int a[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
     while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}
void print(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	int a[] = { 11, 33, 3, 12, 23 };
	int N = sizeof(a) / sizeof(a[0]);
     cout<<"The Insertion sort is: "<<" ";
	insertion(a, N);
	print(a, N);

	return 0;
}
