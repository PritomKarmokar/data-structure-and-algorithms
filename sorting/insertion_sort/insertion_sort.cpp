/*  Insertion sort algorithm
    Time complexity: O(n) -> If the list or array is already sorted which is considered as best case complexity.
                     O(n^2) -> Worst case complexity
    Space complexity: O(1) since the size of the array is not considered for the algorithm
*/
#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for(int i = 1; i < n ; i++){
        // for every index element putting that element at the correct index of it's left hand side
        int item = arr[i];

        int j = i-1;

        while(j >= 0 && arr[j] > item){
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = item;
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
    int arr[] = {-1,2,-2,0,10,20};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before performing selection sort: ";
    print_list(arr, n);
    cout<<endl;
    
    insertion_sort(arr, n);

    cout<<"After performing selection sort: ";
    print_list(arr, n);

    return 0;

}