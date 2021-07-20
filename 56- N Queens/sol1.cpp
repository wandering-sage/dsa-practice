#include <bits/stdc++.h>
using namespace std;

// Using Recursion

// time-->O(N*N!)          space-->O(N)

bool isSafe(int i, int j, vector<string> &ar)
{
  // check behind i.e. same i
  for (int k = j - 1; k > -1; k--)
  {
    if (ar[i][k] == 'Q')
      return false;
  }
  // check upper diagonal
  for (int k = i - 1, l = j - 1; k > -1 && l > -1; k--, l--)
  {
    if (ar[k][l] == 'Q')
      return false;
  }
  // check lower diagonal
  for (int k = i + 1, l = j - 1; k < ar[0].size() && l > -1; k++, l--)
  {
    if (ar[k][l] == 'Q')
      return false;
  }
  return true;
}
void placeQueens(int i, int n, vector<string> &ar, vector<vector<string>> &ans)
{
  if (i == n)
  {
    ans.push_back(ar);
    return;
  }
  for (int j = 0; j < n; j++)
  {
    if (isSafe(j, i, ar))
    {
      ar[j][i] = 'Q';
      placeQueens(i + 1, n, ar, ans);
      ar[j][i] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n)
{
  vector<vector<string>> ans;
  string s(n, '.');
  vector<string> board(n, s);
  placeQueens(0, n, board, ans);
  return ans;
}