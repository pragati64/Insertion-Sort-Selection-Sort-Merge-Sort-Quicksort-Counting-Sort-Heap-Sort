# Insertion-Sort-Selection-Sort-Merge-Sort-Quicksort-Counting-Sort-Heap-Sort by c++

void insertionSort(int arr[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1;
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
} 

#selection short

#include <iostream>
#include <string>
using namespace std;

template<typename T, size_t n>
void print_array(T const(&arr)[n]) {
    for (size_t i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    cout << "\n";
}

int minIndex(int a[], int i, int j) {
    if (i == j)
        return i;
    int k = minIndex(a, i + 1, j);
    return (a[i] < a[k]) ? i : k;
}

void recurSelectionSort(int a[], int n, int index = 0) {
    if (index == n)
        return;
    int k = minIndex(a, index, n - 1);
    if (k != index)
        swap(a[k], a[index]);
    recurSelectionSort(a, n, index + 1);
}

void iterSelectionSort(int a[], int n) {
    for (int i = 0; i < n; i++)
    {
        int min_index = i;
        int min_element = a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < min_element)
            {
                min_element = a[j];
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
}

int main() {
    int recurArr[6] = { 100,35, 500, 9, 67, 20 };
    int iterArr[5] = { 25, 0, 500, 56, 98 };

    cout << "Recursive Selection Sort"  << "\n";
    print_array(recurArr); // 100 35 500 9 67 20
    recurSelectionSort(recurArr, 6);
    print_array(recurArr); // 9 20 35 67 100 500

    cout << "Iterative Selection Sort" << "\n";
    print_array(iterArr); // 25 0 500 56 98
    iterSelectionSort(iterArr, 5);
    print_array(iterArr); // 0 25 56 98 500
}

#merge short

void mergesort(int A[],int size_a,int B[],int size_b,int C[])
{
     int token_a,token_b,token_c;
     for(token_a=0, token_b=0, token_c=0; token_a<size_a && token_b<size_b; )
     {
          if(A[token_a]<=B[token_b])
               C[token_c++]=A[token_a++];
          else
               C[token_c++]=B[token_b++];
      }
      
      if(token_a<size_a)
      {
          while(token_a<size_a)
               C[token_c++]=A[token_a++];
      }
      else
      {
          while(token_b<size_b)
               C[token_c++]=B[token_b++];
      }

}

#quickshort

#include<stdio.h>  
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];     
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    {
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
  

int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printf("Sorted array: n"); 
    printArray(arr, n); 
    return 0; 
} 
#counting short

#include <iostream>

#include <vector>

void countSort(int upperBound, int lowerBound, std::vector < int > numbersToSort) // Lower and upper bounds of numbers in vector
{
  int i;
  int range = upperBound - lowerBound; // Create a range large enough to get every number between the min and max
  std::vector < int > counts(range + 1); // Initialize of counts of the size of the range
  std::fill(counts.begin(), counts.end(), 0); // Fill vector of zeros
  std::vector < int > storedNumbers(numbersToSort.size()); // Initialize of storedNumbers of the same size as the input vector
  std::fill(storedNumbers.begin(), storedNumbers.end(), 0); // Fill storedNumbers vector of zeros

  for (i = 0; i < numbersToSort.size(); i++) {
    int index = numbersToSort[i] - lowerBound; // For example, if 5 is the lower bound and numbersToSort[i] is 5, the index will be 0 and the
    counts[index] += 1; // count of 5 will be stored in counts[0]
  }

  for (i = 1; i < counts.size(); i++) {
    counts[i] += counts[i - 1];
  }

  for (i = numbersToSort.size() - 1; i >= 0; i--) { // Copy elements from numbersToSort to storedNumbers according to the count
    storedNumbers[--counts[numbersToSort[i] - lowerBound]] = numbersToSort[i];
  }

  for (i = 0; i < storedNumbers.size(); i++) {
    std::cout << storedNumbers[i];
    if (i != storedNumbers.size() - 1)
      std::cout << ", ";
  }
  std::cout << std::endl;
}

#heapshort 

#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1;  
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) 
        largest = l;
    if (r < n && arr[r] > arr[largest]) 
        largest = r;
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        
        heapify(arr, n, largest); 
    } 
} 
  
 
void heapSort(int arr[], int n) 
{ 
    
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    
    for (int i=n-1; i>=0; i--) 
    { 

        swap(arr[0], arr[i]); 
  
        
        heapify(arr, i, 0); 
    } 
} 
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
}
