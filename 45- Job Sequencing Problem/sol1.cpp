#include <bits/stdc++.h>
using namespace std;

// Using Greedy Apporch

// time-->O(NlogN)          space-->O(N)

struct Job
{
  int id;     // Job Id
  int dead;   // Deadline of job
  int profit; // Profit if job is over before or on deadline
};

vector<int> JobScheduling(Job arr[], int n)
{
  vector<int> p(101, 0);
  vector<int> ans;
  int total = 0, count = 0;
  for (int i = 0; i < n; i++)
  {
    if (p[arr[i].dead] < arr[i].profit)
      p[arr[i].dead] = arr[i].profit;
  }
  for (int i = 1; i <= 100; i++)
  {
    if (p[i] > 0)
    {
      total += p[i];
      count++;
    }
  }
  ans.push_back(count);
  ans.push_back(total);
  return ans;
}
