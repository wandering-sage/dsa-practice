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

bool compareInterval(vector<int> i1, vector<int> i2)
{
  return (i1[0] < i2[0]);
}
// 1 73 2628 62196 1088430 15020334 170230452 629348605 442125958 82020786 324933029 497343702 569609113 749704286 784446923 352157878 26572299 912624773 394832610 37673337 401718012 585288313 747045099 786926083 222762663 796614822 547596588 175445907 788232565 326567767 345632724 543942166 588924092 34723867 452616317 390058181 356172524 356172524 390058181 452616317 34723867 588924092 543942166 345632724 326567767 788232565 175445907 547596588 796614822 222762663 786926083 747045099 585288313
void solve()
{
  int n = 74;
  vector<long long> ans;
  long long s;
  ans.push_back(1);
  for (int j = 1; j <= (n - 1) / 2; j++)
  {
    long long x = ((ans[j - 1] * (n - j)) / j);
    x %= 1000000007;
    ans.push_back(x);
  }
  int m = ans.size() - 1;
  for (int j = n % 2; j <= (n - 1) / 2; j++)
  {
    ans.push_back(ans[m - j]);
  }

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