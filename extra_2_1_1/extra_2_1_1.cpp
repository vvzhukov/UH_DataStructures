#include <iostream>
#include <ctime>
#include <sys/time.h>
using namespace std;

// EXTRA_2_1_1 Different algoritms with benchmarking on different sizes arrays
// geeks for geeks was partly used for this task


// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++)
    {
        swapped = false;
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        
        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        
        /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
};

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            //cout<<arr[j]<<" "<<arr[min_idx];
        if (arr[j] < arr[min_idx])
            min_idx = j;
        
        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
};

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays */
    int L[n1], R[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
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
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
};

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
};

/* This function takes last element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
};

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
 low  --> Starting index,
 high  --> Ending index */

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(arr, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
};


int* generate_array(int size){
    int *a = NULL;
    a = new int[size];
    for (int i=0; i<size; i++){
        a[i] = rand() % 100;
    }
    return a;
};

void benchmark(int n=0){
    int* array = generate_array(n);
    
    clock_t    start;
    start = clock();
    bubbleSort(array, n);
    // your test
    std::cout << "Time bubble, "<<n<<" entries: " << (std::clock() - start) / (double)
    (CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
    
    clock_t    start2;
    start2 = clock();
    insertionSort(array, n);
    // your test
    std::cout << "Time insert, "<<n<<" entries: " << (std::clock() - start2) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
    
    clock_t    start3;
    start3 = clock();
    selectionSort(array, n);
    // your test
    std::cout << "Time select, "<<n<<" entries: " << (std::clock() - start3) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
    
    clock_t    start4;
    start4 = clock();
    mergeSort(array,0, n-1);
    // your test
    std::cout << "Time merge, "<<n<<" entries: " << (std::clock() - start4) / (double)
    (CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
    
    clock_t    start5;
    start5 = clock();
    quickSort(array,0, n-1);
    // your test
    std::cout << "Time quick, "<<n<<" entries: " << (std::clock() - start5) / (double)
    (CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
}

int main() {
    //cout<<*generate_array(3)<<endl;
    //return 0;
    benchmark(500);
    benchmark(10000);
    benchmark(50000);
    benchmark(500000);
    return 0;
    /*
     int arr[] = {64, 34, 25, 12, 22, 11, 90};
     int n = sizeof(arr)/sizeof(arr[0]);
     bubbleSort(arr, n); //swap used
     insertionSort(arr, n);
     selectionSort(arr, n); //swap used
     mergeSort(arr, 0, n-1);
     quickSort(arr, 0, n-1);
     */
}


