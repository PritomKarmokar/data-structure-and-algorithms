#include<bits/stdc++.h>
using namespace std;

// return -1 if the target value is not present
// else return right most occurrence of the target value
int search(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    int index = -1;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(nums[mid] == target){
            index = mid;
            start = mid + 1; // continue searching in the right portion after one occurrence is found
        }
        else if(nums[mid] < target) // target element is greater than the current middle element
            start = mid + 1;
        else                  // target element is smaller than the current middle element
            end = mid - 1;
    }
    // target element is not presented in the array then the index value is - 1
    return index;
}


int main()
{
    vector<int> nums = {2, 10, 20, 50, 100, 100, 100, 150, 200, 500, 1000};
    int target = 100;

    int index = search(nums, target);

    cout<<"The right most index of the value "<<target<<" is at the index "<<index<<"\n";

    return 0;
}

