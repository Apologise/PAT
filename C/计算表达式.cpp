
//˼·��
//1.����2����ջ��һ�����������������һ�������������֡�
//2.�ڱ��ʽ��β��ӱ�����������������������ȼ����
//3.��������һ�α����ַ�������������������������������ջ��Ԫ�ؽ��бȽϣ��������ջ����������ȼ�С�ڸ���������ߴ�ʱ�����ջΪ�գ��򽫸������ѹ���ջ�������ַ����е���һ��Ԫ�ء�
//4.�������ջջ�����ȼ����ڸ���������򵯳�����������ٴ�����ջ�����ε���2��ջ�����֣���ɵ������������Ӧ������õ�������ڽ��ý��ѹ������ջ���ظ��Ƚϴ�ʱջ��������뵱ǰ����������������ȼ����������ȼ���С�ظ�����3����4
//5.�����������ʽ�е����֣���ֱ��ѹ������ջ
//6.���������ջ�н���2���������ջ��Ԫ��Ϊ�����Լ���ӵı�����������ô���ʽ�����������ʱ���ֶ�ջ��Ψһ�����ּ�Ϊ���ʽ��ֵ

#include<stdio.h>
#include<stack>
using namespace std;

char str[220];
//
//�������ȼ�������mat[i][j] == 1, ��ʾi����������ȼ�����j���������������������Ϊ+Ϊ1�ţ�-Ϊ2�ţ�*Ϊ3�ţ�/Ϊ4��
//��Ϊ��ӵ���������ȼ�Ϊ0
int mat[][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};

stack<int> op; //�����ջ��������������
stack<double> in;	//����ջ�����������ܴ��ڸ�������������doule

//��ñ��ʽ����һ��Ԫ�غ��������������н���ʱ�����ñ���retoΪtrue�����ʾ��Ԫ��Ϊһ���������
//���ű��������ñ���retn�У������ʾ��Ԫ��Ϊһ�����֣���ֵ���������ñ���retn�У����ñ�����i��ʾ�������ַ������±�

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
		i += 2;	//������������������͸��������Ŀո�
		return;
	}
	retn = 0;
	for(; str[i] != ' ' && str[i] != 0; ++i){
		//���ַ���δ�������꣬����һ���ַ����ǿո������α���������֣����㵱ǰ���������ַ���ʾ����ֵ
		retn *= 10;
		retn += str[i] - '0';	//	�����258�����������ַ���ʾ������Ҫ2*10*10+5*10+8
	}
	if(str[i] == ' '){
		++i;
	}
	return ;
}

int main(){
	while(gets(str)){	//�����ַ���������λ���ļ�βʱ��gets����0
		if(str[0] == '0' && str[1] == 0){break;}
		bool retop;
		int retnum;
		int index = 0;
		while(!op.empty()){op.pop();}
		while(!in.empty()){in.pop();}	//	����ַ�ջ������ջ
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
						int ret = op.top();	//	����ջ�������

						//��������2������
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