#include <bits/stdc++.h>
using namespace std;

// Using Moore Voting Algorithm

// time-->O(N)          space-->O(1)

int majorityElement(vector<int> &nums)
{
  int me = nums[0];
  int counter = 1;
  int i = 1;
  while (i < nums.size())
  {
    if (nums[i] == me)
      counter++;
    else
      counter--;
    if (counter == 0)
    {
      me = nums[i];
      counter++;
    }
    i++;
  }
  int c = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == me)
      c++;
  }
  if (c > nums.size() / 2)
    return me;
  return -1;
}
