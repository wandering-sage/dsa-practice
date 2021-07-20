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

int NthRoot(int n, int m)
{
  if (n == 1)
    return m;
  double high = m, low = 0, mid;
  double eps = 0.1;
  long double p, i;
  while ((high - low) > eps)
  {
    mid = (low + high) / 2.0;
    p = 1;
    i = 0;
    while (i < n)
    {
      i++;
      p *= mid;
      if (m < p)
        break;
    }
    if (m == p)
    {
      return mid;
    }
    if (p < m)
      low = mid;
    else
      high = mid;
  }
  int x = round(mid);
  p = 1;
  for (int i = 0; i < n; i++)
    p *= x;
  if (p == m)
    return x;
  return -1;
}

void solve()
{
  cout << NthRoot(3, 27);
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