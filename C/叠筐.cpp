#include<stdio.h>

int outPutBuf[100][82][82];
int main(){
	int n[100];
	char a[100],b[100];
	int N = 0;
	bool firstCase = true;
	while(scanf("%d %c %c",&n[N], &a[N], &b[N]) != EOF){
		if(firstCase == true){firstCase = false;}else{printf("\n");}
		for(int i = 1, j = 1; i <= n[N]; i += 2,j++){
			int x = n[N]/2 + 1, y = x;
			x -= j - 1; y -= j -1;
			char c = j % 2 == 1 ? a[N] : b[N];
			for(int k  = 1; k <= i; k++){
				outPutBuf[N][x + k -1][y] = c;
				outPutBuf[N][x][y + k -1] = c;
				outPutBuf[N][x + i - 1][y + k -1] = c;
				outPutBuf[N][x + k -1][y + i -1] = c;
			}
		}
		
		if(n[N] != 1){
			outPutBuf[N][1][1] = ' ';
			outPutBuf[N][n[N]][1] = ' ';
			outPutBuf[N][1][n[N]] = ' ';
			outPutBuf[N][n[N]][n[N]] = ' ';

		}
		N++;
	}
	for(int s = 0; s < N; ++s){
		for(int i = 1; i <= n[s]; ++i){
			for(int j = 1; j <= n[s]; ++j){
				printf("%c", outPutBuf[s][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}