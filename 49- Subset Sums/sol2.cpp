#include <bits/stdc++.h>
using namespace std;

// Using Recursion

// time-->O(2^N)          space-->O(2^N)

void getSubSet(int i, int n, int sum, vector<int> &arr, vector<int> &ans)
{
  if (n == i)
  {
    ans.push_back(sum);
    return;
  }
  getSubSet(i + 1, n, sum, arr, ans);
  getSubSet(i + 1, n, sum + arr[i], arr, ans);
}

vector<int> subsetSums(vector<int> arr, int N)
{
  vector<int> ans;
  sort(arr.begin(), arr.end());
  getSubSet(0, N, 0, arr, ans);
  sort(ans.begin(), ans.end());
  return ans;
}