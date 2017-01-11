#include<stdio.h>
#include<math.h>

int isPrime(int n){
    if(n==2){
        return 1;
    }else{
        for(int i = 2; i<=sqrt((double)n);i++){
            if(n%i==0){
                return 0;    
            }
        }
        return 1;
    }
}

int main(){
    /*
    int N,M, count = 0;
    scanf("%d %d", &N, &M);
    for(int i = 2; count <= M; i++){

    }
    */
	int M,N;
	scanf("%d %d",&N,&M);
    int count = 0;
	int mark=0;
    for(int i = 2; ;i++){
        if(isPrime(i)){
			count++;
			if(count>M){break;}
			if(count>=N&&count<=M){
				mark++;
				if(mark%10!=0){
					if(count!=M){
						printf("%d ",i);}else{
							printf("%d",i);
						}
				}else{
				printf("%d\n",i);}
			}
			
			
            
}
}

}