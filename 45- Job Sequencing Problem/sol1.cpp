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
  if (i1.dead == i2.dead)
    return i1.profit > i2.profit;
  return (i1.dead < i2.dead);
}

vector<int> JobScheduling(Job arr[], int n)
{
  priority_queue<int, vector<int>, greater<int>> minHeap;
  vector<int> ans;
  int total = 0, count = 0, j;

  sort(arr, arr + n, compare);

  minHeap.push(arr[0].profit);

  for (int i = 1; i < n; i++)
  {
    if (arr[i].dead > minHeap.size())
    {
      minHeap.push(arr[i].profit);
    }
    else if (minHeap.top() < arr[i].profit)
    {
      minHeap.pop();
      minHeap.push(arr[i].profit);
    }
  }

  while (minHeap.empty() == false)
  {
    count++;
    total += minHeap.top();
    minHeap.pop();
  }

  ans.push_back(count);
  ans.push_back(total);
  return ans;
}
