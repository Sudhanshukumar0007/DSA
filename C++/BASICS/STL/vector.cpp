#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    cout << "vector size -> " << v.size() << endl;

    cout << "Enter elements of the array\n";
    for(int i = 0; i < 5; i++){
        int temp;
        cin >> temp;
        v.push_back(temp); 
    }

    cout << "vector size -> " << v.size() << endl;

    cout << "Given array\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    cout<<"capacity-->"<<v.capacity()<<endl;
    cout<<"Element at index 2-->"<<v.at(2)<<endl;
    cout<<"First element-->"<<v.front()<<endl;
    cout<<"Last element-->"<<v.back()<<endl;
    v.pop_back();
    cout<<"Vector after pop\n";
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;
    // TO clear the vector making its size zero
    v.clear();
    return 0;
}
