// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>>&grid,int i,int j){
    int m = grid.size();
    int n = grid[0].size();
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0')
        return;
    grid[i][j]='0';
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}
int NumberOfIslands(vector<vector<char>>&grid){
    int m=grid.size();
    int n=grid[0].size();
    int count = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                count++;
                dfs(grid,i,j);
            }
        }
    }
    return count;
}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<char>>grid(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            char x;
            cin>>x;
            grid[i][j]=x;
        }
    }
    cout<<"Number of islands : "<<NumberOfIslands(grid);
    return 0;
}