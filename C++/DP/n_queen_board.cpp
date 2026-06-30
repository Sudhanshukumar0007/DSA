#include<bits/stdc++.h>
using namespace std;

void printBoard(int n, const vector<vector<int>>& board){
    for(int i = 0; i < n; i++){
        cout << "[";
        for(int j = 0; j < n; j++){
            cout << board[i][j];
            if(j < n - 1) cout << " "; // Matching standard output format
        }
        cout << "]" << endl;
    }
}

bool isSafe(int row, int col, int n, vector<vector<int>>& board){
    // 1. Check this column for queens in previous rows
    for(int i = 0; i < row; i++){
        if(board[i][col] == 1) return false;
    }

    // 2. Check upper-left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 1) return false;
    }

    // 3. Check upper-right diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 1) return false;
    }

    return true;
}

bool solveQueens(int row, int n, vector<vector<int>>& board){
    if(row == n) return true;

    for(int col = 0; col < n; col++){
        if(isSafe(row, col, n, board)){
            board[row][col] = 1; // Place queen
            
            if(solveQueens(row + 1, n, board)) return true;
            
            board[row][col] = 0; // Backtrack
        }
    }
    return false;
}

int main(){
    int n;
    if(!(cin >> n)) return 0;
    
    // Check for N < 4 (except 1) where no solution exists
    if (n > 1 && n < 4) {
        // Depending on problem requirements, you might print "No solution"
        return 0;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));
    if(solveQueens(0, n, board)){
        printBoard(n, board);
    }
    return 0;
}