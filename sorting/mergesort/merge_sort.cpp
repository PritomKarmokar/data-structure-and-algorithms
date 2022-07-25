/*
    Merge Sort Algorithm 
    Time Complexity : O(n * log(n))

    Space Complexity : O(n); Since extra array or list is required for storing the values.
*/
#include<bits/stdc++.h>
using namespace std;

// A function for merging two parts of the array
void merge(int *arr, int left, int mid, int right)
{
    int size_left = mid - left + 1;
    int size_right = right - mid;

    int L[size_left], R[size_right];

    for(int i = 0; i < size_left; i++){
        L[i] = arr[left + i];
    }

    for(int i = 0; i < size_right; i++){
        R[i] = arr[mid + 1 + i];
    }

    int i = left;
    int index_l = 0, index_r = 0;

    while(index_l < size_left && index_r < size_right){
        if(L[index_l] < R[index_r]){
            arr[i] = L[index_l];
            i++;
            index_l++;
        }
        else{
            arr[i] = R[index_r];
            i++;
            index_r++;
        }
    }

    while(index_l < size_left){
        arr[i] = L[index_l];
        i++;
        index_l++;
    }

    while(index_r < size_right){
        arr[i] = R[index_r];
        i++;
        index_r++;
    }
}

// Merge sort 
void merge_sort(int *arr, int left, int right)
{
    if(left >= right) return;

    int mid = left + (right - left)/2;

    merge_sort(arr, left, mid);

    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, right);
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

    merge_sort(arr, 0, n-1);

    cout<<"After sorting : ";
    print_arr(arr, n);
}
