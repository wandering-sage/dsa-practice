#include <bits/stdc++.h>
using namespace std;

// Using Transpose and row reverse

// time-->O(N*N)          space-->O(1)

void rotate(vector<vector<int>> &matrix)
{
  // Transpose the matrix
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < i; j++)
    {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  // Row reverse
  for (int i = 0; i < matrix.size(); i++)
  {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}