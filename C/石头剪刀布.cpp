/*
�����1�и���������N��<=105������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�C�������ӡ���J������������B��
����������1����ĸ����׷�����2�������ҷ����м���1���ո�
*/
/*
�������:
�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ�����3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�����ⲻΨ

һ�����������ĸ����С�Ľ⡣
*/

#include<stdio.h>
int main(){
	int N;

	//0����ƽ�֣�1����ʤ����2����ʧ��
	int result[3] = {0},resultInfo[2][3];	//result��¼���ֵ�ʤ���Լ�ƽ�ִ�����resultInfo��¼2����3�����Ƶ�ʤ������
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			resultInfo[i][j] = 0;
		}
	}
	scanf("%d",&N);
	char A,B;
	for(int i = 0; i < N; ++i){
		//���ֵ���Ϣ
		//fflush(stdin);	//����������ġ�\n��
		getchar();
		scanf("%c %c",&A,&B);
		
		//ƽ��
		if(A == B){
			result[0] += 1;	//ƽ�ּ�һ��  
		}else if( (A == 'C' && B == 'J')||(A == 'J' && B == 'B')||(A == 'B' && B == 'C')){
			result[1] += 1;	//�׵�ʤ������
			if(A == 'B'){
				resultInfo[0][0] += 1;
			}else if(A == 'C'){
				resultInfo[0][1] += 1;
			}else if(A == 'J'){
				resultInfo[0][2] += 1;
			}
		}else{
			result[2] += 1;
		}
	}

	//ƽ��
		if(A == B){
		}else if( (B == 'C' && A == 'J')||(B == 'J' && A == 'B')||(B == 'B' && A == 'C')){
			if(B == 'B'){
				resultInfo[1][0] += 1;
			}else if(B == 'C'){
				resultInfo[1][1] += 1;
			}else if(B == 'J'){
				resultInfo[1][2] += 1;
			}
		}else{
			
		}
	


	//ͳ�Ƽ��ҳ�����������
	char maxA ,maxB;
	int maxIndexA = -1,aMax = -1;
	for(int i = 0; i < 3; ++i){
		if(aMax < resultInfo[0][i]){
			maxIndexA = i;
			aMax = resultInfo[0][i];
		} 
	}

	int maxIndexB = -1,bMax = -1;
	for(int i = 0; i < 3; ++i){
		if(bMax < resultInfo[1][i]){
			maxIndexB = i;
			bMax = resultInfo[1][i];
		} 
	}

	/*printf("maxIndexA%d",maxIndexA);*/
	if(maxIndexA == 0){
		maxA = 'B';
	}else if(maxIndexA == 1){
		maxA = 'C';
	}else if(maxIndexA == 2) {
		maxA = 'J';
	}
	if(maxIndexB == 0){
		maxB = 'B';
	}else if(maxIndexB == 1){
		maxB = 'C';
	}else {
		maxB = 'J';
	}
	


	
	

	//Test��ʤ��������ƽ�ִ���
	//�׵���Ϸ��Ϣ
	printf("%d %d %d\n", result[1], result[0],N-result[0]-result[1]);
	//�ҵ���Ϸ��Ϣ
	printf("%d %d %d\n", result[2], result[0],N-result[0]-result[2]);

	//�������
	printf("%c %c", maxA,maxB);

	/*printf("\n");
	for(int i = 0; i < 3; ++i){
		printf("%d ",resultInfo[0][i]);
	}*/
	return 0;
}
