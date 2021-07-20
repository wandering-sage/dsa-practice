#include <bits/stdc++.h>
using namespace std;

// Using BacTracking

// time-->O(N*N!)          space-->O(N)
bool checkColor(int i, int n, int c, bool graph[101][101], vector<int> &ar)
{
  for (int j = 0; j < n; j++)
  {
    if (graph[i][j] && ar[j] == c)
      return false;
  }
  return true;
}

bool checkM(int i, int n, int m, bool graph[101][101], vector<int> &ar)
{
  if (i == n)
  {
    return true;
  }
  for (int j = 0; j < m; j++)
  {
    if (checkColor(i, n, j + 1, graph, ar))
    {
      ar[i] = j + 1;
      if (checkM(i + 1, n, m, graph, ar))
        return true;
      ar[i] = 0;
    }
  }
  return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
  vector<int> ar(V, 0);
  return checkM(0, V, m, graph, ar);
}