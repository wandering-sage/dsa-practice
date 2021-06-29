#include <bits/stdc++.h>
using namespace std;

// Using Maths

// time-->O(1)          space-->O(1)

map<pair<int, int>, int> memo;
int uniquePaths(int m, int n)
{
  if (m == 1 || n == 1)
    return 1;
  if (m == 0 || n == 0)
    return 0;

  int c = n + m - 2;
  int r = min(n - 1, m - 1);
  long long x = 1;
  long long y = 1;
  for (int i = 0; i < r; i++)
  {
    x *= c - i;
    y *= i + 1;
  }
  return x / y;
}
