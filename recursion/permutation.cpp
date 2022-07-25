#include<bits/stdc++.h>
using namespace std;

void recurPermute(vector< int > &ds, vector< int > &nums, vector< vector< int>> &ans, bool freq[])
{
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

int main()
{
    vector< int > nums {1, 2, 3};
    vector< int > ds;

    bool freq[nums.size()] = {0};
    vector< vector< int >> ans;

    recurPermute(ds, nums, ans, freq);

    for(auto permute: ans){
        for(auto val: permute){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}