#include <iostream>
#include<conio.h>
using namespace std;
int main()
{
    int i,j,n,temp,min;
    cout<<"Enter the number of elements:";
    cin>>n;
    int a[n];
    cout<<"\nEnter the elements\n";

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=0;i<n-1;i++)
    {
        min= i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                min=a[j];

            }
        }

        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }

    cout<<"\nSorted list is \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
