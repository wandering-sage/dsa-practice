#include <bits/stdc++.h>
using namespace std;

// Using Counting Sort

// time-->O(N)          space-->O(1)

void sortColors(vector<int> &nums)
{
  int x = 0, y = 0, z = 0;
  for (auto i : nums)
  {
    switch (i)
    {
    case 0:
      x++;
      break;
    case 1:
      y++;
      break;
    default:
      z++;
    }
  }
  int i = 0;
  while (x > 0)
  {
    nums[i] = 0;
    x--;
    i++;
  }
  while (y > 0)
  {
    nums[i] = 1;
    y--;
    i++;
  }
  while (z > 0)
  {
    nums[i] = 2;
    z--;
    i++;
  }
}