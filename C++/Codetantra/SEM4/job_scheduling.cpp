#include<bits/stdc++.h>
using namespace std;
struct Job{
    int id,deadline,profit;
};
int main(){
    int n;
    cin>>n;
    vector<Job>jobs(n);
    for(int i=0;i<n;i++){
        cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
    }
    int max_deadline = 0;
    sort(jobs.begin(),jobs.end(),[](Job a, Job b){
        return a.profit>b.profit;
    });
    for(int i=0;i<n;i++){
        max_deadline = max(max_deadline,jobs[i].deadline);
    }
    vector<int>time_slot(max_deadline,-1);
    int max_profit = 0;
    int count_jobs = 0;
    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline-1;j>=0;j--){
            if(time_slot[j]==-1){
                time_slot[j] = jobs[i].id;
                max_profit+=jobs[i].profit;
                count_jobs++;
                break;
            }
        }
    }
    cout<<"Maximum profit: "<<max_profit<<endl;
    cout<<"Number of jobs done: "<<count_jobs<<endl;
    return 0;
}