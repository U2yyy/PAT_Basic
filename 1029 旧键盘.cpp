#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	vector<char> broken;
	vector<char>::const_iterator it; 
	string s1,s2;
	cin>>s1>>s2;
	//先把所有字母都变成大写可以极大简化过程 
	for(int i=0;i<s1.size();i++){
		s1[i] = toupper(s1[i]);
	}
	for(int i=0;i<s2.size();i++){
		s2[i] = toupper(s2[i]);
	}
	for(int i=0;i<s1.size();i++){
		bool flag = false;
		for(int j=0;j<s2.size();j++){
			if(s1[i]==s2[j]){//这里是如果两个字符串中有相等情况就不压入栈中 
				flag = true;
				break;
			}
		}
		if(flag == false){
			bool anoflag = false;
			for(it=broken.begin();it!=broken.end();it++){
				if(s1[i]==*it){//anoflag是用来判断栈中之前的元素是不是已经存在这个即将压入的元素，若已经存在就不压入了 
					anoflag = true;
					break;
				}
			}
			if(anoflag == false)
				broken.push_back(s1[i]);
		}
	}
	for(it=broken.begin();it!=broken.end();it++){
		cout<<*it; 
	}
} 
