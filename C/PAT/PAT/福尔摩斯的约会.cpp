#include<stdio.h>

char* day[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
	char s[4][100];
	int n;
	for(int i = 0; i < 4; ++i){
		scanf("%s", s[i]);
	}
	//Test:测试输入数据
	/*for(int i = 0; i < 4; ++i){
		printf("%s ",s[i]);
	}*/

	//检测第一次出现相同的大写字母（注意是第一串和第二串）
	//DAY
	int DAY,i,j,flag = 0;
	for(i = 0; s[0][i] != '\0'; ++i){
		if(flag){break;}
		for(j = 0; s[1][j] != '\0'; ++j){
			if(s[0][i] >= 'A' && s[0][i] <= 'Z' && s[0][i] == s[1][j]){
				flag = 1;
				DAY = s[0][i] - 'A';
				break;
			}
		}
	}

	//HOUR
	int HOUR = 0;
	int k = j; 
	flag = 0;//flag归0
	for(; s[0][i] != '\0'; ++i){
		if(flag){break;}
		for(j = k+1; s[1][j] != '\0'; ++j){
			if(s[0][i] >= 'A' && s[0][i] <= 'Z' && s[0][i] == s[1][j]){
				flag = 1;
				HOUR = s[0][i] - 'A'+10;
				
				break;
			}else if(s[0][i] >= '0' && s[0][i] <= '9' && s[0][i] == s[1][j]){
				flag = 1;
				HOUR = s[0][i] - '0';
				
				break;
			}
		}
	}

	//MINUTE
	int MINUTE;
	flag = 0;
	for( j = 0; s[3][j] != '\0' && s[3][j] != '\0'; ++j){
			if((s[2][j] <= 'Z' && s[2][j] >= 'A')||
				(s[2][j] >= 'a' && s[2][j] <= 'z') && s[2][j] == s[3][j]){
				flag = 1;
				MINUTE = j;	
				break;
		}
	}
	if(MINUTE >= 60){
		HOUR = (HOUR+MINUTE/60)%24;
		MINUTE = MINUTE%60;
	}
	
	//Test:DAY
	/*printf("%s",day[DAY]);*/
	//Test:HOUR
	/*printf("%d",HOUR);*/

	//Test Result
	printf("%s ",day[DAY]);
	if(HOUR <= 9){
		printf("0%d:",HOUR);
	}else{
		printf("%d:",HOUR);
	}

	if(MINUTE <= 9){
		printf("0%d",MINUTE);
	}else{
		printf("%d",MINUTE);
	}

	/*printf("%s %02d:%02d",day[DAY],HOUR,MINUTE);*/
}