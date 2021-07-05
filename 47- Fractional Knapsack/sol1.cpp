#include <bits/stdc++.h>
using namespace std;

// Using Greedy Apporch

// time-->O(NlogN)          space-->O(N)

struct Item
{
  int value;
  int weight;
};

bool compare(Item i1, Item i2)
{
  double a1 = (double)i1.value / i1.weight;
  double a2 = (double)i2.value / i2.weight;
  return a1 > a2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
  double ans = 0;
  sort(arr, arr + n, compare);
  int j = 0;
  while (j < n)
  {
    if (arr[j].weight < W)
    {
      ans += arr[j].value;
      W -= arr[j].weight;
    }
    else
    {
      double x = (double)arr[j].value / arr[j].weight;
      ans += x * W;
      return ans;
    }
    j++;
  }
  return ans;
}