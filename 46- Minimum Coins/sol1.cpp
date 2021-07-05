#include <bits/stdc++.h>
using namespace std;

// Using Greedy Apporch

// time-->O(N)          space-->O(N)

vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int n = 10;

int minCoins(int V)
{
  int j = n - 1, ans = 0;
  while (j >= 0)
  {
    if (V >= coins[j])
    {
      V -= coins[j];
      ans++;
      if (V == 0)
        return ans;
    }
    else
      j++;
  }
  return -1;
}
