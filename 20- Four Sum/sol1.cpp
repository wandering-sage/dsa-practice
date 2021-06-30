#include <bits/stdc++.h>
using namespace std;

// Using Two Pointers and sorting

// time-->O(N*3)          space-->O(1)

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
  vector<vector<int>> ans;
  if (nums.size() < 4)
  {
    return ans;
  }
  sort(nums.begin(), nums.end());
  int n = nums.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int target_2 = target - nums[i] - nums[j];
      int f = j + 1;
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
          quad.push_back(nums[j]);
          quad.push_back(nums[f]);
          quad.push_back(nums[b]);
          ans.push_back(quad);

          while (f < b && nums[f] == quad[2])
            f++;
          while (f < b && nums[b] == quad[3])
            b--;
        }
      }
      while (j + 1 < n && nums[j + 1] == nums[j])
        j++;
    }
    while (i + 1 < n && nums[i + 1] == nums[i])
      i++;
  }
  return ans;
}
