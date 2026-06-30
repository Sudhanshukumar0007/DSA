#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout<<binary_search(v.begin(),v.end(),5)<<endl;
    cout<<"Finding 4-->"<<binary_search(v.begin(),v.end(),4)<<endl;
    cout<<"lower bound-->"<<lower_bound(v.begin(),v.end(),4)-v.begin()<<endl;
    cout<<"Upper bound-->"<<upper_bound(v.begin(),v.end(),4)-v.begin()<<endl;
    int a=3;
    int b=5;

    cout<<"max->"<<max(a,b)<<endl;
    swap(a,b);
    cout<<"A and b are respectively   "<<a<<"   "<<b<<endl;
    string abcd= "abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<"string->>"<<abcd<<endl;
    rotate(v.begin(),v.begin()+1,v.end());
    cout<<"After rotate\n";
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;
    return 0;
}