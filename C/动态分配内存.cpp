#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int i = 0,j=0;
	char t[] = "abcdefg", s[] = "klfdsg";
	char* p;
	p = (char *)malloc(sizeof(strlen(t)+strlen(s)+1));
	if((p = (char *)malloc(sizeof(strlen(t)+strlen(s)+1))) == NULL){
		printf("ÄÚ´æ·ÖÅä´íÎó\n");
		exit(1);
	}
	while((p[i] = t[i])!= '\0'){
		i++;
	}
	while((p[i+j] = s[j])!= '\0'){
		j++;
	}
	printf("%s\n", p);
	p = p+1;
	printf("%s\n", p);
	printf("%c", p[-1]);
	return  0; 
} 
