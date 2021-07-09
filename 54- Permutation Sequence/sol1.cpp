#include <bits/stdc++.h>
using namespace std;

// Using Recursion

// time-->O(2^N)          space-->O(2^N)

string getPermutation(int n, int k)
{
  vector<int> nums;
  int fact = 1;
  for (int i = 1; i <= n; i++)
  {
    nums.push_back(i);
    fact *= i;
  }
  k--;
  string ans = "";
  for (int i = 1; i < n + 1; i++)
  {
    fact /= nums.size();
    int x = k / fact;
    ans += to_string(nums[x]);
    k %= fact;
    nums.erase(nums.begin() + x, nums.begin() + x + 1);
  }
  return ans;
}