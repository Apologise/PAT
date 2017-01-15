/*
Author:Apolo
Time : 2017-01-14
Problem Description：
Method；通过条件找数学规律 
*/
#include<cstdio>
#include<cstring>

int main(){
	int N;
	scanf("%d", &N);
	getchar();
	while(N--){
 		char str[110];
		gets(str);
		int numP = 0,numT = 0,other = 0;
		int locP, locT, len = strlen(str);
		for(int i = 0; i < len; ++i){
			if(str[i] == 'P'){
				numP++;
				locP = i;
			}else if(str[i] == 'T'){
				numT++;
				locT = i;
			}else if(str[i] != 'A'){
				other++;
			}
		}
		
		if(numP != 1 || numT != 1 || other >0 || locT - locP <= 1){
			printf("NO\n");
			continue;
		}
		
		int x,y,z;
		x = locP;
		y = locT - locP -1;
		z = len - locT - 1;
		if(z - x*(y -1) == x){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
} 