#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin>>s;
	int cnt = 0;
	//�����Ǳ������Ľⷨ��������������Ե㳬ʱ��Ҳ��������֮�� 
	/*for(int i=0;i<s.length();i++){
		if(s[i]=='P'){
			for(int j=i+1;j<s.length();j++){
				if(s[j]=='A'){
					for(int k=j+1;k<s.length();k++){
						if(s[k]=='T'){
							cnt++;
							break;
						}
					}
				}
			}
		}
	}*/
	//����Ľⷨ�Ѿ������˿�������ÿ��A��ǰP�����ͺ�T������˵õ�������Ȼû�иı�ʱ�临�Ӷȹ��ߵ���ʵ 
	/*
	int numP = 0;
	int numT = 0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='A'){
			for(int j=0;j<i;j++){
				if(s[j]=='P')
					numP++;
			}
			for(int k=i+1;k<s.length();k++){
				if(s[k]=='T')
					numT++;
			}
			cnt += numP*numT;
			numP = 0;
			numT = 0;
		}
	}
	*/
	//�����ǿ�������Ĳ���֮�����׵�˼·�����ò�����ȷʵ�ǳ�����
	int numP = 0;
	int numT = 0;
	for(int i=0;i<s.length();i++){
		//ֻ��Ҫ��T������ȫ��������� 
		if(s[i]=='T')
			numT++;
	}
	for(int i=0;i<s.length();i++){
		if(numT==0)
			break;
		//ÿ������Pʱ���Ͷ�numP���м�һ���� 
		if(s[i]=='P')
			numP++;
		//ÿ������Tʱ���Ͷ�numT���м�һ���� 
		if(s[i]=='T')
			numT--;
		//cnt��ʵ����ÿ��Aǰ���P�ͺ����T����Ŀ�ĳ˻� 
		if(s[i]=='A')
			cnt = (cnt+(numP*numT)%1000000007)%1000000007;
	}
	cout<<cnt;
	return 0;
}
