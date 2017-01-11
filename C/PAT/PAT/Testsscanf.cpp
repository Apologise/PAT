#include<cstdio>

int main(){
	int n = 12;
	double db = 3.1421;
	char str[100],str2[100] = "good";
	sprintf(str,"%d:%.2f,%s",n,db,str2);
	printf("%s",str);
	/*char str[100] = "2048:3.14,hello",str2[100];
	sscanf(str,"%d:%lf,%s",&n,&db,str2);
	printf("n = %d, db = %.2f,str = %s\n",n,db,  str2);*/
	/*sscanf(str,"%d",&n);
	printf("%d\n",n);*/
}