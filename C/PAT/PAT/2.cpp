#include<stdio.h>


int main(){
    int A[1000];
    int num;
    scanf("%d",&num);
    for(int i = 0; i < num; ++i){
    scanf("%d",&A[i]);
}
//ÇóA1
    int A1 = 0,A2=0,A3=0,A5=0,flag=1,count = 0;
    double A4 = 0,sum=0;
    for(int j = 0; j < num; ++j){
        if(A[j]%10 == 0){
            A1 += A[j];
}   

    if(A[j]%5==1){
        A2 +=flag*A[j];
        flag = (-1)*flag;
        
    }
    
    if(A[j]%5==2){
        A3++;
    }

    if(A[j]%5==3){
        count++;
        sum += A[j];
}

    if(A[j]%5==4){
        if(A5<A[j]){
            A5 = A[j];
}
}





}
if(A1 == 0){
        printf("%c ",'N');
}else{
        printf("%d ",A1);
}

if(A2 == 0){
        printf("%c ",'N');
}else{
        printf("%d ",A2);
}

if(A3 == 0){
        printf("%c ",'N');
}else{
        printf("%d ",A3);
}

A4 = sum/count;
if(count == 0){
        printf("%c ",'N');
}else{
        printf("%.1f ",A4);
}

if(A5 == 0){
        printf("%c",'N');
}else{
        printf("%d",A5);
}
    
  return 0;  
}