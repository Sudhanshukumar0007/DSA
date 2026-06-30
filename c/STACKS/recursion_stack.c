#include<stdio.h>
int facTR(int n,int a){
    if(n==0) return a;
    else {
        return facTR(n-1,n*a);
    }

}

int fact(int n){
    return facTR(n,1);
}
void main(){
    int n;
    printf("Enter an integer : ");
    scanf("%d",&n);
    if(n<0){
        printf("INvalid integer! it should be greater or equal to 0.\n");
        return ;
    }
   printf("Factorial of %d is :%d",n,fact(n));

}