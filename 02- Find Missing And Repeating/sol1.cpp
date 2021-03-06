#include <bits/stdc++.h>
using namespace std;

// Using Sorting

// time-->O(N*logN)          space-->O(1)

vector<int> findTwoElement(int *arr, long long n)
{
  sort(arr, arr + n);
  int rep = -1;
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
    if (i < n - 1 && arr[i] == arr[i + 1])
      rep = arr[i];
  }
  long long diff = n * (n + 1) / 2 - sum;
  long long missing = rep + diff;
  vector<int> ret;
  ret.push_back(rep);
  ret.push_back(missing);
  return ret;
}