﻿
//Ë¼Â·£º
//1.ÉèÁ¢2¸ö¶ÑÕ»£¬Ò»¸öÓÃÀ´±£´æÔËËã·û£¬Ò»¸öÓÃÀ´±£´æÊý×Ö¡£
//2.ÔÚ±í´ïÊ½Ê×Î²Ìí¼Ó±ê¼ÇÔËËã·û£¬¸ÃÔËËã·ûÔËËãÓÅÏÈ¼¶×îµÍ
//3.´Ó×óÖÁÓÒÒ»´Î±éÀú×Ö·û´®£¬Èô±éÀúµ½ÔËËã·û£¬½«ÆäÓëÔËËã·ûÕ»¶¥ÔªËØ½øÐÐ±È½Ï£¬ÈôÔËËã·ûÕ»¶¥ÔËËã·ûÓÅÏÈ¼¶Ð¡ÓÚ¸ÃÔËËã·û»òÕß´ËÊ±ÔËËã·ûÕ»Îª¿Õ£¬Ôò½«¸ÃÔËËã·ûÑ¹Èë¶ÑÕ»¡£±éÀú×Ö·û´®ÖÐµÄÏÂÒ»¸öÔªËØ¡£
//4.ÈôÔËËã·ûÕ»Õ»¶¥ÓÅÏÈ¼¶´óÓÚ¸ÃÔËËã·û£¬Ôòµ¯³ö¸ÃÔËËã·û£¬ÔÙ´ÓÊý×ÖÕ»ÖÐÒÀ´Îµ¯³ö2¸öÕ»¶¥Êý×Ö£¬Íê³Éµ¯³öµÄÔËËã·û¶ÔÓ¦µÄÔËËãµÃµ½½á¹ûºó£¬ÔÚ½«¸Ã½á¹ûÑ¹ÈëÊý×ÖÕ»£¬ÖØ¸´±È½Ï´ËÊ±Õ»¶¥ÔËËã·ûÓëµ±Ç°±éÀúµ½µÄÔËËã·ûÓÅÏÈ¼¶£¬ÊÓÆäÓÅÏÈ¼¶´óÐ¡ÖØ¸´²½Öè3»ò²½Öè4
//5.Èô±éÀúµ½±í´ïÊ½ÖÐµÄÊý×Ö£¬ÔòÖ±½ÓÑ¹ÈëÊý×ÖÕ»
//6.ÈôÔËËã·û¶ÑÕ»ÖÐ½ö´æ2¸öÔËËã·ûÇÒÕ»¶¥ÔªËØÎªÎÒÃÇ×Ô¼ºÌí¼ÓµÄ±ê¼ÇÔËËã·û£¬ÄÇÃ´±í´ïÊ½ÔËËã½áÊø£¬´ËÊ±Êý×Ö¶ÑÕ»ÖÐÎ¨Ò»µÄÊý×Ö¼´Îª±í´ïÊ½µÄÖµ

#include<stdio.h>
#include<stack>
using namespace std;

char str[220];
//
//¶¨ÒåÓÅÏÈ¼¶¾ØÕó£¬Èômat[i][j] == 1, ±íÊ¾iºÅÔËËã·ûÓÅÏÈ¼¶´óÓÚjºÅÔËËã·û£¬ÔËËã·û±àÂë¹æÔòÎª+Îª1ºÅ£¬-Îª2ºÅ£¬*Îª3ºÅ£¬/Îª4ºÅ
//ÈËÎªÌí¼ÓµÄÔËËã·ûÓÅÏÈ¼¶Îª0
int mat[][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};

stack<char> op; //ÔËËã·ûÕ»£¬±£´æÔËËã·û±àºÅ
stack<double> in;	//Êý×ÖÕ»£¬ÔËËã½á¹û¿ÉÄÜ´æÔÚ¸¡µãÊý£¬ËùÒÔÓÃdoule

//»ñµÃ±í´ïÊ½ÖÐÏÂÒ»¸öÔªËØº¯Êý£¬Èôº¯ÊýÔËÐÐ½áÊøÊ±£¬ÒýÓÃ±äÁ¿retoÎªtrue£¬Ôò±íÊ¾¸ÃÔªËØÎªÒ»¸öÔËËã·û£¬
//Æä±àºÅ±£´æÔÚÒýÓÃ±äÁ¿retnÖÐ£¬·ñÔò±íÊ¾¸ÃÔªËØÎªÒ»¸öÊý×Ö£¬ÆäÖµ±£´æÔÚÒýÓÃ±äÁ¿retnÖÐ£¬ÒýÓÃ±äÁ¿ÓÃi±íÊ¾±éÀúµ½×Ö·û´®µÄÏÂ±ê

void getOp(bool &reto, int &retn, int &i){
	if(i == 0 && op.empty() == true){
		reto = true;
		retn = 0;
		return;
	}	
	if(str[i] == 0){
		reto = true;
		retn = 0;
	}
	if(str[i] >= '0' && str[i] <= '9'){
		reto = false;
	}else{
		reto = true;
		if(str[i] == '+'){
			retn = 1;
		}else if(str[i] == '-'){
			retn = 2;
		}else if(str[i] == '*'){
			retn = 3;
		}else if(str[i] == '/'){
			retn = 4;
		}
		i += 2;	//µÝÔö£¬Ìø¹ý¸ÃÔËËã·ûºÍ¸ÃÔËËã·ûºóµÄ¿Õ¸ñ
		return;
	}
	retn = 0;
	for(; str[i] != ' ' && str[i] != 0; ++i){
		//Èô×Ö·û´®Î´±»±éÀúÍê£¬ÇÒÏÂÒ»¸ö×Ö·û²»ÊÇ¿Õ¸ñ£¬ÔòÒÀ´Î±éÀúÆäºóÊý×Ö£¬¼ÆËãµ±Ç°Á¬ÐøÊý×Ö×Ö·û±íÊ¾µÄÊýÖµ
		retn *= 10;
		retn += str[i] - '0';	//	Èç¹ûÊÇ258£¬ÓÉÓÚÊÇÓÃ×Ö·û±íÊ¾£¬ÔòÐèÒª2*10*10+5*10+8
	}
	if(str[i] == ' '){
		++i;
	}
	return ;
}

int main(){
	while(gets(str)){	//ÊäÈë×Ö·û´®£¬µ±ÆäÎ»ÓÚÎÄ¼þÎ²Ê±£¬gets·µ»Ø0
		if(str[0] == '0' && str[1] == 0){break;}
		bool retop;
		int retnum;
		int index = 0;
		while(!op.empty()){op.pop();}
		while(!in.empty()){in.pop();}	//	Çå¿Õ×Ö·ûÕ»ºÍÊý×ÖÕ»
		while(true){
			
			getOp(retop,retnum,index);
			if(retop == false){
				in.push((double)retnum);
			}else{
				double tmp;
				if(op.empty() == true || mat[retnum][op.top()] == 1){
					op.push(retnum);
				}else {
				
					while(mat[retnum][op.top()] == 0){
						int ret = op.top();	//	±£´æÕ»¶¥ÔËËã·û

						//Á¬Ðøµ¯³ö2¸öÊý×Ö
						op.pop();
						double b = in.top();
						in.pop();
						double a = in.top();
						in.pop();
						if(ret == 1){tmp = a+b;}
						else if(ret == 2){tmp = a-b;}
						else if(ret == 3){tmp = a*b;}
						else{tmp = a / b;}
						in.push(tmp);
					}
					op.push(retnum);
				}
			}
			if(op.size() == 2 && op.top() == 0) {break;}
		}
		printf("%.2f\n", in.top());
	}
	return 0;
}