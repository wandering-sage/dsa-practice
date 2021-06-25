#include <bits/stdc++.h>
using namespace std;

// Using Gap Meathod and 2 pointers

// time-->O(N*logN)          space-->O(1)

void merge(int arr1[], int arr2[], int n, int m)
{
  int gap = n + m;
  while (gap != 1)
  {
    gap = ceil((float)gap / 2);
    int ptr1 = 0;
    int ptr2 = gap;
    bool inSecond = false;
    bool bothInSecond = false;
    while (true)
    {
      if (!inSecond && ptr2 >= n)
      {
        ptr2 -= n;
        inSecond = true;
      }
      if (!bothInSecond && ptr1 >= n)
      {
        ptr1 -= n;
        bothInSecond = true;
      }
      if (inSecond && ptr2 >= m)
        break;
      if (!bothInSecond && inSecond && arr1[ptr1] > arr2[ptr2])
        swap(arr1[ptr1], arr2[ptr2]);
      if (!inSecond && arr1[ptr1] > arr1[ptr2])
        swap(arr1[ptr1], arr1[ptr2]);
      if (bothInSecond && arr2[ptr1] > arr2[ptr2])
        swap(arr2[ptr1], arr2[ptr2]);
      ptr1++;
      ptr2++;
    }
  }
}