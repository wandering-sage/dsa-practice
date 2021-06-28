#include <bits/stdc++.h>
using namespace std;

// Using Binary Search

// time-->O(logN)          space-->O(1)

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int n = matrix[0].size() - 1;
  int n1 = matrix.size() - 1;
  if (target > matrix[n1][n])
    return false;
  int l = 0, h = n1;
  while (l < h)
  {
    int m = l + (h - l) / 2;
    if (target == matrix[m][n])
    {
      return true;
    }
    if (target > matrix[m][n])
    {
      l = m + 1;
    }
    else
    {
      h = m;
    }
  }
  l = 0;
  while (l < n)
  {
    int m = l + (n - l) / 2;
    if (target == matrix[h][m])
    {
      return true;
    }
    if (target > matrix[h][m])
    {
      l = m + 1;
    }
    else
    {
      n = m;
    }
  }
  if (matrix[h][l] == target)
    return true;
  return false;
}