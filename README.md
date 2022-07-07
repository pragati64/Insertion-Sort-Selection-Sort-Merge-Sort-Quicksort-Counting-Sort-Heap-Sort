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
            
            
#by python
   
#insertin short
            
            def insertion_sort(array):
for i in range(len(array)):
        for j in range(0,i+1):
            if array[i] < array[j]:
                array[i],array[j] = array[j] ,array[i]
    for val in array:
        print(val,end = " ")
print("Enter elements into the array")
array = [int(n) for n in input().split()]
insertion_sort(array)
   
   #selection short
   
   def selection_sort(array):
    sorted_array = []
    #Initializing the second array with spaces in it
    for i in range(len(array)):
        sorted_array.append(" ")
    for i in range(len(array)):
        #Take minimum element in the array
        ele = min(array)
        #taking the index of the minimum element
        index = array.index(min(array))
        #Removing the minimum element in the array
        del array[index]
        #Adding the minimum element to second array
        sorted_array[i] = ele
        print("Elements After Sorting")
        for val in sorted_array:
            print(val,end = " ")
print("Enter elements into array")
array = [int(n) for n in input().split()]
selection_sort(array)
   
   #quickshort
   
   def quick_sort(arr,first_index,last_index):
    if first_index < last_index:
                                
  #heapshort
                                
                       
 def heapify(nums, heap_size, root_index):
    
    largest = root_index
    left_child = (2 * root_index) + 1
    right_child = (2 * root_index) + 2

   
    if left_child < heap_size and nums[left_child] > nums[largest]:
        largest = left_child

  
    if right_child < heap_size and nums[right_child] > nums[largest]:
        largest = right_child

    
    if largest != root_index:
        nums[root_index], nums[largest] = nums[largest], nums[root_index]
        # Heapify the new root element to ensure it's the largest
        heapify(nums, heap_size, largest)


def heap_sort(nums):
    n = len(nums)

    
    for i in range(n, -1, -1):
        heapify(nums, n, i)

    # Move the root of the max heap to the end of
    for i in range(n - 1, 0, -1):
        nums[i], nums[0] = nums[0], nums[i]
        heapify(nums, i, 0)



random_list_of_nums = [35, 12, 43, 8, 51]
heap_sort(random_list_of_nums)
print(random_list_of_nums)                 
        
         pivot = first_index
         i = first_index + 1
         j = last_index
         while i < j:
           #Incrementing i till element is greater than element at pivot
           while arr[i] < arr[pivot] and i < last_index:
                 i+=1
        
           #Decrementing j till element is less than element at pivot
           while arr[j] > arr[pivot]:
                 j-=1
           if i < j:
                 arr[i], arr[j] = arr[j],arr[i]
         arr[pivot], arr[j] = arr[j],arr[pivot]
         
         #Sorting Elements Before Swaping the pivot elements
         quick_sort(arr,first_index,j-1)
         quick_sort(arr,j+1,last_index)
print("Enter size of array")
N = int(input())
print("Enter Elements into the array")
arr = [int(n) for n in input().split()]
quick_sort(arr,0,N-1)
print("Elements After Sorting")
for i in range(N):
    print(arr[i],end=" ")
                    
  #mergeshort
 
 def mergeSort(array, low, mid, high): 
    n1 = mid - low + 1
    n2 = high - mid 
  
    # create temp arrays 
    arr1 = [0] * (n1) 
    arr2 = [0] * (n2) 
  
    # Copy data to temp arrays arr1[] and arr2[] 
    for i in range(0 , n1): 
        arr1[i] = array[low + i] 
  
    for j in range(0 , n2): 
        arr2[j] = array[mid + 1 + j] 
  
    # Merge the temp arrays back into arr[l..r] 
    i = 0     # Initial index of first subarray 
    j = 0     # Initial index of second subarray 
    k = low   # Initial index of merged subarray 
  
    while i < n1 and j < n2 : 
        if arr1[i] <= arr2[j]: 
            array[k] = arr1[i] 
            i += 1
        else: 
            array[k] = arr2[j] 
            j += 1
        k += 1
  
    # Copy the remaining elements of arr1[], if there are any 
    while i < n1: 
        array[k] = arr1[i] 
        i += 1
        k += 1
  
    # Copy the remaining elements of arr2[], if there are any 
    while j < n2: 
        array[k] = arr2[j] 
        j += 1
        k += 1
def partition(array,low,high): 
    if low < high: 
  
       #Same as (low+high)//2, but avoids overflow for large low and high 
       mid = (low+(high-1))//2
  
        # Sort first and second halves 
        partition(array, low, mid) 
        partition(array, mid+1, high) 
        mergeSort(array, low, mid, high) 
  
  
print("Enter Elements into array")
array = [int(n) for n input().split()] 
n = len(array) 
  
partition(array,0,n-1) 
print ("\n\nSorted array is") 
for i in range(n): 
    print ("%d" %array[i])
                  
     #counting short
    
  def countingSort(arr):
    size = len(arr)
    output = [0] * size

    # count array initialization
    count = [0] * 10

    # storing the count of each element 
    for m in range(0, size):
        count[arr[m]] += 1

    # storing the cumulative count
    for m in range(1, 10):
        count[m] += count[m - 1]

    # place the elements in output array after finding the index of each element of original array in count array
    m = size - 1
    while m >= 0:
        output[count[arr[m]] - 1] = arr[m]
        count[arr[m]] -= 1
        m -= 1

    for m in range(0, size):
        arr[m] = output[m]

data = [3,5,1,6,7,8,3]
countingSort(data)
print("Sorted Array: ")
print(data)
  
