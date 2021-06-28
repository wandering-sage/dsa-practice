#include <bits/stdc++.h>
using namespace std;

// To Return nth Row

// time-->O(N*N)          space-->O(N*N)

vector<long long> nthRowOfPascalTriangle(int n)
{
  vector<vector<long long>> ans{
      {1},
      {1, 1}};
  vector<long long> v{};
  if (n < 3)
  {
    if (n == 1)
      ans.pop_back();
    return ans[ans.size() - 1];
  }
  for (int i = 3; i <= n; i++)
  {
    ans.push_back(v);
    ans[i - 1].push_back(1);
    for (int j = 1; j < i - 1; j++)
    {
      ans[i - 1].push_back((ans[i - 2][j - 1] + ans[i - 2][j]) % 1000000007);
    }
    ans[i - 1].push_back(1);
  }
  return ans[ans.size() - 1];
}

// vector<long long> nthRowOfPascalTriangle(int n)
// {
//   vector<long long> ans;
//   long long s;
//   ans.push_back(1);
//   for (int j = 1; j <= (n - 1) / 2; j++)
//   {
//     long long x = (ans[j - 1] * (n - j) / j);
//     x %= 1000000007;
//     ans.push_back(x);
//   }
//   int m = ans.size() - 1;
//   for (int j = n % 2; j <= (n - 1) / 2; j++)
//   {
//     ans.push_back(ans[m - j]);
//   }
//   return ans;
// }