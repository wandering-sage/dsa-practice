#include <bits/stdc++.h>
using namespace std;

// Using Optimized brute force

// time-->O(N)          space-->O(1)

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
  sort(intervals.begin(), intervals.end());
  vector<vector<int>> ret;
  vector<int> cur = intervals[0];
  for (int i = 0; i < intervals.size() - 1; i++)
  {
    if (cur[1] >= intervals[i + 1][0])
    {
      cur[1] = max(intervals[i + 1][1], cur[1]);
    }
    else
    {
      ret.push_back(cur);
      cur = intervals[i + 1];
    }
  }
  ret.push_back(cur);
  return ret;
}