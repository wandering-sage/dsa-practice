#include <bits/stdc++.h>
using namespace std;

// Using Binary Exponentiation

// time-->O(logN)          space-->O(1)

double myPow(double x, int m)
{
  long long n = m;
  double y = 1;
  bool flag = false;
  if (n == 0)
    return 1;
  if (n < 0)
  {
    n = abs(n);
    flag = true;
  }
  while (n > 0)
  {
    if (n % 2 == 0)
    {
      x *= x;
      n = n / 2;
    }
    else
    {
      y *= x;
      n--;
    }
  }
  x = y;
  if (flag)
    x = 1 / x;
  return x;
}