#include <bits/stdc++.h>
using namespace std;

// Using Recursion

// time-->O(N*N!)          space-->O(N)

void getAllPermutations(int ptr, vector<int> &arr, vector<vector<int>> &ans)
{
  if (ptr == arr.size())
  {
    ans.push_back(arr);
    return;
  }
  for (int i = ptr; i < arr.size(); i++)
  {
    swap(arr[ptr], arr[i]);
    getAllPermutations(ptr + 1, arr, ans);
    swap(arr[ptr], arr[i]);
  }
}
vector<vector<int>> permute(vector<int> &nums)
{
  vector<vector<int>> ans;
  getAllPermutations(0, nums, ans);
  return ans;
}