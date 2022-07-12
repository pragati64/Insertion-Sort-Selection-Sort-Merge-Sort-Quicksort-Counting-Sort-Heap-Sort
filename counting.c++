#include <iostream>
using namespace std;

void count(int arr[], int size)
{
  int output[10];
  int count[10];
  int max = arr[0];

  for (int i = 1; i < size; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }

  for (int i = 0; i <= max; i++)
  {
    count[i] = 0;
  }

  for (int i = 0; i < size; i++)
  {
    count[arr[i]]++;
  }

  for (int i = 1; i <= max; i++)
  {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--)
  {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  for (int i = 0; i < size; i++)
  {
    arr[i] = output[i];
  }
}

void print(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
  int arr[] = {1, 7, 4, 8, 9, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  count(arr, n);
  cout<<("Sorted array in Ascending Order: ");
  print(arr, n);
}
