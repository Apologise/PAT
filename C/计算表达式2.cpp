
#include<cstdio>
#include<stack>
#include<cstring> 
using namespace std;
/*
˼��:1.�ȶ���һ����������ȼ����� 
	 2.�ֱ��ڱ��ʽ�׺�β���һ����ֹ������ֹ�����������ȼ���͡�
	 3.�ֱ�����һ������ջnp,�������ջop����������retn��reto,�����retoΪtrue��
	   ���ʾΪ�����,retn����������ı�ţ������false,retn���ص��Ǹ����� 
	 4.�������ʽ�� ����������֣����뵽����ջ�����������������뵱ǰopջ��ջ
	   ��������Ƚ����ȼ������opջ�����ȼ�С����ֱ�ӽ����������վ�����ջ��
	   �����ȼ����ڵ�ǰ����������������ȼ�����ô����ջ���������ջ��ͬʱ������ջ��ǰ�������ֳ�ջ������������
	 5.֪�����ջ��ֻ��2����ֹ������ô����ջ�е����ֱ��Ǳ��ʽ��ֵ 
*/

/*
	��˼���ڳ��ִ���10����ʱ��Ҫ����λ�����������
		 ����ڳ��ֱ������ջ��С���������Ҫ������2�����ӣ�����ע������ͳ���ʱ�ĸ��Ǳ��������ĸ��Ǳ�����
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
	//����������ǵ�һ���ַ�����ջΪ�գ��������ֹ��.ע�⣬��ʱi��û�������� 
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
	 	//��������ջ������ջ
		 while(!op.empty()){op.pop();}
		 while(!np.empty()){np.pop();}
		 while(true){
		 	getOp(reto, retn, index);
		 	if(reto == false){
			 	np.push((double)retn);
			 }else{
			 	double tmp;
			 	//�Ƚϵ�ǰ����������ȼ�
				 if(op.empty() == true||mat[retn][op.top()] == 1){
				 	op.push(retn);
				 }else{
					while(mat[retn][op.top()] == 0){
						int ret = op.top();
						op.pop();
						double b = np.top();	//ע���ȳ�����b��Ȼ����a����Ϊ��a/b��b������ջջ��
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