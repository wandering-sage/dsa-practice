#include <bits/stdc++.h>
using namespace std;

// Using Recursion

// time-->O(N*N!)          space-->O(N)

void getAllPermutations(vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, vector<bool> &map)
{
  if (ds.size() == arr.size())
  {
    ans.push_back(ds);
    return;
  }

  for (int i = 0; i < arr.size(); i++)
  {
    if (map[i])
      continue;
    map[i] = true;
    ds.push_back(arr[i]);
    getAllPermutations(arr, ds, ans, map);
    map[i] = false;
    ds.pop_back();
  }
}
vector<vector<int>> permute(vector<int> &nums)
{
  vector<int> ds;
  vector<vector<int>> ans;
  vector<bool> map(nums.size(), false);
  getAllPermutations(nums, ds, ans, map);
  return ans;
}