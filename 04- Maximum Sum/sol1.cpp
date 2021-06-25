#include <bits/stdc++.h>
using namespace std;

// Using Kadane’s Algorithm

// time-->O(N)          space-->O(1)

int maxSubArray(vector<int> &nums)
{
  long long m = INT_MIN;
  long long curSum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    curSum += nums[i];
    m = max(curSum, m);
    if (curSum < 0)
    {
      curSum = 0;
    }
  }
  return m;
}

// int maxSubarraySum(int arr[], int n){
//   long long max = arr[0];
//   long long curSum = 0;
//   for (int i = 0; i < n; i++)
//   {
//     if (max < arr[i])
//       max = arr[i];
//   }
//   if (max < 0)
//   {
//     return max;
//   }
//   for (int i = 0; i < n; i++)
//   {
//     if ((curSum + arr[i]) > 0)
//     {
//       curSum += arr[i];
//     }
//     else if (arr[i] > 0)
//     {
//       curSum = arr[i];
//     }
//     else
//     {
//       curSum = 0;
//     }
//     if (max < curSum)
//       max = curSum;
//   }
//   return max;
// }