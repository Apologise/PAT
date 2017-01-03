/*
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代
表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
*/
/*
输出描述:
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯

一，则输出按字母序最小的解。
*/

#include<stdio.h>
int main(){
	int N;

	//0代表平手，1代表胜利，2代表失败
	int result[3] = {0},resultInfo[2][3];	//result记录交手的胜利以及平局次数，resultInfo记录2个人3个手势的胜利次数
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			resultInfo[i][j] = 0;
		}
	}
	scanf("%d",&N);
	char A,B;
	for(int i = 0; i < N; ++i){
		//交手的信息
		//fflush(stdin);	//清除缓冲区的“\n”
		getchar();
		scanf("%c %c",&A,&B);
		
		//平手
		if(A == B){
			result[0] += 1;	//平局加一次  
		}else if( (A == 'C' && B == 'J')||(A == 'J' && B == 'B')||(A == 'B' && B == 'C')){
			result[1] += 1;	//甲的胜利次数
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

	//平手
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
	


	//统计甲乙出手手势最多的
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
	


	
	

	//Test：胜利次数及平手次数
	//甲的游戏信息
	printf("%d %d %d\n", result[1], result[0],N-result[0]-result[1]);
	//乙的游戏信息
	printf("%d %d %d\n", result[2], result[0],N-result[0]-result[2]);

	//手势最多
	printf("%c %c", maxA,maxB);

	/*printf("\n");
	for(int i = 0; i < 3; ++i){
		printf("%d ",resultInfo[0][i]);
	}*/
	return 0;
}
