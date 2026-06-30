#include<stdio.h>
void Merge(int a[],int b[],int M[]){
   int i=0,j=0,k=0;
   while(i<5 && j<7){
    if(a[i]>b[j]){
        M[k]=b[j];
        j++;
    }
    else{
        M[k]=a[i];
        i++;
    }
    k++;
   }
   while(i<5){
    M[k]=a[i];
    i++;
    k++;
   }
   while(j<7){
    M[k]=b[j];
    j++;
    k++;
   }
}
int main(){
    int a[5]={11,21,32,44,55};
    int b[7]={12,22,31,43,54,58,60};
    int mergedArray[12];
    Merge(a,b,mergedArray);
    printf("Merged Array\n");
    for(int i=0;i<12;i++){
        printf("%d ",mergedArray[i]);
    }
    
   
    return 0;
}