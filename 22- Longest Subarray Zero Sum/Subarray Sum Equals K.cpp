#include <bits/stdc++.h>
using namespace std;

// Using Prefix Sum and Hashing

// time-->O(N)          space-->O(N)

int subarraySum(vector<int> &nums, int k)
{
  unordered_map<int, int> map;
  int sum = 0;
  int count = 0;
  map[0] = 1;
  for (int i = 0; i < nums.size(); i++)
  {
    sum += nums[i];
    if (map.find(sum - k) != map.end())
    {
      count += map[sum - k];
    }
    map[sum]++;
  }
  return count;
}