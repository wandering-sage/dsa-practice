#include <bits/stdc++.h>
using namespace std;

// Using Hash map

// time-->O(N)           space-->O(N)

vector<int> findTwoElement(int *arr, long long n)
{
  vector<bool> hMap(n + 1, false);
  int rep = -1;
  long long sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
    if (hMap[arr[i]])
      rep = arr[i];
    else
      hMap[arr[i]] = true;
  }
  long long diff = n * (n + 1) / 2 - sum;
  long long missing = rep + diff;
  vector<int> ret;
  ret.push_back(rep);
  ret.push_back(missing);
  return ret;
}