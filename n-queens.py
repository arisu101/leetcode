class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        column = set()
        positive_diagonal = set()  # r + c
        negative_diagonal = set()  # r - c
        result = []
        board = [["."] * n for i in range(n)]

        def backtrack(r):
            if r == n:
                copy = ["".join(row) for row in board]
                result.append(copy)
                return

            for c in range(n):
                if (
                    c in column
                    or (r + c) in positive_diagonal
                    or (r - c) in negative_diagonal
                ):
                    continue
                column.add(c)
                positive_diagonal.add(r + c)
                negative_diagonal.add(r - c)
                board[r][c] = "Q"

                backtrack(r + 1)

                column.remove(c)
                positive_diagonal.remove(r + c)
                negative_diagonal.remove(r - c)
                board[r][c] = "."

        backtrack(0)
        return result


print(Solution().solveNQueens(1))
