#include <bits/stdc++.h>
using namespace std;

// Using something

// time-->O(N)          space-->O(1)

void nextPermutation(vector<int> &nums)
{
  int n = nums.size() - 1;
  int p = 0;
  for (int i = n; i > 0; i--)
  {
    if (nums[i - 1] < nums[i])
    {
      int j = n;
      while (nums[i - 1] >= nums[j])
        j--;
      swap(nums[j], nums[i - 1]);
      p = i;
      break;
    }
  }
  while (p < n)
  {
    swap(nums[p], nums[n]);
    p++;
    n--;
  }
}
