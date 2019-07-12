#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > vvi;

//use convention of empty cell being a zero

bool solve(vvi &grid);
bool isCompleted(const vvi &grid);
void findEmptyCell(const vvi &grid, int &row, int &col);
bool isValid(vvi &grid, int digit, int row, int col);

int main() {
    vvi grid;
    cout << "Please enter the sudoku grid with empty cells having values of zero and all values space-separated" << endl;

    for(int i = 0; i < 9; ++i){
        vector<int> temp;
        for(int j = 0; j < 9; ++j){
            int num;
            cin >> num;
            temp.push_back(num);
        }
        grid.push_back(temp);
    }

    if (solve(grid)){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        cout << "This puzzle does not have a solution" << endl;
    }

    return 0;
}

bool solve(vvi &grid){
    if (isCompleted(grid)) return true;
    int row, col;
    findEmptyCell(grid, row, col);
    for(int i = 1; i <= 9; ++i){
        if (isValid(grid, i, row, col)){
            grid[row][col] = i;
            if (solve(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void findEmptyCell(const vvi &grid, int &row, int &col){
    for(int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j){
            if (grid[i][j] == 0){
                row = i;
                col = j;
                return;
            }
        }
    }
}

bool isCompleted(const vvi &grid){
    int rows = grid.size(), cols;
    while(rows--){
        cols = grid[0].size();
        while(cols--){
            if (grid[rows][cols] == 0) return false;
        }
    }
    return true;
}

bool isValid(vvi &grid, int digit, int row, int col){
    //check row
    for (int i = 0; i < grid.size(); ++i){
        if (grid[row][i] == digit) return false;
    }
    //check col
    for (int i = 0; i < grid[row].size(); ++i){
        if (grid[i][col] == digit) return false;
    }
    //check block
    ++row; ++col;
    int rLow, cLow;
    if (row <= 3) rLow = 1;
    else if (row <= 6) rLow = 4;
    else rLow = 7;

    if (col <= 3) cLow = 1;
    else if (col <= 6) cLow = 4;
    else cLow = 7;

    for(int i = rLow; i <= rLow + 2; ++i){
        for(int j = cLow; j <= cLow + 2; ++j){
            if (grid[i - 1][j - 1] == digit){
                return false;
            }
        }
    }
    return true;
}