/*
    Bubble sort implementation using simple modification so that time complexity is O(N) when the given array is already sorted.
    
    Time complexity: 
        best case : O(N) ; when the given array is already sorted.
        worst case : O(N^2) ; when the given array is not sorted.

    Space complexity: O(1), since array size is not considered for the algorithm
*/

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    bool swapped;
    // run the steps n-1 times

    for(int i = 0; i < n; i++){
        swapped = false;
        // for each step, max item will come at the last respective index
        for(int j = 1; j < n-i; j++){
            if(arr[j] < arr[j-1]){
                swap(arr[j], arr[j-1]);
                swapped = true;
            }
        }
        // if swapped variable is false that means the array is already sorted
        // no need to perform the algorithm
        if(!swapped) break;
    }
}

void print_list(int arr[], int n)
{
    // a function for printing the elements presented in the array
    for(int i = 0 ; i < n ; i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
}

int main()
{
    int arr[] = {9, 0, 10, 99, -1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before performing bubble sort: ";
    print_list(arr, n);
    cout<<endl;
    
    bubble_sort(arr, n);

    cout<<"After performing bubble sort: ";
    print_list(arr, n);

    return 0;

}