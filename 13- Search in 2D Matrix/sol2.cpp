#include <bits/stdc++.h>
using namespace std;

// Using simple Search

// time-->O(N+M)          space-->O(1)

int matSearch(int N, int M, vector<vector<int>> matrix, int x)
{
  int ptr1 = 0;
  int ptr2 = M - 1;
  while (ptr1 < N && ptr2 >= 0)
  {
    if (matrix[ptr1][ptr2] == x)
      return 1;
    if (matrix[ptr1][ptr2] > x)
    {
      ptr2--;
    }
    else
      ptr1++;
  }
  return 0;
}