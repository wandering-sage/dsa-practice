#include <bits/stdc++.h>
using namespace std;

// Using Prefix Sum and Hashing

// time-->O(N)          space-->O(N)

int maxLen(int A[], int n)
{
  unordered_map<int, int> map;
  int sum = 0;
  int max = 0;
  map[0] = -1;
  for (int i = 0; i < n; i++)
  {
    sum += A[i];
    if (map.find(sum) == map.end())
    {
      map[sum] = i;
    }
    else
    {
      int cur = i - map[sum];
      if (max < cur)
        max = cur;
    }
  }
  return max;
}