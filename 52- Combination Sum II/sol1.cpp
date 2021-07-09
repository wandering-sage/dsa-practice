#include <bits/stdc++.h>
using namespace std;

// Using Recursion

// time-->O(2^N)          space-->O(2^N)

void getAllCombinations(int idx, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
  if (target == 0)
  {
    ans.push_back(ds);
    return;
  }

  for (int i = idx; i < arr.size(); i++)
  {
    if (i != idx && arr[i] == arr[i - 1])
      continue;
    if (arr[i] > target)
      return;
    ds.push_back(arr[i]);
    getAllCombinations(i + 1, target - arr[i], arr, ds, ans);
    ds.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  sort(candidates.begin(), candidates.end());
  vector<int> ds;
  vector<vector<int>> ans;
  getAllCombinations(0, target, candidates, ds, ans);
  return ans;
}