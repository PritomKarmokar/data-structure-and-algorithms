#include<bits/stdc++.h>
using namespace std;

// ceiling of a number is the smallest element in the array greater than or equal to target

// returning the index of the target value
// else returning the next big number greater than the target element.

int ceiling(vector<int> &nums, int target)
{   
    // If the target number is greater than the greatest element in the array
    if(target > nums[ nums.size() - 1]) return -1;

    int start = 0;
    int end = nums.size() - 1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(nums[mid] == target) // when the target element is presented in the array
            return mid;
        
        if(nums[mid] < target) // target element is greater than the current middle element
            start = mid + 1;
        else                  // target element is smaller than the current middle element
            end = mid - 1;
    }

    // at the end of while loop start becomes greater than the end value
    // and since target is not presented in the array we'll return the next large number
    // which is currently is locating at the start position.
    return start;
}

int main()
{
    vector<int> nums = {1, 5, 10, 13, 15, 20, 25, 94};

    int target = 14;     // when the target element is not present in the array.


    int ans = ceiling(nums, target);
    
    cout<<nums[ans]<<endl;

    return 0; 
}