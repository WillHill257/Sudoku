import java.util.Scanner;

public class sudoku {
    static final int ROWS = 9;

    public static void main(String[] args) {

        //Use convention of an empty cell having a value of 0
        int[][] grid = new int[ROWS][ROWS];
        System.out.println("Please enter the sudoku grid with empty cells having values of zero and all values space-separated");

        Scanner input = new Scanner(System.in);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < ROWS; ++j) {
                grid[i][j] = input.nextInt();
            }
        }
        input.close();

        if (solve(grid)) {
            for (int[] row : grid) {
                for (int col : row) {
                    System.out.print(col + " ");
                }
                System.out.println();
            }
        } else {
            System.out.println("This puzzle does not have a solution");
        }
    }

    private static boolean solve(int grid[][]){
        if (isCompleted(grid)) return true;
        Cell pos = findEmptyCell(grid);
        for (int i = 1; i <= 9; ++i){
            if (isValid(grid, i, pos)) {
                grid[pos.row][pos.col] = i;
                if (solve(grid)){
                    return true;
                }
                grid[pos.row][pos.col] = 0;
            }
        }
        return false;
    }

    private static boolean isCompleted(int grid[][]) {
        for (int r = 0; r < ROWS; ++r){
            for (int c = 0; c < ROWS; ++c){
                if (grid[r][c] == 0){
                    return false;
                }
            }
        }
        return true;
    }

    private static Cell findEmptyCell(int grid[][]) {
        for (int r = 0; r < ROWS; ++r){
            for (int c = 0; c < ROWS; ++c){
                if (grid[r][c] == 0) {
                    return new Cell(r, c);
                }
            }
        }
        return new Cell(-1, -1);//invalid cell
    }

    private static boolean isValid(int grid[][], int digit, Cell pos) {
        //check row and col
        for (int i = 0; i < ROWS; ++i){
            if ((grid[pos.row][i] == digit) || (grid[i][pos.col] == digit)) return false;
        }
        //check block
        int lRow = (pos.row/3)*3, lCol = (pos.col/3)*3;
        for (int r = lRow; r < lRow + 3; ++r){
            for (int c = lCol; c < lCol + 3; ++c){
                if (grid[r][c] == digit) return false;
            }
        }
        return true;
    }
}

class Cell{
    public int row, col;

    Cell(int row, int col){
        this.row = row;
        this.col = col;
    }
}