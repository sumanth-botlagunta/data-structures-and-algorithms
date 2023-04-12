from typing import List

def solveNQueens(self, n: int) -> List[List[str]]:
      board = [['.' for _ in range(n)] for _ in range(n)]
      column = set()
      positive_diagnol = set()
      negative_diagnol = set()
      result = []

      def backtrack(row):
        if row == n:
          result.append([''.join(row) for row in board])
          return 

        for col in range(n):
          if col in column or row + col in positive_diagnol or row - col in negative_diagnol:
            continue

          board[row][col] = 'Q'
          column.add(col)
          positive_diagnol.add(row + col)
          negative_diagnol.add(row - col)

          backtrack(row + 1)

          board[row][col] = '.'
          column.remove(col)
          positive_diagnol.remove(row + col)
          negative_diagnol.remove(row - col)
        
      backtrack(0)
      return result
