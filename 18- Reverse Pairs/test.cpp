#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

int merge(vector<int> &nums, vector<int> &tmp, int l, int mid, int h)
{
  int count = 0;
  int ptr1 = l;
  int ptr2 = mid;
  int i = l;
  while (ptr1 < mid && ptr2 <= h)
  {
    if (nums[ptr1] >= nums[ptr2])
    {
      tmp[i] = nums[ptr2];
      int j = ptr1;
      while (j < mid)
      {
        if (nums[j] > 2 * nums[ptr2])
        {
          count += mid - j;
          break;
        }
        j++;
      }
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

void solve()
{
  vi a = {2, 4, 1, 2147483647, 2147483646};
  cout << reversePairs(a);
  cout << "Hello";
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}