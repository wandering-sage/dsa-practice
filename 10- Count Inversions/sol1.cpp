#include <bits/stdc++.h>
using namespace std;

// Using Merge Sort

// time-->O(N*logN)          space-->O(N)

#define ll long long

long long merge(ll arr[], ll tmp[], ll l, ll mid, ll r)
{
  ll inv = 0;
  ll ptr1 = l;
  ll ptr2 = mid;
  int i = l;
  while (ptr1 < mid && ptr2 <= r)
  {
    if (arr[ptr1] > arr[ptr2])
    {
      inv += mid - ptr1;
      tmp[i] = arr[ptr2];
      ptr2++;
    }
    else
    {
      tmp[i] = arr[ptr1];
      ptr1++;
    }
    i++;
  }
  while (ptr1 < mid)
  {
    tmp[i] = arr[ptr1];
    ptr1++;
    i++;
  }
  while (ptr2 <= r)
  {
    tmp[i] = arr[ptr2];
    ptr2++;
    i++;
  }
  for (ll j = l; j <= r; j++)
  {
    arr[j] = tmp[j];
  }
  return inv;
}

long long int mSort(ll arr[], ll tmp[], ll left, ll right)
{
  ll count = 0;
  ll mid = left + (right - left) / 2;
  if (left < right)
  {
    count += mSort(arr, tmp, left, mid);
    count += mSort(arr, tmp, mid + 1, right);
    count += merge(arr, tmp, left, mid + 1, right);
  }
  return count;
}

long long int inversionCount(ll arr[], ll N)
{
  ll tmp[N];
  return mSort(arr, tmp, 0, N - 1);
}
