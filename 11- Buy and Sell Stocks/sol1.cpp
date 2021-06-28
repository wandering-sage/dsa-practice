#include <bits/stdc++.h>
using namespace std;

// Using Optimized Brute Force

// time-->O(N)          space-->O(1)

int maxProfit(vector<int> &prices)
{
  int profit = 0;
  int max = -1;
  for (int i = prices.size() - 1; i >= 0; i--)
  {
    if (profit < max - prices[i])
      profit = max - prices[i];
    if (max < prices[i])
      max = prices[i];
  }
  return profit;
}