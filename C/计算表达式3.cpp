/*
Author:Apolo
Time : 
Problem Description：计算表达式 
Method；
*/
#include<stack>
#include<cstdio>
using namespace std;
 
stack<double> np;
stack<int> op;
char str[220];

int mat[][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
}; 

void getOp(bool &reto, int &retn, int &i){
	//首先先添加终止符
	if(i == 0 && op.empty()){
		reto = true;
		retn = 0;
		return;
	} 
	//如果是最后一个字符
	if(str[i] == 0){
		reto = true;
		retn = 0;
		retn;
	}
	//如果是数字 
	if(str[i] <= '9' && str[i] >= '0'){
		reto = false;
	}else{	//	如果是运算符 
		reto = true;
		if(str[i] = '+'){
			retn = 1;
		} else if(str[i] == '-'){
			retn = 2;
		}else if(str[i] == '*'){
			retn = 3;
		}else if(str[i] == '/'){
			retn = 4;
		}
		i += 2;
		return;
	}
	retn = 0;
	//计算当前所代表的字符
	for(;str[i] != ' ' && str[i] != 0; i++){
		retn *= 10;
		retn = str[i] - '0';
	}
	if(str[i] == ' '){
		i++;
	} 
	
}

int main(){
	while(gets(str)){
		//如果只是输入0的话，直接输出
		if(str[0] == '0' && str[1] == 0){
			printf("0");
			break;
		} 
		bool reto;
		int retn; 
		int index;
		while(!op.empty()){op.pop();}
		while(!np.empty()){np.pop();}
		while(true){
			getOp(reto,retn, index);
			if(reto == false){
				np.push((double)retn);
			}else{
				if(op.empty() || mat[retn][op.top()] == 1){
					op.push(retn);
				}else{
					double tmp;
					while(mat[retn][op.top()] == 0){
						int ret = op.top();	//	返回栈顶符号
						op.pop();
						double b = np.top();
						np.pop();
						double a = np.top();
						np.pop(); 
						if(retn == 1){
							tmp = a + b;
						}else if(retn == 2){
							tmp = a - b;
						} else if(retn == 3){
							tmp = a * b;
						}else if(retn == 4){
							tmp = a / b;
						}
						np.push(tmp);
					}
					op.push(retn);
				}
			}
			if(op.size() == 2 && op.top() == 0){
				break;
			}
		} 
		printf("%.2f\n",np.top());
		
	}
	return 0;
}