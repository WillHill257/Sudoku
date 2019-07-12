from array import *

ROWS = 9
# use the convention of an empty cell being 0

def isCompleted(grid):
    for r in range(ROWS):
        for c in range(ROWS):
            if grid[r][c] == 0: 
                return False
    return True

def findEmptyCell(grid): #returns the row and col of an empty cell
    for r in range(ROWS):
        for c in range(ROWS):
            if grid[r][c] == 0:
                return r, c 
    return -1, -1

def isValid(grid, digit, row, col):
    #check row and col
    for i in range(ROWS):
        if (grid[row][i] == digit) or (grid[i][col] == digit):
            return False
    
    #check block
    lRow = (row//3)*3
    lCol = (col//3)*3
    for r in range(lRow, lRow + 3):
        for c in range(lCol, lCol + 3):
            if grid[r][c] == digit:
                return False
    return True

def solve(grid):
    if isCompleted(grid):
        return True
    row, col = findEmptyCell(grid)
    for i in range(1, 10):
        if isValid(grid, i, row, col):
            grid[row][col] = i
            if solve(grid):
                return True
            grid[row][col] = 0
    return False
    

#main
print("Please enter the sudoku grid with empty cells having values of zero and all values space-separated")
grid = [[0 for x in range(ROWS)] for y in range(ROWS)] 
for r in range(ROWS):
        grid[r] = list(map(int, input().split()))

if solve(grid):
    for row in grid:
        for col in row:
            print(str(col) + " ", end='')
        print()
else:
    print("This puzzle does not have a solution")