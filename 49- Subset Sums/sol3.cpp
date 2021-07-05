#include <bits/stdc++.h>
using namespace std;

// Using Recursion

// time-->O(2^N)          space-->O(2^N)

void getSubSet(int i, int n, vector<int> set, vector<int> &arr, vector<vector<int>> &ans)
{
  if (n == i)
  {
    ans.push_back(set);
    return;
  }
  getSubSet(i + 1, n, set, arr, ans);
  set.push_back(arr[i]);
  getSubSet(i + 1, n, set, arr, ans);
}

vector<vector<int>> subsets(vector<int> &arr)
{
  int N = arr.size();
  vector<int> set;
  vector<vector<int>> ans;
  sort(arr.begin(), arr.end());
  getSubSet(0, N, set, arr, ans);
  return ans;
}