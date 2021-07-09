#include <bits/stdc++.h>
using namespace std;

// Using Recursion

// time-->O(2^N)          space-->O(2^N)

bool ispalindrome(string &s, int i, int j)
{
  while (i < j)
  {
    if (s[i] != s[j])
      return false;
    i++;
    j--;
  }
  return true;
}

void getPartitions(int idx, string &s, vector<string> &ds, vector<vector<string>> &ans)
{
  if (idx == s.size())
  {
    ans.push_back(ds);
    return;
  }
  int i = idx + 1;
  while (i <= s.size())
  {
    if (ispalindrome(s, idx, i - 1))
    {
      ds.push_back(s.substr(idx, i - idx));
      getPartitions(i, s, ds, ans);
      ds.pop_back();
    }
    i++;
  }
}

vector<vector<string>> partition(string s)
{
  vector<string> ds;
  vector<vector<string>> ans;
  getPartitions(0, s, ds, ans);
  return ans;
}