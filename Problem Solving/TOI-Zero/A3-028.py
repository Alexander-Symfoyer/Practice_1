def increment(board, i, j):
    if board[i][j] == "x":
        return
    current_count = int(board[i][j])
    current_count += 1
    board[i][j] = str(current_count)

rows, cols = [int(x) for x in input().split()]
num_bombs = int(input())

board = []
for i in range(rows):
    board.append(["0"] * cols)

for i in range(num_bombs):
    row, col = [int(x) for x in input().split()]
    board[row][col] = "x"

    if row >= 1:
        increment(board, row-1, col)
        if col >= 1:
            increment(board, row-1, col-1)
        if col < cols - 1:
            increment(board, row-1, col+1)
    
    if row < rows - 1:
        increment(board, row+1, col)
        if col >= 1:
            increment(board, row+1, col-1)
        if col < cols - 1:
            increment(board, row+1, col+1)

    if col >= 1:
        increment(board, row, col-1)
    if col < cols - 1:
        increment(board, row, col+1)

for i in range(rows):
    print(" ".join(board[i]))