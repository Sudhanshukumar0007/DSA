#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// We have to count the number of primes less than the number 
// we will use Sieve of Eratosthenes
int primeCount(int n){
    if(n<=1) return 0;
    vector<bool>prime(n+1,true);
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=false;
            }
        }
    }
    return count(prime.begin(),prime.end(),true); 
}
int main(){
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    int primes=primeCount(n);
    cout<<primes;
    return 0;
}