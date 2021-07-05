#include <bits/stdc++.h>
using namespace std;

// Using Recursion and Memoization

// time-->O(2^N)          space-->O(2^N)

map<int, vector<int>> memo;
vector<int> subsetSums(vector<int> arr, int N)
{
  if (memo.find(N) != memo.end())
  {
    return memo[N];
  }
  vector<int> ans, a;
  if (N == 0)
  {
    ans.push_back(0);
    memo[0] = ans;
    return ans;
  }
  int cur = arr[N - 1];
  arr.pop_back();
  a = subsetSums(arr, N - 1);
  ans.insert(ans.end(), a.begin(), a.end());
  for (int i : a)
  {
    ans.push_back(i + cur);
  }
  sort(ans.begin(), ans.end());
  memo[N] = ans;
  return ans;
}