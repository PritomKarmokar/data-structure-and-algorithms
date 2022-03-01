#include<bits/stdc++.h>
using namespace std;

// floor of a number is the greatest element in the array smaller than or equal to target

// returning the index of the target value
// else returning the next smaller number than the target element.

int floor(vector<int> &nums, int target)
{
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
    // and since target is not presented in the array we'll return the next small number
    // which is currently is locating at the end position.
    return end;
}

int main()
{
    vector<int> nums = {1, 5, 10, 13, 15, 20, 25, 94};

    int target = 0;     // when the target element is not present in the array.

    int ans = floor(nums, target);

    //cout<<nums[ans]<<endl;
    cout<<ans<<endl;
    return 0; 
}