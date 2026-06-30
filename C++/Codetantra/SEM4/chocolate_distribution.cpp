#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    vector<int>chocolates(N);
    for(int i=0;i<N;i++){
        cin>>chocolates[i];
    }
    if(M>N){
        cout<<-1<<endl;
        return 0;
    }
    sort(chocolates.begin(),chocolates.end());
    int min_diff = INT_MAX;
    for(int i=0;i<=N-M;i++){
        int diff = chocolates[i+M-1] - chocolates[i];
        min_diff = min(min_diff,diff);

    }
    cout<<min_diff<<endl;
    return 0;
}