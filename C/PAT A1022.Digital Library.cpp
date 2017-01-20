#include<iostream>
#include<map>
#include<set>
#include<string>
#include<cstdio>
using namespace std;

map<string, set<int> > Mptitle,Mpauthor,Mpkeyword,Mppublisher,Mpyear;

void query(map<string ,set<int> > &mp, string &str){
	if(mp.find(str) == mp.end()){
		printf("Not Found\n");
	}else{
		for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); ++it){
			printf("%07d\n", *it);
		}
	}
}

int main(){
	int N,id,type;
	string title, author,publisher,year,keywords;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d",&id);
		char c = getchar();	//	接受输入id后面的换行
		getline(cin,title); 
		Mptitle[title].insert(id);
		getline(cin,author);
		Mpauthor[author].insert(id);
		//输入关键词
		while(cin>>keywords){
			Mpkeyword[keywords].insert(id);
			c = getchar(); 
			if(c == '\n'){ break;}
		}
		getline(cin, publisher);
		Mppublisher[publisher].insert(id); 
		getline(cin,year);
		Mpyear[year].insert(id);	
	}
	
	string temp;
	int m;	//	查询的次数 
	scanf("%",&m);
	for(int i = 0; i < m; i++){
		scanf("%d: ",&type);	//	注意，这里不需要getchar来接受，因为没有换行 
		getline(cin,temp);
		cout<<type<<": "<<temp<<endl;
		if(type == 1){	//title
			query(Mptitle,temp);
		}else if(type == 2){
			query(Mpauthor,temp);
		}else if(type == 3){
			query(Mpkeyword, temp);
		}else if(type == 4){
			query(Mppublisher, temp);
		}else{
			query(Mpyear, temp);
		}
		return 0;
	}
}