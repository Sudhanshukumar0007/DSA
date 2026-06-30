#include<iostream>
using namespace std;

// Function to input array dimensions
void inputDimensions(int &m, int &n) {
    cout << "Enter rows and columns of the array\n";
    cin >> m >> n;
}

// Function to input elements of the array
void inputArray(int arr[][100], int m, int n) {
    cout << "Enter elements of array\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
}

// Function to display the array
void displayArray(int arr[][100], int m, int n) {
    cout << "Given array\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    int m, n;
    int arr1[100][100]; // Using fixed size for portability

    inputDimensions(m, n);
    inputArray(arr1, m, n);
    displayArray(arr1, m, n);
    cout<<"Row wise sum of the 2D array\n";
    int largest_sum=0;
    int largest_sum_row=0;
    for(int i=0;i<m;i++){
        cout<<"Sum of row-->"<<i<<endl;
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=arr1[i][j];
        }
        cout<<sum<<endl;
        if(sum>largest_sum){
            largest_sum=sum;
            largest_sum_row=i;
        }
    }
    cout<<"Largest row sum --> "<<largest_sum<<"of the row "<<largest_sum_row;
    return 0;
}
