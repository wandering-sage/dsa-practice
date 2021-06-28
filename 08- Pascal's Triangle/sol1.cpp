#include <bits/stdc++.h>
using namespace std;

// To Return the complete Pascal's Triangle

// time-->O(N*N)          space-->O(N*N)

vector<vector<int>> generate(int numRows)
{
  vector<vector<int>> ans{
      {1},
      {1, 1}};
  vector<int> v{};
  if (numRows < 3)
  {
    if (numRows == 1)
      ans.pop_back();
    return ans;
  }
  for (int i = 3; i <= numRows; i++)
  {
    ans.push_back(v);
    ans[i - 1].push_back(1);
    for (int j = 1; j < i - 1; j++)
    {
      ans[i - 1].push_back(ans[i - 2][j - 1] + ans[i - 2][j]);
    }
    ans[i - 1].push_back(1);
  }
  return ans;
}