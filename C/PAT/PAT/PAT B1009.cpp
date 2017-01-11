#include<cstdio>
#include<cstring>

int main(){
	char str[90];
	char str1[90][90];
	gets(str);
	int len = strlen(str);
	int index = 0;
	int i,j = 0;
	for(i = 0; i < len; ++i){

		if(str[i] != ' '){
			str1[index][j++] = str[i];
		}else{
			str1[index][j] = '\0';
            index ++;
			j = 0;
		}
	}
	str1[index][j] = 0;
	for(int i = index; i > 0; i--){
			printf("%s ",str1[i]);
	}
	printf("%s",str1[0]);
}