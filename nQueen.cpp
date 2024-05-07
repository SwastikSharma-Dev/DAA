#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {

  vector<int> temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp.push_back(board[i][j]);
    }
  }
  ans.push_back(temp);
}
bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
  int x = row;
  int y = col;
  while (y >= 0) {
    if (board[x][y] == 1)
      return false;
    y--;
  }
  x = row;
  y = col;
  while (x >= 0 && y >= 0) {
    if (board[x][y] == 1)
      return false;
    y--;
    x--;
  }
  x = row;
  y = col;
  while (x < n && y >= 0) {
    if (board[x][y] == 1)
      return false;

    y--;
    x++;
  }
  return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board,
           int n) {

  if (col == n) {
    addSolution(ans, board, n);
    return;
  }
  for (int row = 0; row < n; row++) {
    if (isSafe(row, col, board, n)) {
      board[row][col] = 1;
      solve(col + 1, ans, board, n);
      board[row][col] = 0;
    }
  }
}

vector<vector<int>> solveNQueens(int n) {
  vector<vector<int>> board(n, vector<int>(n, 0));
  vector<vector<int>> ans;

  solve(0, ans, board, n);
  return ans;
}
 int count=1;
int main() {
  int n;
  cout << "Enter the Size of the Board: ";
  cin >> n;

  vector<vector<int>> ans;
  ans= solveNQueens(n);
  cout<<endl<<"The Possible Combinations of Boards are: "<<endl<<endl<<"-----------"<<endl;
  for(int row=0; row<ans.size(); row++)

    {
       for(int col=0; col<ans[row].size(); col++)
        {
            if(::count<=4)
            {
                if(::count==1)
                {
                    cout<<"| "<<ans[row][col]<<" ";
                    ::count++;
                }
                else if(::count==4)
                {
                    cout<<ans[row][col]<<" |";
                    ::count++;               
                }
                else
                {
                    cout<<ans[row][col]<<" ";
                    ::count++;
                }
            }
            else
            {
                ::count=2;
                cout<<endl;
                cout<<"| "<<ans[row][col]<<" ";
            }
        }
      cout<<endl<<"-----------";
    }
}
