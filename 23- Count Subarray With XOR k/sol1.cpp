#include <bits/stdc++.h>
using namespace std;

// Using Prefix Xor and Hashing

// time-->O(N)          space-->O(N)

int XorCount(vector<int> A, int k)
{
  unordered_map<int, int> map;
  int Xor = 0;
  int cnt = 0;
  map[0] = 1;
  for (int i = 0; i < A.size(); i++)
  {
    Xor ^= A[i];
    map[Xor]++;
    if (map.find(Xor ^ k) != map.end())
    {
      cnt += map[Xor ^ k];
    }
  }
  return cnt;
}