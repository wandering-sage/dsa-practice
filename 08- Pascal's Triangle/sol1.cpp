#include <bits/stdc++.h>
using namespace std;

// Using Optimized Brute Force

// time-->O(N*M)          space-->O(N+M)

vector<long long> nthRowOfPascalTriangle(int n)
{
  vector<long long> ans;
  long long s;
  ans.push_back(1);
  for (int j = 1; j <= (n - 1) / 2; j++)
  {
    long long x = (ans[j - 1] * (n - j) / j);
    x %= 1000000007;
    ans.push_back(x);
  }
  int m = ans.size() - 1;
  for (int j = n % 2; j <= (n - 1) / 2; j++)
  {
    ans.push_back(ans[m - j]);
  }
  return ans;
}