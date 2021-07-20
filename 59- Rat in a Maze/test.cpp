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

void solve(int i, int j, int n, vector<vector<int>> &m, vector<string> &ans, string &str, vector<vector<bool>> &vis)
{
  if (i == n - 1 && j == n - 1)
  {
    ans.push_back(str);
    return;
  }
  if (i + 1 < n && !vis[i + 1][j] && m[i + 1][j] == 1)
  {
    str = str + "D";
    vis[i][j] = true;
    solve(i + 1, j, n, m, ans, str, vis);
    vis[i][j] = false;
    str = str.substr(0, str.size() - 1);
  }
  if (j - 1 > -1 && !vis[i][j - 1] && m[i][j - 1] == 1)
  {
    str = str + "L";
    vis[i][j] = true;
    solve(i, j - 1, n, m, ans, str, vis);
    vis[i][j] = false;
    str = str.substr(0, str.size() - 1);
  }
  if (j + 1 < n && !vis[i][j + 1] && m[i][j + 1] == 1)
  {
    str = str + "R";
    vis[i][j] = true;
    solve(i, j + 1, n, m, ans, str, vis);
    vis[i][j] = false;
    str = str.substr(0, str.size() - 1);
  }
  if (i - 1 > -1 && !vis[i - 1][j] && m[i - 1][j] == 1)
  {
    str = str + "U";
    vis[i][j] = true;
    solve(i - 1, j, n, m, ans, str, vis);
    vis[i][j] = false;
    str = str.substr(0, str.size() - 1);
  }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
  vector<vector<bool>> vis(n, vector<bool>(n, false));
  vector<string> ans;
  string str = "";
  solve(0, 0, n, m, ans, str, vis);
  return ans;
}

void solve()
{
  vector<vector<int>> board{
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 0},
      {0, 1, 1, 1}};

  findPath(board, 4);
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