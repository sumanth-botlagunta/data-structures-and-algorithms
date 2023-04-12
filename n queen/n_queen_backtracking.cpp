#include <bits/stdc++.h>
using namespace std;

void backtrack(int row, vector<vector<string>> &ans, vector<string> &board, set<int> &columns, set<int> &positive_diagonal, set<int> &negative_diagonal){
  if(row == board.size()){
    ans.push_back(board);
    return;
  }
  
  for(int col = 0; col < board.size(); col++){
    if(columns.find(col) != columns.end())
      continue;
    int positive = row + col;
    if(positive_diagonal.find(positive) != positive_diagonal.end())
      continue;
    int negative = row - col;
    if(negative_diagonal.find(negative) != negative_diagonal.end())
      continue;
    
    board[row][col] = 'Q';
    columns.insert(col);
    positive_diagonal.insert(positive);
    negative_diagonal.insert(negative);
    
    backtrack(row + 1, ans, board, columns, positive_diagonal, negative_diagonal);
    
    board[row][col] = '.';
    columns.erase(col);
    positive_diagonal.erase(positive);
    negative_diagonal.erase(negative);
  }
}

vector<vector<string>> solveNQueens(int n){
  vector<vector<string>> ans;
  vector<string> board(n, string(n, '.'));
  set<int> columns, positive_diagonal, negative_diagonal;
  backtrack(0, ans, board, columns, positive_diagonal, negative_diagonal);
  return ans;
}

int main(){
  int n;
  cin >> n;
  vector<vector<string>> ans = solveNQueens(n);
  for(auto &board : ans){
    for(auto &row : board)
      cout << row << endl;
    cout << endl;
  }
  return 0;
}
