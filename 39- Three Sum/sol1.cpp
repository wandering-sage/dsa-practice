#include <bits/stdc++.h>
using namespace std;

// Using Prefix Sum and Hashing

// time-->O(N)          space-->O(N)

vector<vector<int>> threeSum(vector<int> &nums)
{
  vector<vector<int>> ans;
  int n = nums.size();
  int sum, f, b, v1, v2;

  if (n < 3)
    return ans;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < n; i++)
  {
    if (nums[i] > 0)
      break;

    f = i + 1;
    b = n - 1;
    while (f < b)
    {
      v1 = nums[f];
      v2 = nums[b];
      sum = nums[i] + v1 + v2;
      if (sum < 0)
        f++;
      else if (sum > 0)
        b--;
      else
      {
        ans.push_back({nums[i], v1, v2});

        while (f < b && nums[f] == v1)
          f++;
        while (f < b && nums[b] == v2)
          b--;
      }
    }
    while (i + 1 < n && nums[i + 1] == nums[i])
      i++;
  }
  return ans;
}