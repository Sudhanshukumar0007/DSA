#include<bits/stdc++.h>
using namespace std;
bool isSafe(int row,int col,vector<int>board){
    for(int prevCol=0;prevCol<col;prevCol++){
        int prevRow = board[prevCol];

        if(prevRow==row) return false;
        if(abs(prevRow-row)==abs(prevCol-col)) return false;
    }
    return true;
}
void solveQueen(int col,int n,vector<vector<int>>&result,vector<int>&board){
    if(col==n){
        result.push_back(board);
        return;
    }
    for(int row = 0;row<n;row++){
        if(isSafe(row,col,board)){
            board[col] = row;
            solveQueen(col+1,n,result,board);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>result;
    vector<int>board(n);
    solveQueen(0,n,result,board);
    if(result.empty()){
        cout<<-1<<endl;
    }else{
        for(auto &config:result){
            for(int i=0;i<n;i++){
                cout<<config[i]<<(i==n-1 ? "":" ");
            }
            cout<<"\n";
        }
    }
    return 0;
}