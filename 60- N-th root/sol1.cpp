#include <bits/stdc++.h>
using namespace std;

// Using BacTracking

// time-->O(N*N!)          space-->O(N)

int NthRoot(int n, int m)
{
  if (n == 1)
    return m;
  double high = m, low = 0, mid;
  double eps = 0.1;
  long double p, i;
  while ((high - low) > eps)
  {
    mid = (low + high) / 2.0;
    p = 1;
    i = 0;
    while (i < n)
    {
      i++;
      p *= mid;
      if (m < p)
        break;
    }
    if (m == p)
    {
      return mid;
    }
    if (p < m)
      low = mid;
    else
      high = mid;
  }
  int x = round(mid);
  p = 1;
  for (int i = 0; i < n; i++)
    p *= x;
  if (p == m)
    return x;
  return -1;
}