#include<stdio.h>

int main(){
	int a, b, c,flag = 0;
	/*
		temp������Ŵ�����ݣ�tot��ʾ����ָ��
	*/
	int temp[1001], index = 0;
	
	scanf("%d%d", &a, &b);
	c = a + b;
	if( c < 0){
		flag = -1;
		c = -c;
	}else if(c == 0){
		printf("0");
	}
	
	while( c != 0 ){
		temp[index++] = c%10;
		c /= 10;
	}

	
	//���cΪ��������ô�������-��
	if(flag == -1){ printf("-");}
	//���չ涨�ĸ�ʽ������֣�ע��ÿ��3λ���������,Ҳ����˵����λ�����Ϊ3�ı�����Ҫ��","
	for( int i = index - 1; i >= 0 ; i--){
		printf("%d", temp[i]);
		if( i % 3 == 0 && i){ printf(",");}
	}
	printf("\n");
	return 0;
}