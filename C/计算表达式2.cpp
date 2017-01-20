
#include<cstdio>
#include<stack>
#include<cstring> 
using namespace std;
/*
思想:1.先定义一个运算符优先级矩阵 
	 2.分别在表达式首和尾添加一个终止符，终止符的运算优先级最低。
	 3.分别设立一个数字栈np,和运算符栈op，并且设置retn和reto,如果是reto为true，
	   则表示为运算符,retn返回运算符的标号，如果是false,retn返回的是该数字 
	 4.遍历表达式， 如果遇到数字，进入到数字栈，如果是运算符，则与当前op栈的栈
	   顶运算符比较优先级，如果op栈顶优先级小，则直接将该运算符入站，如果栈顶
	   的优先级大于当前遍历的运算符的优先级，那么将该栈顶运算符出栈，同时将数字栈中前两个数字出栈，并进行运算
	 5.知道最后栈中只有2个终止符，那么数字栈中的数字便是表达式的值 
*/

/*
	反思：在出现大于10的数时，要根据位来计算这个数
		 其次在出现比运算符栈顶小的运算符，要连续出2个数子，而且注意减法和除法时哪个是被减数，哪个是被除数
*/

int mat[][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};
stack<double> np;
stack<int> op;
char str[220];
void getOp(bool &reto, int &retn, int &i){
	//如果遍历的是第一个字符并且栈为空，则添加终止符.注意，此时i并没有自增， 
	if( i == 0 && op.empty() == true){
		reto = true;
		retn = 0;
		return;
	}
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
		}else if(str[i] == '/'){
			retn = 4;
		}
		i += 2;
		return ;
	}

	retn = 0;
	for(;str[i] != ' ' && str[i] != 0;i++){
		retn *= 10;
		retn += str[i] - '0';
	}
	if(str[i] == ' '){ i++;}
	return;
}
 
 int main(){
 	while(gets(str)){
	 	if(str[0] == '0' && str[1] == 0 ){break;}
	 	bool reto;
	 	int retn;
		int index = 0;
	 	//清空运算符栈和数字栈
		 while(!op.empty()){op.pop();}
		 while(!np.empty()){np.pop();}
		 while(true){
		 	getOp(reto, retn, index);
		 	if(reto == false){
			 	np.push((double)retn);
			 }else{
			 	double tmp;
			 	//比较当前运算符的优先级
				 if(op.empty() == true||mat[retn][op.top()] == 1){
				 	op.push(retn);
				 }else{
					while(mat[retn][op.top()] == 0){
						int ret = op.top();
						op.pop();
						double b = np.top();	//注意先出的是b，然后是a，因为是a/b，b在数字栈栈顶
						np.pop();
						double a = np.top();
						np.pop();
						if(ret == 1){tmp = a + b;}
						else if(ret == 2){tmp = a - b;}
						else if(ret == 3){tmp = a * b;}
						else {tmp = a / b;}
						np.push(tmp);
					}
					op.push(retn);		 	
				 } 
			 }
			 if(op.size() == 2 && op.top() == 0) break;
		 }
		 printf("%.2f\n", np.top()); 
	 }
	 return 0;
 }