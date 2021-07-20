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

bool canFill(int i, int j, char d, vector<vector<char>> &board)
{
  // check row
  for (int k = 0; k < 9; k++)
  {
    if (board[i][k] == d)
      return false;
  }

  // check column
  for (int k = 0; k < 9; k++)
  {
    if (board[k][j] == d)
      return false;
  }

  // check 3x3 cell
  int k = i - i % 3;
  int l = j - j % 3;
  for (int x = k; x < k + 3; x++)
  {
    for (int y = l; y < l + 3; y++)
    {
      if (board[x][y] == d)
        return false;
    }
  }
  return true;
}
void btSudoku(int i, int j, vector<vector<char>> &board, bool &solved)
{
  if (j > 8)
  {
    j %= 9;
    i++;
  }
  if (i == 9)
  {
    solved = true;
    return;
  }
  if (board[i][j] != '.')
  {
    btSudoku(i, j + 1, board, solved);
    return;
  }
  for (char d = '1'; d <= '9'; d++)
  {
    if (canFill(i, j, d, board))
    {
      board[i][j] = d;
      btSudoku(i, j + 1, board, solved);
    }
    if (solved)
    {
      return;
    }
  }
  board[i][j] = '.';
}

void solveSudoku(vector<vector<char>> &board)
{
  bool solved = false;
  btSudoku(0, 0, board, solved);
}

void solve()
{
  vector<vector<char>> board{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  solveSudoku(board);
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