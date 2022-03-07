/*
    Selection Sort Algorithm
    Time Complexity: O(n^2)
    Space Complexity: O(1) , because array is not the part of algorithm, it's just the part of the input
    Advantages: although time complexity is O(n^2) this algorithm works well in sorted list or arrays
*/

#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{   
    // selects an element and puts it at the right position according to it's value

    // run the 1st loop for n-2 times

    for(int i = 0 ; i < n-1; i++){
        // for each step min item will come at the first respective index
        int index_min = i;
        for(int j = i+1; j < n; j++){
            if(arr[index_min] > arr[j])
                index_min = j;
        }

        // if the array contains value less than at it's current position two values will be swapped
        if(index_min != i)
            swap(arr[i], arr[index_min]);
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

    cout<<"Before performing selection sort: ";
    print_list(arr, n);
    cout<<endl;
    
    selection_sort(arr, n);

    cout<<"After performing selection sort: ";
    print_list(arr, n);

    return 0;

}