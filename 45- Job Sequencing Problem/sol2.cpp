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

bool compare(Job i1, Job i2)
{
  return i1.profit > i2.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
  vector<int> jobs(101, 0);
  vector<int> ans;
  int total = 0, count = 0, j;

  sort(arr, arr + n, compare);

  for (int i = 0; i < n; i++)
  {
    if (jobs[arr[i].dead] != 0)
    {
      j = 1;
      int d = arr[i].dead;
      while (j < d)
      {
        if (jobs[d - j] == 0)
        {
          jobs[d - j] = arr[i].profit;
          count++;
          total += arr[i].profit;
          break;
        }
        j++;
      }
    }
    else
    {
      jobs[arr[i].dead] = arr[i].profit;
      count++;
      total += arr[i].profit;
    }
  }
  ans.push_back(count);
  ans.push_back(total);
  return ans;
}
