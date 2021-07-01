#include <bits/stdc++.h>
using namespace std;

// Using Sliding window and HashSet

// time-->O(N)          space-->O(N)

int lengthOfLongestSubstring(string s)
{
  set<char> map;
  int len = 0;
  int maxLen = 0;
  int j = 0;
  for (int i = 0; i < s.size(); i++)
  {
    char c = s[i];
    if (map.find(c) != map.end())
    {
      while (map.find(c) != map.end())
      {
        map.erase(map.find(s[j]));
        j++;
      }
      len = i - j;
    }
    map.insert(c);
    len++;
    maxLen = max(len, maxLen);
  }
  return len;
}