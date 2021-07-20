#include <bits/stdc++.h>
using namespace std;

// Using Recursion

// time-->O(N*N!)          space-->O(N)

bool canFill(int i, int j, char d, vector<vector<char>> &board)
{
  for (int k = 0; k < 9; k++)
  {
    // check row
    if (board[i][k] == d)
      return false;

    // check column
    if (board[k][j] == d)
      return false;

    // check 3x3 cell
    if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == d)
      return false;
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