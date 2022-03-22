// A recursive program for binary search algorithm

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> nums, int target, int start, int end)
{
    if(start > end) return -1; // target element is not presented in that array.

    int mid = start + (end - start)/2;

    if(nums[mid] == target) return mid; // return the index of the targeted value.
    else if(nums[mid] < target) {       // if target element is greater than current middle element
        return binarySearch(nums, target, mid + 1, end); // making the current start = mid + 1
    }
    else {// if target element is less than current middle element
        return binarySearch(nums, target, start, mid-1);   // making the current end = mid - 1;
    }
}

int main()
{
    vector<int> nums = {1, 2, 10, 22, 50, 80, 100};

    int target = 22;

    int index = binarySearch(nums, target, 0, nums.size() - 1);

    if(index == -1){
        cout<<target<<" is not presented in the array"<<endl;
    }
    else{
        cout<<target<<" is at index position "<<index<<endl;
    }

    return 0;
}