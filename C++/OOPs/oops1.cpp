#include<iostream>
#include"Hero.cpp"//in this way we can use class made in other folder and it gets included in this folder
using namespace std;
int main(){
    Hero h1;
    cout<<sizeof(h1);
    return 0;
}