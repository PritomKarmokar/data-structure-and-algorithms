/*
    Cycle Sort Algorithm implementation
    This algorithm is useful when the given numbers is between 1 to n
    Time Complexity : O(n)
    Space Complexity : O(1) , since array size is not considered for the algorithm
*/
#include<bits/stdc++.h>
using namespace std;

// useful when given numbers range is between 1 to n
void cycle_sort(int arr[], int n)
{
    int i = 0;
    while(i < n){
        int correct = arr[i] - 1;
        
        // if the position the value is not correct then swap.
        if(arr[i] != arr[correct])
            swap(arr[i], arr[correct]);
        else 
            i++;
    }
}

void print_list(int arr[], int n)
{
    // a function for printing the elements presented in the array

    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {2, 4, 5, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before sorting : ";
    print_list(arr,n);

    cycle_sort(arr,n);

    cout<<"After sorting : ";
    print_list(arr,n);
    cout<<endl;

    return 0;
}