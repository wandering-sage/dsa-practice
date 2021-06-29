#include <bits/stdc++.h>
using namespace std;

// Using Moore Voting Algorithm

// time-->O(N)          space-->O(1)

vector<int> majorityElement(vector<int> &nums)
{
  int me1 = -1, me2 = -2;
  int c1 = 0, c2 = 0;
  vector<int> ret;
  int i = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == me1)
      c1++;
    else if (nums[i] == me2)
      c2++;
    else if (c1 == 0)
    {
      me1 = nums[i];
      c1++;
    }
    else if (c2 == 0)
    {
      me2 = nums[i];
      c2++;
    }
    else
    {
      c1--;
      c2--;
    }
  }
  c1 = 0;
  c2 = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == me1)
      c1++;
    if (nums[i] == me2)
      c2++;
  }
  if (c1 > nums.size() / 3)
    ret.push_back(me1);
  if (c2 > nums.size() / 3)
    ret.push_back(me2);
  return ret;
}
