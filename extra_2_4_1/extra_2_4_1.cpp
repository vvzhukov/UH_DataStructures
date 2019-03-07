#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

//EXTRA_2_4_1 -> write 1 shell sort for
//create 100 array (random)
//create 500 array (random)
//create 1000 array (random)
// Print time for each
// geeks for geeks was partly used for this task
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
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
    clock_t start;
    start = clock();
    shellSort(array, n);
    // your test
    std::cout << "Time shell, "<<n<<" entries: " << (std::clock() - start) / (double)
    (CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
}

int main() {
    benchmark(100);
    benchmark(500);
    benchmark(1000);
    return 0;
}