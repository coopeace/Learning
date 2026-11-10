from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = {i:set() for i in range(9)}
        cols = {i:set() for i in range(9)}
        boxes = {(i,j):set() for i in range(3) for j in range(3)}

        for r in range(9):
            for c in range(9):
                pointer = board[r][c]
                
                # skip "."
                if pointer == ".":
                    continue

                # check for rows duplicates
                if pointer in rows[r]:
                    return False
                else:
                    rows[r].add(pointer)

                # check for cols duplicates
                if pointer in cols[c]:
                    return False
                else:
                    cols[c].add(pointer)

                # check for boxes duplicates
                box_coordinate = (r//3,c//3)
                if pointer in boxes[box_coordinate]:
                    return False
                else:
                    boxes[box_coordinate].add(pointer)
        return True

if __name__ == "__main__":
    board = [
 ["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","8",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]
  ]

    board1 = [
 ["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","1",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]
  ]
    print(Solution().isValidSudoku(board))
    print(Solution().isValidSudoku(board1))
