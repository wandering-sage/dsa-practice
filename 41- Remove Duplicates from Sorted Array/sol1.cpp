#include <bits/stdc++.h>
using namespace std;

// Using Optimized Brute force

// time-->O(N)          space-->O(N)

int removeDuplicates(vector<int> &nums)
{
  int i = 1, j = 1, n = nums.size();
  if (n < 1)
    return 0;
  while (j < n)
  {
    if (nums[i - 1] != nums[j])
    {
      nums[i] = nums[j];
      i++;
    }
    j++;
  }
  return i;
}