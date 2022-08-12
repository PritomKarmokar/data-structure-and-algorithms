//https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/

#include<bits/stdc++.h>
using namespace std;

// A function that uses binary search approach to find an element presented in a sorted array.
int search(vector < int > &nums, int target, int start, int end)
{
    while(start <= end){
        
        int mid = start + (end - start)/2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    return -1;
}

// A function that searches for the target in an sorted array whose length is infinite.
int searchInInfinite(vector< int > &nums, int target)
{
    int start = 0;
    int end = 1;

    // since we don't know the size of the array so we'll be doubling end size until the target element is not less than the nums[end].
    while(nums[end] < target){
        int temp = end + 1; 
        end = end + (end - start + 1) * 2;
        start = temp;
        //cout<<"nums["<<end<<"] = "<<nums[end]<<" target = "<<target<<endl;
        //cout<<"start = "<<start<<" end = "<<end<<endl;
    }

    return search(nums, target, start, end);
}

// main function starts here.
int main()
{
    vector< int > nums(100); // we're assuming it is as infinite array although the length is finite here.
    
    // for implementation purpose we need to take bigger sized array else it may cause segmentation fault.
    for(int i = 0; i < 100; i++){
        nums[i] = (2*i) + 1;
    }

    int target = 13;

    for(auto val: nums){
        cout<<val<<" ";
    }
    cout<<endl;

    int searchIndex = searchInInfinite(nums, target);

    if(searchIndex){        
        cout<<"Index of the value is = "<<searchIndex<<endl;
    }
    else{
        cout<<target<<" is not presented here"<<endl;
    }

    return 0;
}