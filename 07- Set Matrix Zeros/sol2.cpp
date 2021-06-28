#include <bits/stdc++.h>
using namespace std;

// Using O(1)space Optimized Brute Force

// time-->O(N*M)          space-->O(1)

void setZeroes(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  int m = matrix[0].size();
  bool firstCol = false;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (matrix[i][j] == 0)
      {
        matrix[i][0] = 0;
        if (j == 0)
        {
          firstCol = true;
        }
        else
          matrix[0][j] = 0;
      }
    }
  }
  for (int i = n - 1; i > -1; i--)
  {
    for (int j = m - 1; j > 0; j--)
    {
      if (matrix[i][0] == 0 || matrix[0][j] == 0)
        matrix[i][j] = 0;
    }
  }

  if (firstCol)
  {
    for (int i = 0; i < n; i++)
    {
      matrix[i][0] = 0;
    }
  }
}