#include <bits/stdc++.h>
using namespace std;

// Using Hashing

// time-->O(N)          space-->O(N)

int longestConsecutive(vector<int> &nums)
{
  int cnt = 0;
  int max = 0;
  unordered_set<int> map;
  for (int num : nums)
  {
    map.insert(num);
  }
  for (int i : map)
  {
    if (map.find(i - 1) == map.end())
    {
      cnt = 1;
      int j = 1;
      while (map.find(i + j) != map.end())
      {
        j++;
        cnt++;
      }
      if (cnt > max)
        max = cnt;
    }
  }
  return max;
}