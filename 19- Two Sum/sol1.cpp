#include <bits/stdc++.h>
using namespace std;

// Using Hash Map

// time-->O(N)          space-->O(N)

vector<int> twoSum(vector<int> &nums, int target)
{
  vector<int> res;
  unordered_map<int, int> mine;
  for (int i = 0; i < nums.size(); i++)
  {
    auto it = mine.find(target - nums[i]);
    if (it != mine.end())
    {
      res.push_back(it->second);
      res.push_back(i);
      return res;
    }
    mine[nums[i]] = i;
  }
  return res;
}
