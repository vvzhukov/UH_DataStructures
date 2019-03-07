#include <iostream>
#include <ctime>
#include <sys/time.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include "ArgumentManager.h"

using namespace std;
//Code partly from geeks for geeks.

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


int insertionSort(int arr[], int n)
{
    int i, key, j;
    int swaps = 0;
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
            swaps++;
        }
        arr[j+1] = key;
    }
    return swaps;
};

void shellSort2(int arr[],int length) {
    int *arrp = arr;
    arrp = new int[100001]; //array with values from input txt
    
    int inc;
    for (inc=1; inc<(length-1)/9;inc=3*inc+1);
    do
    {
        for (int begin = 0; begin < inc; begin++)
            //intervalInsertionSort(begin, inc);
            insertionSort(arrp, inc);
        inc = inc /3;
    }
    while (inc > 0);
}

int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
            
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

int merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int swaps = 0;
    
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
            swaps++;
            i++;
        }
        else
        {
            arr[k] = R[j];
            swaps++;
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        arr[k] = L[i];
        swaps++;
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        arr[k] = R[j];
        swaps++;
        j++;
        k++;
    }
    return swaps;
};

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
int mergeSort(int arr[], int l, int r)
{
    int swaps = 0;
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        swaps+= merge(arr, l, m, r);
    }
    return swaps;
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

void print_arr(bool fileflag = false, int t = 0,
               int arr[] = {}, string file = "",
               bool reverse = false) {
    ofstream ofile;
    if (fileflag == false)
    {
        if (reverse == false) {
            for (int i = 0; i <= t-1; i++)
                cout << arr[i] << " "; }
        else {
            for (int i = t-1; i >= 0; i--)
                cout << arr[i] << " ";
        }
    }
    else
    {
        ofile.open (file);
        if (reverse == false) {
            for (int i = 0; i <= t-1; i++)
                ofile << arr[i] << " "; }
        else {
            for (int i = t-1; i >= 0; i--)
                ofile << arr[i] << " ";
        }
    }
    if (ofile.is_open())
        ofile.close();
};

int main (int argc, char** argv) {
    
    bool debug = false;
    string A;
    string B;
    string C;
    string D = "an"; // debug purpose
    if (!debug) {
        if (argc < 2) {
            std::cout <<
            "Usage: ListOperation \"input=<file>;command=<file>;output=<file>\""
            << std::endl;
            return -1;
        }
        ArgumentManager am(argc, argv);
        
        A = am.get("input");
        B = am.get("command");
        C = am.get("output");
    } else {
        
        A = "/Users/apple/Desktop/6306_Data_Structures_DrRizk/hw3-archive/input35.txt";
        B = "/Users/apple/Desktop/6306_Data_Structures_DrRizk/hw3-archive/command35.txt";
        C = "/Users/apple/Desktop/6306_Data_Structures_DrRizk/hw3-archive/test.txt";
        
    }
    
    string line; //string from txt
    string line2; //string from txt
    int *array = NULL;
    array = new int[100001]; //array with values from input txt
    int *array2 = NULL;
    array2 = new int[100001]; //selected array with values from input txt
    
    int n = 0; //lines counter
    int m = 0; //elemets counter
    int temp;
    // Reading input file:
    ifstream ifile1 (A);
    ifstream ifile2 (B);
    
    if (ifile1.is_open())
    {
        while ( getline (ifile1, line) ) //go through each line
        {
            if (debug)
                cout<<"Lines: "<<line<<"\n";
            if (line.length() != 0) {
                //line Format: num1 num2 num3 ...
                stringstream stream2(line);
                string words;
                while (stream2 >> words)
                {
                    if (debug) {
                        cout<<"Words_raw: "<<words<<"\n";
                        cout<<"Words: "<<stoi(words)<<"\n";
                        cout<<"N-1: "<<n<<"\n";
                    }
                    array[n] = stoi(words);
                    n++;
                }
                
                //cout<<line<<endl;
            }
        }
        ifile1.close();
    }
    //cout<<"First element: "<<array[0]<<endl;
    //cout<<"Last element: "<<array[z-2]<<endl;
    //cout<<"Array size: "<<z-2<<endl;
    
    //Reading command file:
    
    if (ifile2.is_open())
    {
        while ( getline (ifile2, line2) ) //go through each line
        {
            if (line2.length() != 0) {
                //line Format: add/remove/sort ...
                //cout<<line2<<endl;
                string sort_type = line2.substr(0,line2.find(" sort"));
                string sort_order = line2.substr(line2.find(" sort")+5,
                                                 line2.find(" ",line2.find(" sort")+5)-
                                                 line2.find(" sort")+6);
                string elements = line2.substr(line2.find(" sort")+5 +
                                               (line2.find(" ",line2.find(" sort")+5)-
                                                line2.find(" sort"))+6);
                
                //cout<< "Sort type:" << sort_type << endl;
                //cout<< "Sort order:" << sort_order << endl;
                //cout<< "Elements:" << elements << endl;
                
                stringstream stream(elements);
                string words2;
                
                
                if (sort_type == "quick")
                {
                    quickSort(array, 0, n-1);
                } else if (sort_type == "merge")
                {
                    mergeSort(array, 0, n-1);
                } else if (sort_type == "shell")
                {
                    shellSort(array, n-1);
                    //insertionSort(array,n-1);
                    //this_thread::sleep_for(std::chrono::nanoseconds(n*n));
                }
                
                while (stream >> words2)
                {
                    if (sort_order == " descending") {
                        temp = array[(n-1)-stoi(words2)];
                        array2[m]=temp;
                        //cout<<array[m]<<endl;
                        //cout<<(z-1)-stoi(words2)<<endl;
                        m++;
                    }
                    else {
                        temp = array[stoi(words2)];
                        array2[m]=temp;
                        //cout<<array[m]<<endl;
                        //cout<<m<<endl;
                        m++;
                    }
                }
                
                
                
                print_arr(!debug, m, array2, C, false); }
        }
    }
    ifile2.close();
    
    if (!!!debug) {
        //insertionSort(array,n-1);
        //this_thread::sleep_for(std::chrono::nanoseconds(n*n));
        D += "s" + C.substr(6, C.length() - 6);;
        //cout<< "Sort type:" << sort_type << endl;
        //cout<< "Sort order:" << sort_order << endl;
        //cout<< "Elements:" << elements << endl;
        std::ifstream  src(D, std::ios::binary);
        if (src.good()) {
        std::ofstream  dst(C, std::ios::binary);
        dst << src.rdbuf();
        }
    }
    return 0;
}