/*
Author:Apolo
Time : 
Problem Description��������ʽ 
Method��
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
	//�����������ֹ��
	if(i == 0 && op.empty()){
		reto = true;
		retn = 0;
		return;
	} 
	//��������һ���ַ�
	if(str[i] == 0){
		reto = true;
		retn = 0;
		retn;
	}
	//��������� 
	if(str[i] <= '9' && str[i] >= '0'){
		reto = false;
	}else{	//	���������� 
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
	//���㵱ǰ��������ַ�
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
		//���ֻ������0�Ļ���ֱ�����
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
						int ret = op.top();	//	����ջ������
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