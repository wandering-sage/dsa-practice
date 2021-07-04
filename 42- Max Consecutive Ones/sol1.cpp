#include <bits/stdc++.h>
using namespace std;

// Using Optimized Brute force

// time-->O(N)          space-->O(N)

int findMaxConsecutiveOnes(vector<int> &nums)
{
  int max = 0;
  int streak = 0;
  for (int i : nums)
  {
    if (i == 0)
      streak = 0;
    else
      streak++;
    if (streak > max)
      max = streak;
  }
  return max;
}