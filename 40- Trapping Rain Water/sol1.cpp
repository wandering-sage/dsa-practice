#include <bits/stdc++.h>
using namespace std;

// Using Optimized Brute force

// time-->O(N)          space-->O(N)

int trap(vector<int> &height)
{
  int max = -1, maxi = -1, trapped = 0;
  int n = height.size();
  if (n < 3)
    return trapped;
  for (int i = 0; i < n; i++)
    if (max < height[i])
    {
      max = height[i];
      maxi = i;
    }
  vector<int> minLR(n, 0);
  minLR[maxi] = max;
  max = -1;
  for (int i = 0; i < maxi; i++)
  {
    if (height[i] > max)
    {
      max = height[i];
    }
    minLR[i] = max;
  }
  max = -1;
  for (int j = n - 1; j > maxi; j--)
  {
    if (height[j] > max)
    {
      max = height[j];
    }
    minLR[j] = max;
  }

  for (int i = 0; i < n; i++)
  {
    trapped += minLR[i] - height[i];
  }

  return trapped;
}