#include <bits/stdc++.h>
using namespace std;

// Using Two Pointers and sorting

// time-->O(N*2)          space-->O(1)

vector<vector<int>> threeSum(vector<int> &nums)
{
  vector<vector<int>> ans;
  if (nums.size() < 3)
  {
    return ans;
  }
  sort(nums.begin(), nums.end());
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    int target_2 = 0 - nums[i];
    int f = i + 1;
    int b = n - 1;
    while (f < b)
    {
      if (nums[f] + nums[b] < target_2)
        f++;
      else if (nums[f] + nums[b] > target_2)
        b--;
      else
      {
        vector<int> quad;
        quad.push_back(nums[i]);
        quad.push_back(nums[f]);
        quad.push_back(nums[b]);
        ans.push_back(quad);

        while (f < b && nums[f] == quad[1])
          f++;
        while (f < b && nums[b] == quad[2])
          b--;
      }
    }
    while (i + 1 < n && nums[i + 1] == nums[i])
      i++;
  }
  return ans;
}