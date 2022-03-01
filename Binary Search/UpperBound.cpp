#include<bits/stdc++.h>
using namespace std;

int searchUpperBound(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    int index = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(nums[mid] == target){
            index = mid;   // when the target element is presented in the array
            start = mid + 1; // continue searching in right portion after one occurrence is found
        }
        else if(nums[mid] < target){  // target element is greater than the current middle element
            start = mid + 1;
        }
        else{           // target element is smaller than the current middle element 
            end = mid - 1;
        }
    }
    // at the end we're returning end index

    return start ;
}

int main()
{
    vector<int> nums = {10, 20, 20, 30, 30, 40, 50};
    int target = 12;

    int index = searchUpperBound(nums, target);

    //cout<<nums[index]<<endl;
    cout<<index<<endl;
    
    return 0;
}