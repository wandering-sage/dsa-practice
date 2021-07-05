#include <bits/stdc++.h>
using namespace std;

// Using Recursion

// time-->O(2^N)          space-->O(2^N)

void getSubSet(int ind, vector<int> &set, vector<int> &arr, vector<vector<int>> &ans)
{
  ans.push_back(set);
  for (int i = ind; i < arr.size(); i++)
  {
    if (i != ind && arr[i] == arr[i - 1])
      continue;
    set.push_back(arr[i]);
    getSubSet(i + 1, set, arr, ans);
    set.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int> &arr)
{
  sort(arr.begin(), arr.end());
  vector<int> set;
  vector<vector<int>> ans;
  getSubSet(0, set, arr, ans);
  return ans;
}