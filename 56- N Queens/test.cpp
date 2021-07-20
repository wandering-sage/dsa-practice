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

bool isSafe(int i, int j, vector<string> &ar)
{
  // check behind i.e. same i
  for (int k = j - 1; k > -1; k--)
  {
    if (ar[i][k] == 'Q')
      return false;
  }
  // check upper diagonal
  for (int k = i - 1, l = j - 1; k > -1 && l > -1; k--, l--)
  {
    if (ar[k][l] == 'Q')
      return false;
  }
  // check lower diagonal
  for (int k = i + 1, l = j - 1; k < ar[0].size() && l > -1; k++, l--)
  {
    if (ar[k][l] == 'Q')
      return false;
  }
  return true;
}
void placeQueens(int i, int n, vector<string> &ar, vector<vector<string>> &ans)
{
  if (i == n)
  {
    ans.push_back(ar);
    return;
  }
  for (int j = 0; j < n; j++)
  {
    if (isSafe(j, i, ar))
    {
      ar[j][i] = 'Q';
      placeQueens(i + 1, n, ar, ans);
      ar[j][i] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n)
{
  vector<vector<string>> ans;
  string s(n, '.');
  vector<string> board(n, s);
  placeQueens(0, n, board, ans);
  return ans;
}

void solve()
{
  auto ans = solveNQueens(4);
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