#include<stdio.h>
#include<cstring>

int main(){
	/*char str1[20];
	char str2[5][20];

	gets(str1);
	for(int i = 0; i < 3; ++i){
		gets(str2[i]);
	}
	puts(str1);
	for(int i = 0; i < 3; ++i){
		puts(str2[i]);
	}
*/

	/*char str[15];
	int i;
	for(i = 0; i < 3; ++i){
		str[i] = getchar();
	}
	str[i] = 0;
	puts(str);
	return 0;*/
	char str[10];
	scanf("%s", str);
	printf("%s\n",str);
	char str2[10];
	gets(str2);
	printf("%s",str2);

	return 0;
}