#include <bits/stdc++.h>
using namespace std;

// Using Greedy Apporch

// time-->O(NlogN)          space-->O(N)

int findPlatform(int arr[], int dep[], int n)
{
  sort(arr, arr + n);
  sort(dep, dep + n);
  int trains = 0, ans = 0, j = 0;
  for (int i = 0; i < n; i++)
  {
    while (arr[i] > dep[j])
    {
      trains--;
      j++;
    }
    trains++;
    ans = max(trains, ans);
  }
  return ans;
}
