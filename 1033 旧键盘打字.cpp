#include<iostream>
#include<string>
//这道题自己写的代码比较复杂，并且只能通过一个用例（主用例），看了柳神的代码之后豁然开朗，用string类用的是出神入化
//看明白了之后就自己写了一遍，确实是思路清晰又简单
//柳神的思路很像一个筛子，筛掉不能输出的，输出可以输出的 
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
