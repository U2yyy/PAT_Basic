#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	//这个题同样是用来考察string方法和各种方法调用的一个题目，不是很难 
	string s;
	//必须使用getline获取一整行，否则到空格处就会停止读取 
	getline(cin,s); 
	int num[123] = {0};
	for(int i=0;i<s.length();i++){
		if(s[i]>='A'&&s[i]<='Z')
		//使用transform进行转换大小写的操作 
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
