//https://leetcode.com/problems/permutations-ii/
#include<bits/stdc++.h>
using namespace std;

set< vector< int >> check;

void recurPermute(vector< int > &ds, vector< int > &nums, vector< vector < int >> &ans, bool freq[])
{
    if(ds.size() == nums.size()){
        if(check.count(ds) == 0){
            check.insert(ds);
            ans.push_back(ds);
        }
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
    vector< int > nums{1, 2, 2};
    vector< int > ds;
    vector< vector < int >> ans;
    bool freq[nums.size()] = {0};

    sort(nums.begin(), nums.end());

    recurPermute(ds, nums, ans, freq);

    for(auto res : ans){
        for(auto values : res){
            cout<<values<<" ";
        }
        cout<<endl;
    }
    return 0;
}