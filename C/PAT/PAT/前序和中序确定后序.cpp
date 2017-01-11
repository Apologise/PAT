#include<cstdio>
#include<cstring>

typedef struct Node{
	Node *lchild;
	Node *rchild;
	char c;
}Node;

Node Tree[50];
int IOC;
Node *create(){
	Tree[IOC].lchild = Tree[IOC].rchild = NULL;
	return &Tree[IOC++];
}

char str1[30],str2[30];

void postOrder(Node *T){
	if(T->lchild != NULL){
		postOrder(T->lchild);
	}
	if(T->rchild != NULL){
		postOrder(T->rchild);
	}
	printf("%c",T->c);
}

Node *build(int s1,int e1,int s2,int e2){
	Node *ret = create();
	ret->c = str1[s1];
	int rootidx;
	for(int i = s2; i <= e2; ++i){
		if(str2[i] == str1[s1]){
			rootidx = i;
			break;
		}
	}
	if(rootidx != s2){
		ret->lchild = build(s1 + 1, s1 + (rootidx - s2), s2,rootidx - 1);
	}

	if(rootidx != e2){
		ret->rchild = build(s1 + (rootidx - s2) + 1, e1,rootidx + 1,e2);
	}
	return ret;
}

int main(){
	while(scanf("%s",str1) != EOF){
		scanf("%s", str2);
		IOC = 0;
		int L1 = strlen(str1);
		int L2 = strlen(str2);
		Node *T = build(0,L1-1,0,L2-1);
		postOrder(T);
		printf("\n");
	}
	return 0;
}