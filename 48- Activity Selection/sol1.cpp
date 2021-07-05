#include <bits/stdc++.h>
using namespace std;

// Using Greedy Apporch

// time-->O(NlogN)          space-->O(N)

int activitySelection(vector<int> start, vector<int> end, int n)
{
  vector<pair<int, int>> activity;
  int ans = 0, lastEndTime = 0;
  for (int i = 0; i < n; i++)
  {
    activity.push_back({end[i], start[i]});
  }
  sort(activity.begin(), activity.end());

  for (int i = 0; i < n; i++)
  {
    if (lastEndTime < activity[i].second)
    {
      ans++;
      lastEndTime = activity[i].first;
    }
  }
  return ans;
}