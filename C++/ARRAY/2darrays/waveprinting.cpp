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
//Wave printing of a 2D array 
void wave_print(vector<vector<int>> &arr){
    int m=arr.size();
    int n=arr[0].size();
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<m;j++){
                cout<<arr[j][i]<<" ";
            }
        }
        else{
            for(int j=m-1;j>=0;j--){
                cout<<arr[j][i]<<" ";
            }
        }
    }
}
//Spiral printing of an array
void Spiral_print(vector<vector<int>> &arr){
    int top=0;
    int bottom=arr.size()-1;
    int left=0;
    int right=arr[0].size()-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            cout<<arr[top][i]<<" ";
        }
        top++;
        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<<" ";
        }right--;
        for(int i=right;i>=left;i--){
            cout<<arr[bottom][i]<<" ";
        }bottom--;
        for(int i=bottom;i>=top;i--){
            cout<<arr[i][left]<<" ";
        }left++;
    }

}
int main() {
    int m, n;
    vector<vector<int>> arr1;

    inputDimensions(m, n);
    inputArray(arr1, m, n);
    displayArray(arr1);
    // wave_print(arr1);
    Spiral_print(arr1);
    return 0;
}
