#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>start(n),end(n);
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    vector<pair<int,int>>activities(n);
    for(int i=0;i<n;i++){
        activities[i] = {end[i],start[i]};
    }
    sort(activities.begin(),activities.end());
    int count = 1;
    int last_selected = activities[0].first;
    for(int i=1;i<n;i++){
        if(activities[i].second>last_selected){
            count++;
            last_selected = activities[i].first;
        }
    }
    cout<<count<<endl;
}