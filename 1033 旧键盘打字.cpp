#include<iostream>
#include<string>
//������Լ�д�Ĵ���Ƚϸ��ӣ�����ֻ��ͨ��һ��������������������������Ĵ���֮���Ȼ���ʣ���string���õ��ǳ����뻯
//��������֮����Լ�д��һ�飬ȷʵ��˼·�����ּ�
//�����˼·����һ��ɸ�ӣ�ɸ����������ģ������������� 
using namespace std;
int main(){
	string BadKey,Sentences;
	getline(cin,BadKey);
	getline(cin,Sentences);
	for(int i=0;i<Sentences.length();i++){
		if(BadKey.find(toupper(Sentences[i]))!=string::npos)
			continue;
		if(isupper(Sentences[i])&&BadKey.find('+')!=string::npos)
			continue;
		cout<<Sentences[i];
	}
	return 0;
} 
