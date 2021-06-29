#include <bits/stdc++.h>
using namespace std;

// Using Recursion And Memoization

// time-->O(N*M)          space-->O(N*M)

map<pair<int, int>, int> memo;
int uniquePaths(int m, int n)
{
  if (memo.find(make_pair(m, n)) != memo.end())
    return memo[make_pair(m, n)];
  if (m == 1 && n == 1)
    return 1;
  if (m == 0 || n == 0)
    return 0;
  memo[make_pair(m, n)] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
  return memo[make_pair(m, n)];
}
