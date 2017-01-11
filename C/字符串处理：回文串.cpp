#include<cstdio>
#include<cstring>

bool judge(char str[]){
	int len = strlen(str);
	for(int i = 0; i < len / 2; ++i){
		if(str[i] != str[len - i - 1]){
			return false;
		}
	}
	return true;
}

int main(){
	char str[255];
	while(gets(str)){
		if(judge(str)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}