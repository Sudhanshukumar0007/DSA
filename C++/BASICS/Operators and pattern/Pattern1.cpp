#include<iostream>
using namespace std;
int main(){
    int num_of_lines;
    cout<<"Enter number of line:\n";
    cin>>num_of_lines;
    for(int i=0;i<num_of_lines;i++){
        for(int j=0;j<num_of_lines*2;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}