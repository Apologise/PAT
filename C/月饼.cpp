#include<stdio.h>
#include<algorithm>
using namespace std;

#define MaxSize 1001

typedef struct{
	double sum;	//存量
	double price;	//	价格
	double per;	//月饼的单价	
}YueBing;


//定义月饼的排序规则
bool cmp(YueBing A, YueBing B){
	return A.per > B.per;
}

int main(){
	YueBing product[MaxSize];
	int n,total;
	scanf("%d%d",&n,&total);
	for(int i = 1; i <= n; ++i){
		scanf("%lf",&product[i].sum);
	}
	for(int i = 1; i <= n; ++i){
		scanf("%lf",&product[i].price);
	}
	for(int i = 1; i <= n; ++i){
		product[i].per = (double)product[i].price  / product[i].sum;
	}
	
	sort(product+1,product+n+1,cmp);
	
	double maxProfit = 0;
	/*if(total == 0){
		printf("0.00");
	}else{*/
	for(int i = 1; i <= n; ++i){
	
	if(total < product[i].sum){
		maxProfit += (double)product[i].price*total/product[i].sum;
		break;
		
	}else {
		maxProfit += product[i].price;
		total  = total - product[i].sum;
	}
	}
	printf("%.2f",maxProfit);
	/*}*/
	return 0;
}