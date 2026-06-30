#include<bits/stdc++.h>
using namespace std;
struct Item{
    double value,weight;
};
int main(){
    int n;
    cin>>n;
    int capacity;
    cin>>capacity;
    vector<Item>items(n);
    for(int i=0;i<n;i++){
        cin>>items[i].value>>items[i].weight;
    }
    sort(items.begin(),items.end(),[](Item a,Item b){
        return (a.value/a.weight)>(b.value/b.weight);
    });

    double total_value = 0.0;
    int remaining = capacity;
    for(int i=0;i<n;i++){
        if(items[i].weight <= remaining){
            total_value += items[i].value;
            remaining -= items[i].weight;
        }
        else{
            total_value += (items[i].value/items[i].weight)*remaining;
            remaining = 0;
            break;
        }
    }
    cout<<fixed<<setprecision(6)<<total_value<<endl;
    return 0;
}