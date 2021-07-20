#include <bits/stdc++.h>
using namespace std;

// Using BacTracking

// time-->O(N*N!)          space-->O(N)

void solve(int i, int j, int n, vector<vector<int>> &m, vector<string> &ans, string &str, vector<vector<bool>> &vis)
{
  if (i == n - 1 && j == n - 1)
  {
    ans.push_back(str);
    return;
  }
  if (i + 1 < n && !vis[i + 1][j] && m[i + 1][j] == 1)
  {
    str = str + "D";
    vis[i][j] = true;
    solve(i + 1, j, n, m, ans, str, vis);
    vis[i][j] = false;
    str = str.substr(0, str.size() - 1);
  }
  if (j - 1 > -1 && !vis[i][j - 1] && m[i][j - 1] == 1)
  {
    str = str + "L";
    vis[i][j] = true;
    solve(i, j - 1, n, m, ans, str, vis);
    vis[i][j] = false;
    str = str.substr(0, str.size() - 1);
  }
  if (j + 1 < n && !vis[i][j + 1] && m[i][j + 1] == 1)
  {
    str = str + "R";
    vis[i][j] = true;
    solve(i, j + 1, n, m, ans, str, vis);
    vis[i][j] = false;
    str = str.substr(0, str.size() - 1);
  }
  if (i - 1 > -1 && !vis[i - 1][j] && m[i - 1][j] == 1)
  {
    str = str + "U";
    vis[i][j] = true;
    solve(i - 1, j, n, m, ans, str, vis);
    vis[i][j] = false;
    str = str.substr(0, str.size() - 1);
  }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
  vector<vector<bool>> vis(n, vector<bool>(n, false));
  vector<string> ans;
  string str = "";
  if (m[0][0] == 0)
  {
    ans.push_back("-1");
    return ans;
  }
  solve(0, 0, n, m, ans, str, vis);
  if (ans.size() == 0)
  {
    ans.push_back("-1");
    return ans;
  }
  return ans;
}