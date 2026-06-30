// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    int minutes = 0;
    while(true){
        bool changed = false;
        vector<vector<int>>copy = grid;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(copy[i][j]==1){

                    if((i>0 && copy[i-1][j]==2) || (i<m-1 && copy[i+1][j]==2) || (j>0 && copy[i][j-1]==2) || (j<n-1 && copy[i][j+1]==2)){
                        grid[i][j]=2;
                        changed = true;
                    }
                }
            }
        }
        if(!changed) break;
        minutes++;
    }
    for(auto&row:grid){
        for(int x:row){
            if(x==1) return -1;
        }
    }
    return minutes;
}
int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    cout << "Enter the grid values (0-empty, 1-fresh, 2-rotten):\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int result = orangesRotting(grid);

    cout << "\nMinimum minutes to rot all oranges: " << result << endl;

    return 0;
}
