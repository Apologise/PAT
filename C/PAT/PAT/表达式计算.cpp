//思想：
//1.设置两个栈，一个为运算符栈，一个为数字栈
//2.在计算式中首尾添加标识符，这个运算符的优先级最低
//3.从左至右遍历字符串，如果遍历到运算符，该运算符的优先级大于栈顶的运算符，那么就直接将该运算符压入栈
//  如果当前遍历到的运算符小于栈顶运算符，那么弹出栈顶运算符，并且依次弹出两个数字，并进行计算，然后将
//  计算的结果压入数字栈，并且当前遍历的运算符也进入运算符栈
//4.若遍历到数字，则直接将数字压入数字栈
//5.如果运算符栈中只有2个运算符并且栈顶为我们人为添加的标识符，那么表达式运算结束，此时数字栈中的结果就
//  表达式的结果

#include<cstdio>
#include<stack>
using namespace std;

char str[220];	//	计算式字符串
int mat[][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};	//	运算符优先级矩阵，0序号代表认为添加标识符，1为+,2为-，3为*，4为/

stack<char> op;
stack<double> in;

void getOp(bool &reto, int &retn, int &i){
	/*1.如果是第一个字符，那么先认为添加一个，*/
	if(i == 0 && op.empty() == true){
		reto = true;
		retn = 0;
		return;
	}
	/*2.如果遍历到末尾，也同样添加一个*/
	if(str[i] == 0){
		reto = true;
		retn = 0;
		return;
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
		}else{
			retn = 4;
		}
		i += 2;
		return;
	}
	retn = 0;
	for(;str[i] != ' ' && str[i] != 0; ++i){
		retn *= 10;
		retn += str[i] - '0';
	}
	if(str[i] == ' '){
		++i;
	}
	return;
}

int main(){
	while(gets(str)){
		if(str[0] == '0' && str[1] == 0){
			break;
		}
		bool retop;
		int retnum;
		int index;
		while(!op.empty()){op.pop();}
		while(!in.empty()){in.pop();}
		while(true){
			getOp(retop,retnum,index);
			if(retop == false){
				in.push((double)retnum);
			}else{
				double tmp;
				if(op.empty() == true || mat[retnum][op.top()] == 1){
					op.push(retnum);
				}else{
					while(mat[retnum][op.top()] == 0){
						int ret = op.top();
						op.pop();
						double b = in.top();
						in.pop();
						double a = in.top();
						in.pop();
						if(ret == 1){ 
							tmp = a + b;
						}else if(ret == 2){
							tmp = a - b;
						}else if(ret == 3){
							tmp = a * b;
						}else{
							tmp = a / b;
						}
						in.push(tmp);
					}
					op.push(retnum);
				}
			}
			if(op.size() == 2 && op.top() == 0) {break;}
		}
		printf("%.2f\n",in.top());
	}
	return 0;
}