#include<iostream>
using namespace std;

void intialize_array(int **arr,int row,int col){
    cout<<"Enter elements of the array\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
}

void print_array(int **arr,int row,int col){
    cout<<"Given Matrix\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Sparse matrix creation - returns compact form and non-zero count by reference
int** Sparse_matrix(int **arr, int row, int col, int &nonzero_count) {
    int count_zero = 0;
    nonzero_count = 0;

    // Count non-zero elements
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] != 0)
                nonzero_count++;
            else
                count_zero++;
        }
    }

    // Allocate compact matrix
    int **compact = new int*[nonzero_count];
    for (int i = 0; i < nonzero_count; i++) {
        compact[i] = new int[3]; // row, col, value
    }

    // Fill compact matrix
    int index = 0;
    cout << "\nSparse matrix:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] != 0) {
                cout << "<" << i << ", " << j << ", " << arr[i][j] << ">\n";
                compact[index][0] = i;
                compact[index][1] = j;
                compact[index][2] = arr[i][j];
                index++;
            }
        }
    }

    cout << "\nStored Sparse Matrix (Compact Form):\n";
    cout << "Row Col Value\n";
    for (int i = 0; i < nonzero_count; i++) {
        cout << compact[i][0] << "   "
             << compact[i][1] << "   "
             << compact[i][2] << endl;
    }

    cout << "\nNumber of zeroes in the matrix: " << row * col - nonzero_count << endl;
    cout << "Number of non-zero elements: " << nonzero_count << endl;

    return compact;
}

void transpose_sparse(int **compact, int k) {
    // Allocate transpose of compact form (by swapping row & col)
    int **transpose = new int*[k];
    for(int i=0; i<k; i++) {
        transpose[i] = new int[3];
        transpose[i][0] = compact[i][1]; // new row = old col
        transpose[i][1] = compact[i][0]; // new col = old row
        transpose[i][2] = compact[i][2]; // value stays same
    }

    cout << "\nTransposed Sparse Matrix (Compact Form):\n";
    cout << "Row Col Value\n";
    for (int i = 0; i < k; i++) {
        cout << transpose[i][0] << "   "
             << transpose[i][1] << "   "
             << transpose[i][2] << endl;
    }

    // Free memory
    for (int i = 0; i < k; i++) {
        delete[] transpose[i];
    }
    delete[] transpose;
}

int main(){
    int row, col;
    cout << "Enter rows and columns: \n";
    cin >> row >> col;

    // Allocate memory dynamically
    int **arr = new int*[row];
    for(int i=0; i<row; i++) {
        arr[i] = new int[col];
    }

    intialize_array(arr, row, col);
    print_array(arr, row, col);

    int k = 0; // non-zero count
    int **compact = Sparse_matrix(arr, row, col, k);
    transpose_sparse(compact, k);

    // Free compact memory
    for(int i = 0; i < k; i++) {
        delete[] compact[i];
    }
    delete[] compact;

    // Free original matrix memory
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
