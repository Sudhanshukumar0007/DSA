#include<iostream>
#include<vector>
using namespace std;

// Function to input array dimensions
void inputDimensions(int &m, int &n) {
    cout << "Enter rows and columns of the array\n";
    cin >> m >> n;
}

// Function to input elements of the array
void inputArray(vector<vector<int>> &arr, int m, int n) {
    cout << "Enter elements of array\n";
    arr.resize(m, vector<int>(n));  // Allocate memory dynamically
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
}

// Function to display the array
void displayArray(const vector<vector<int>> &arr) {
    cout << "Given array\n";
    for(const auto &row : arr){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//Spiral printing of an array
vector<vector<int>> Spiral_print(int row,int col,int rStart,int cStart){
    vector<vector<int>>result(row,vector<int>(col));
    int count=1;
    
    while(rStart<=row && cStart>=0){
        for(int i=cStart;i<col;i++){
        result[rStart][i]=count++;
        }
        rStart++;
        cStart--;
        for(int i=col-1;i>=cStart;i--){
            result[rStart][i]=count++;
        }
        for(int i=rStart;i>=0;i--){
            result[i][cStart]=count++;
        }cStart--,rStart++;
    }
    return result;
}
int main() {
    int m, n;
    vector<vector<int>> arr1;

    // inputDimensions(m, n);
    // inputArray(arr1, m, n);
    // displayArray(arr1);
    vector<vector<int>>result=Spiral_print(5,6,1,4);
    displayArray(result);
    return 0;
}
