#include <bits/stdc++.h>
using namespace std;

// Using Binary Exponentiation

// time-->O(logN)          space-->O(1)

long long int power(int x, long long int n)
{
  long long y = 1;
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
      x %= 1000000007;
      n = n / 2;
    }
    else
    {
      y *= x;
      y %= 1000000007;
      n--;
    }
  }
  x = y;
  if (flag)
    x = 1 / x;
  return x;
}
