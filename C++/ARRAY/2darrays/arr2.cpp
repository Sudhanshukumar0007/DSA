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
bool is_present(vector<vector<int>> &arr,int target){
    for(auto row:arr){
        for(int val:row){
            if(target==val) return 1;
        }
    }
    return 0;
}
int main() {
    int m, n;
    vector<vector<int>> arr1;

    inputDimensions(m, n);
    inputArray(arr1, m, n);
    displayArray(arr1);
    int target;
    cout<<"Enter element to find\n";
    cin>>target;
    if(is_present(arr1,target)){
        cout<<"Yes Element found\n";
    }
    else{
        cout<<"Not found\n";
    }

    return 0;
}
