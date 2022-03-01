#include<bits/stdc++.h>
using namespace std;

int searchLowerBound(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    int index = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(nums[mid] == target){
            index = mid;   // when the target element is presented in the array
            end = mid - 1; // continue searching in left portion after one occurrence is found
        }
        else if(nums[mid] < target){  // target element is greater than the current middle element
            start = mid + 1;
        }
        else{           // target element is smaller than the current middle element 
            end = mid - 1;
        }
    }
    // at the end we're returning start index

    return start ;
}

int main()
{
    vector<int> nums = {10, 20, 20, 30, 30, 40, 50};
    int target = 30;

    int index = searchLowerBound(nums, target);

    cout<<index<<endl;

    return 0;
}