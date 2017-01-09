
//思路：
//1.设立2个堆栈，一个用来保存运算符，一个用来保存数字。
//2.在表达式首尾添加标记运算符，该运算符运算优先级最低
//3.从左至右一次遍历字符串，若遍历到运算符，将其与运算符栈顶元素进行比较，若运算符栈顶运算符优先级小于该运算符或者此时运算符栈为空，则将该运算符压入堆栈。遍历字符串中的下一个元素。
//4.若运算符栈栈顶优先级大于该运算符，则弹出该运算符，再从数字栈中依次弹出2个栈顶数字，完成弹出的运算符对应的运算得到结果后，在将该结果压入数字栈，重复比较此时栈顶运算符与当前遍历到的运算符优先级，视其优先级大小重复步骤3或步骤4
//5.若遍历到表达式中的数字，则直接压入数字栈
//6.若运算符堆栈中仅存2个运算符且栈顶元素为我们自己添加的标记运算符，那么表达式运算结束，此时数字堆栈中唯一的数字即为表达式的值

#include<stdio.h>
#include<stack>
using namespace std;

char str[220];
//
//定义优先级矩阵，若mat[i][j] == 1, 表示i号运算符优先级大于j号运算符，运算符编码规则为+为1号，-为2号，*为3号，/为4号
//人为添加的运算符优先级为0
int mat[][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};

stack<int> op; //运算符栈，保存运算符编号
stack<double> in;	//数字栈，运算结果可能存在浮点数，所以用doule

//获得表达式中下一个元素函数，若函数运行结束时，引用变量reto为true，则表示该元素为一个运算符，
//其编号保存在引用变量retn中，否则表示该元素为一个数字，其值保存在引用变量retn中，引用变量用i表示遍历到字符串的下标

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
		i += 2;	//递增，跳过该运算符和该运算符后的空格
		return;
	}
	retn = 0;
	for(; str[i] != ' ' && str[i] != 0; ++i){
		//若字符串未被遍历完，且下一个字符不是空格，则依次遍历其后数字，计算当前连续数字字符表示的数值
		retn *= 10;
		retn += str[i] - '0';	//	如果是258，由于是用字符表示，则需要2*10*10+5*10+8
	}
	if(str[i] == ' '){
		++i;
	}
	return ;
}

int main(){
	while(gets(str)){	//输入字符串，当其位于文件尾时，gets返回0
		if(str[0] == '0' && str[1] == 0){break;}
		bool retop;
		int retnum;
		int index = 0;
		while(!op.empty()){op.pop();}
		while(!in.empty()){in.pop();}	//	清空字符栈和数字栈
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
						int ret = op.top();	//	保存栈顶运算符

						//连续弹出2个数字
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