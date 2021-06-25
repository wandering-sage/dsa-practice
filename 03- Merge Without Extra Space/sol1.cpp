#include <bits/stdc++.h>
using namespace std;

// Using Insertion Sort

// time-->O(N*M)          space-->O(1)

void merge(int arr1[], int arr2[], int n, int m)
{
  int ptr = 1;
  int cur;
  for (int i = 0; i < n; i++)
  {
    if (arr1[i] > arr2[0])
    {
      cur = arr1[i];
      arr1[i] = arr2[0];
      while (cur > arr2[ptr] && ptr < m)
      {
        ptr++;
      }
      for (int j = 0; j < ptr - 1; j++)
      {
        arr2[j] = arr2[j + 1];
      }
      arr2[ptr - 1] = cur;
    }
  }
}