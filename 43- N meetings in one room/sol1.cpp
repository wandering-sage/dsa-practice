#include <bits/stdc++.h>
using namespace std;

// Using Greedy Apporch

// time-->O(NlogN)          space-->O(N)

int maxMeetings(int start[], int end[], int n)
{
  vector<pair<int, int>> a;
  int ans = 1, etime;
  for (int i = 0; i < n; i++)
  {
    a.push_back({end[i], start[i]});
  }
  sort(a.begin(), a.end());
  etime = a[0].first;
  for (int i = 1; i < n; i++)
  {
    if (a[i].second > etime)
    {
      etime = a[i].first;
      ans++;
    }
  }
  return ans;
}