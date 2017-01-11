#include<stdio.h>
//定义宏判断是否为闰年
#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ?1 : 0 



int dayOfMonth[13][2] = {
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};//预存每月的天数

struct Date{
	int Day;
	int Month;
	int Year;
	void nextDay(){//计算下一天的日期
		Day++;
		if(Day > dayOfMonth[Month][ISYEAP(Year)]){
			Day = 1;
			Month ++;
			if(Month > 12 ){
				Month = 1;
				Year ++;
			}
		}
	}
};

int buf[5001][13][32];	//保存预处理的天数
int ABS(int x){
	return x < 0? -x : x;
}

int main(){
	Date tmp;
	int count = 0;	//天数计数
	//初始化日期为0年1月1日
	tmp.Day = 1;
	tmp.Month = 1;
	tmp.Year = 0;
	while(tmp.Year != 5001){
		buf[tmp.Year][tmp.Month][tmp.Day] = count;
		tmp.nextDay();
		count++;
	}

	int d1,m1,y1;
	int d2,m2,y2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1) != EOF){
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",ABS(buf[y2][m2][d2] - buf[y1][m1][d1]) + 1);
	}

	return 0;
}