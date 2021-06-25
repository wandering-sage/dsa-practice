#include <bits/stdc++.h>
using namespace std;

// Two pointers Meathod also known as Dutch National Flag Algorithm

// time-->O(N)          space-->O(1)

void sortColors(vector<int> &nums)
{
  int l = 0;
  int cur = 0;
  int h = nums.size() - 1;
  while (cur <= h)
  {
    if (nums[cur] == 0)
    {
      if (l != cur)
        swap(nums[l], nums[cur]);
      l++;
      cur++;
    }
    else if (nums[cur] == 1)
      cur++;
    else
    {
      swap(nums[h], nums[cur]);
      h--;
    }
  }
}