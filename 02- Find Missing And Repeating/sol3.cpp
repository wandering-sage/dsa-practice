#include <bits/stdc++.h>
using namespace std;

// Using Sum and sum of squares

// time-->O(N)           space-->O(1)

vector<int> findTwoElement(int *arr, long long n)
{
  long long sum = 0;
  long long sqSum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
    sqSum += (long long)arr[i] * arr[i];
  }
  long long diff = n * (n + 1) / 2 - sum;
  long long sqDiff = n * (n + 1) * ((2 * n) + 1) / 6 - sqSum;
  long long mrSum = sqDiff / diff;
  int rep = (mrSum - diff) / 2;
  int missing = (mrSum + diff) / 2;
  vector<int> ret;
  ret.push_back(rep);
  ret.push_back(missing);
  return ret;
}