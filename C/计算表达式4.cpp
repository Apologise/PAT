#include<cstdio>
#include<stack>
using namespace std;

stack<int> op;
stack<double> np;
char str[220];

int mat[][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,	
};

void getOp(bool &retop, int &retnum, int &i){
	if(i == 0 && op.empty()){
		retop = true;
		retnum = 0;
		return ;
	}
	if(str[i] == 0){
		retop = true;
		retnum = 0;
		return;
	}
	
	if(str[i] >= '0' && str[i] <= '9'){
		retop = false;
	}else{
		retop = true;
		if(str[i] == '+'){
			retnum = 1;
		}else if(str[i] == '-'){
			retnum = 2;
		}else if(str[i] == '*'){
			retnum = 3;
		}else if(str[i] == '/'){
			retnum = 4;
		}
		i += 2;
		return;
	}
	retnum = 0;
	for(; str[i] != ' ' && str[i] != 0; i++){
		retnum *= 10;
		retnum += str[i] - '0';
	}
	if(str[i] == ' '){
		i++;
	}
	return ;
} 

int main(){
	while(gets(str)){
		//如果输入的是数字，那么直接输出数字
		bool retop;
		int retnum;
		int index = 0;
		while(true){
			getOp(retop, retnum, index);
			if(!retop){
				np.push(retnum);
			}else{
				//如果当前运算符优先级大于，直接入栈，如果小于栈顶，那么先出栈，
				if(op.empty() ||mat[retnum][op.top()] == 1){
					op.push(retnum);
				}else{
					double temp;
					while(mat[retnum][op.top()] == 0){
						int tag = op.top();
						op.pop();
						double b = np.top();
						np.pop();
						double a = np.top();
						np.pop();					
						if(tag == 1){
							temp = a + b;
						}else if(tag == 2){
							temp = a - b;
						}else if(tag == 3){
							temp = a * b;
						}else if(tag == 4){
							temp = a / b;
						}
						//将temp入栈
						np.push(temp); 
				}
				op.push(retnum);
			}
			}
			if(op.size() == 2 && op.top() == 0){break;} 
		}
		printf("%.2f\n",np.top());
	}
	return 0;
}