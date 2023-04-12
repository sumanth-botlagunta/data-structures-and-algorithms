/**
 * @param {number} n
 * @return {string[][]}
 */

var isValid = function (board, row, col) {
  for (var i = 0; i < board.length; i++) {
    if (board[i][col] === 'Q') {
      return false;
    }
  }
  for (var i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] === 'Q') {
      return false;
    }
  }
  for (var i = row - 1, j = col + 1; i >= 0 && j < board.length; i--, j++) {
    if (board[i][j] === 'Q') {
      return false;
    }
  }
  return true;
};

var backtracking = function (board, row, result) {
  if (row === board.length) {
    var temp = [];
    for (var i = 0; i < board.length; i++) {
      temp.push(board[i].join(''));
    }
    result.push(temp);
    return;
  }
  for (var i = 0; i < board.length; i++) {
    if (isValid(board, row, i)) {
      board[row][i] = 'Q';
      backtracking(board, row + 1, result);
      board[row][i] = '.';
    }
  }
};

var solveNQueens = function (n) {
  var result = [];
  var board = [];
  for (var i = 0; i < n; i++) {
    board[i] = [];
    for (var j = 0; j < n; j++) {
      board[i][j] = '.';
    }
  }
  backtracking(board, 0, result);

  return result;
};
