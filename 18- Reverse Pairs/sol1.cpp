#include <bits/stdc++.h>
using namespace std;

// Using Merge sort and two pointers

// time-->O(Nlog(N))          space-->O(N)

#define ll long long

int merge(vector<int> &nums, vector<int> &tmp, int l, int mid, int h)
{
  int count = 0;
  int ptr1 = l;
  int ptr2 = mid;
  int k = mid;
  for (int i = l; i < mid; i++)
  {
    while (k <= h && nums[i] > (long long)2 * nums[k])
    {
      k++;
    }
    count += k - mid;
  }
  int i = l;
  while (ptr1 < mid && ptr2 <= h)
  {
    if (nums[ptr1] > nums[ptr2])
    {
      tmp[i] = nums[ptr2];
      int j = ptr1;
      ptr2++;
    }
    else
    {
      tmp[i] = nums[ptr1];
      ptr1++;
    }
    i++;
  }
  while (ptr1 < mid)
  {
    tmp[i] = nums[ptr1];
    ptr1++;
    i++;
  }
  while (ptr2 <= h)
  {
    tmp[i] = nums[ptr2];
    ptr2++;
    i++;
  }
  for (int j = l; j < i; j++)
    nums[j] = tmp[j];
  return count;
}

int mSort(vector<int> &nums, vector<int> &tmp, int l, int h)
{
  int mid = l + (h - l) / 2;
  int count = 0;
  if (l < h)
  {
    count += mSort(nums, tmp, l, mid);
    count += mSort(nums, tmp, mid + 1, h);
    count += merge(nums, tmp, l, mid + 1, h);
  }
  return count;
}

int reversePairs(vector<int> &nums)
{
  vector<int> tmp(nums.size(), 0);
  return mSort(nums, tmp, 0, nums.size() - 1);
}