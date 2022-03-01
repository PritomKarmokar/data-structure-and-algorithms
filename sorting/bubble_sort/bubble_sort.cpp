/*
    Bubble Sort Implementation
    Time complexity: O(N ^ 2)
    Space complexity: O(1), since array size is not considered for the algorithm
*/

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    //run the steps n-1 times

    for(int i = 0; i < n; i++){
        // for each step, max item will come at the last respective index
        for(int j = 1; j < n-i; j++){
            if(arr[j] < arr[j-1])
                swap(arr[j], arr[j-1]);
        }
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