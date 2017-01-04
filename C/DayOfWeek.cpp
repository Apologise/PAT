#include<stdio.h>
#include<string.h>

#define ISYEAP(x) (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0) ? 1 : 0

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
	31,31,
};
char monthName[13][20] = {
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

char week[7][20] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

typedef struct{
	int Year;
	int Month;
	int Day;
	void nextDay(){
		Day++;
		if(Day > dayOfMonth[Month][ISYEAP(Year)]){
			Month++;
			Day = 1;
			if(Month >12){
				Month = 1;
				Year++;
			}
		}
	}
}Date;

int buf[5001][13][32];

int abs(int x){
	return x < 0 ? -x:x;
}
int main(){
	int count = 0;	//统计天数
	Date temp;
	temp.Day = 1;
	temp.Month = 1;
	temp.Year = 0; //初始化日期为0年1月1日；
	//初始化buf数组
	while( temp.Year != 5000){
		buf[temp.Year][temp.Month][temp.Day] = count;
		count++;
		temp.nextDay();
	}

	int day,month,year;
	char s[20];
	while(scanf("%d%s%d",&day,s,&year) != EOF){
		for(month = 1; month <= 12; ++month){
			if(strcmp(s,monthName[month]) == 0){
				break;
			}
		}
		int days = buf[year][month][day] - buf[2017][1][2];	// 2017-1-2是星期一
		days +=1 ;
		puts(week[(days % 7 + 7) % 7]);
	}
	
	
	return 0;
}