#include <bits/stdc++.h>
using namespace std;

// Using O(1)space Two pointes Approch

// time-->O(N)          space-->O(1)

int trap(vector<int> &height)
{
  int n = height.size();
  if (n < 3)
    return 0;
  int lmax = 0, rmax = 0, i = 0, j = n - 1, ans = 0;
  while (i < j)
  {
    if (height[i] <= height[j])
    {
      lmax = max(lmax, height[i]);
      ans += lmax - height[i];
      i++;
    }
    else
    {
      rmax = max(height[j], rmax);
      ans += rmax - height[j];
      j--;
    }
  }
  return ans;
}