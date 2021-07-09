#include <bits/stdc++.h>
using namespace std;

// Using Recursion

// time-->O(2^N)          space-->O(2^N)

void getAllCombinations(int idx, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
  if(target == 0){
    ans.push_back(ds);
    return;
  }
  if(idx==arr.size()){
    return;
  }
  if(arr[idx]>target){
    return;
  }
  ds.push_back(arr[idx]);
  getAllCombinations(idx, target-arr[idx], arr, ds, ans);
  ds.pop_back();
  getAllCombinations(idx+1, target, arr, ds, ans);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  sort(candidates.begin(), candidates.end());
  vector<int> ds;
  vector<vector<int>> ans;
  getAllCombinations(0, target,candidates,ds,ans);
  return ans;
}