class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        rows = [""] * numRows
        current_row, going_down = 0, False

        for c in s:
            rows[current_row] += c
            if current_row in (0, numRows - 1):
                going_down = not going_down
            current_row += 1 if going_down else -1
        return "".join(rows[i] for i in range(1, numRows - 1))
