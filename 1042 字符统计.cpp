#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	//�����ͬ������������string�����͸��ַ������õ�һ����Ŀ�����Ǻ��� 
	string s;
	//����ʹ��getline��ȡһ���У����򵽿ո񴦾ͻ�ֹͣ��ȡ 
	getline(cin,s); 
	int num[123] = {0};
	for(int i=0;i<s.length();i++){
		if(s[i]>='A'&&s[i]<='Z')
		//ʹ��transform����ת����Сд�Ĳ��� 
			transform(s.begin(),s.end(),s.begin(),::tolower);
	}
	for(int i=0;i<s.length();i++){
		if(s[i]>='a'&&s[i]<='z')
			num[s[i]]++;
	}
	int max = 0;
	for(int i=97;i<123;i++){
		if(num[i]>max)
			max = num[i];
	}
	vector<char> maxCharacter;
	vector<char>::iterator it;
	for(int i=0;i<123;i++){
		if(num[i]==max)
			maxCharacter.push_back(char(i));
	}
	it = maxCharacter.begin();
	cout<<*it<<" "<<max;
	return 0;
}
