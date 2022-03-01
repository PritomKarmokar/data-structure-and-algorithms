#include<bits/stdc++.h>
using namespace std;

// returning the index
// in case the target element is not present it will return -1
int search(vector<int> &nums, int target)
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

    // target element is not presented in the array
    return -1;
}

int main()
{
    vector<int> nums = {1, 5, 10, 13, 15, 20, 25, 94};
    int target = 94;    // when target element is presented in the array

    int ans = search(nums, target);
    
    cout<<"Index of the target value is "<<ans<<endl;

    return 0;
}