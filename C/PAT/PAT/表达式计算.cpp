//˼�룺
//1.��������ջ��һ��Ϊ�����ջ��һ��Ϊ����ջ
//2.�ڼ���ʽ����β��ӱ�ʶ�����������������ȼ����
//3.�������ұ����ַ���������������������������������ȼ�����ջ�������������ô��ֱ�ӽ��������ѹ��ջ
//  �����ǰ�������������С��ջ�����������ô����ջ����������������ε����������֣������м��㣬Ȼ��
//  ����Ľ��ѹ������ջ�����ҵ�ǰ�����������Ҳ���������ջ
//4.�����������֣���ֱ�ӽ�����ѹ������ջ
//5.��������ջ��ֻ��2�����������ջ��Ϊ������Ϊ��ӵı�ʶ������ô���ʽ�����������ʱ����ջ�еĽ����
//  ���ʽ�Ľ��

#include<cstdio>
#include<stack>
using namespace std;

char str[220];	//	����ʽ�ַ���
int mat[][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};	//	��������ȼ�����0��Ŵ�����Ϊ��ӱ�ʶ����1Ϊ+,2Ϊ-��3Ϊ*��4Ϊ/

stack<char> op;
stack<double> in;

void getOp(bool &reto, int &retn, int &i){
	/*1.����ǵ�һ���ַ�����ô����Ϊ���һ����*/
	if(i == 0 && op.empty() == true){
		reto = true;
		retn = 0;
		return;
	}
	/*2.���������ĩβ��Ҳͬ�����һ��*/
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