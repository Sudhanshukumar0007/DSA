#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);

    cout << "Stack elements (top to bottom):\n";
    stack<int> temp = stk;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }cout<<endl;

    cout<<"Size of the stack --> "<<stk.size()<<endl;
    cout<<"Empty or not -->"<<stk.empty()<<endl;
    cout<<"Top element -->"<<stk.top()<<endl;

    return 0;
}
