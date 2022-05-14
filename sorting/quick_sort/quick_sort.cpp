/*
    Quick Sort Algorithm 
    Time Complexity : Average case -> O(n * log(n))
                      Worst case   -> O(n * n)

    Space Complexity : O(1); Since no extra array or list is required like Merge Sort.
*/
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int i, j;
    int pivot = arr[high];

    for(i = low-1, j = low ; j < high; j++){
        if(arr[j] < pivot){
            i += 1; // moving the left pointer to right
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);

    return i+1; // returning the index of the pivot by positioning it in it's correct position.
}

void quick_sort(int arr[], int low, int high)
{
    if(low >= high) return;

    int p = partition(arr, low, high);

    quick_sort(arr, low, p-1);

    quick_sort(arr, p+1, high);
}


// A function for priting values of the array.

void print_arr(int arr[], int n)
{
    for(int i = 0; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int arr[] = {1, 5, 6, 3, 5, 8, 7, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before sorting : ";
    print_arr(arr, n);

    quick_sort(arr, 0, n-1);

    cout<<"After sorting : ";
    print_arr(arr, n);

    return 0;
}