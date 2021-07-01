#include <bits/stdc++.h>
using namespace std;

// Instead of Hash set we use Bool Array

// time-->O(N)          space-->O(N)

int lengthOfLongestSubstring(string s)
{
  vector<bool> map(256, false);
  int len = 0;
  int maxLen = 0;
  int j = 0;
  for (int i = 0; i < s.size(); i++)
  {
    char c = s[i];
    if (map[c])
    {
      while (map[c])
      {
        map[s[j]] = false;
        j++;
      }
      len = i - j;
    }
    map[c] = true;
    len++;
    maxLen = max(len, maxLen);
  }
  return maxLen;
}