#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	vector<char> broken;
	vector<char>::const_iterator it; 
	string s1,s2;
	cin>>s1>>s2;
	//�Ȱ�������ĸ����ɴ�д���Լ���򻯹��� 
	for(int i=0;i<s1.size();i++){
		s1[i] = toupper(s1[i]);
	}
	for(int i=0;i<s2.size();i++){
		s2[i] = toupper(s2[i]);
	}
	for(int i=0;i<s1.size();i++){
		bool flag = false;
		for(int j=0;j<s2.size();j++){
			if(s1[i]==s2[j]){//��������������ַ��������������Ͳ�ѹ��ջ�� 
				flag = true;
				break;
			}
		}
		if(flag == false){
			bool anoflag = false;
			for(it=broken.begin();it!=broken.end();it++){
				if(s1[i]==*it){//anoflag�������ж�ջ��֮ǰ��Ԫ���ǲ����Ѿ������������ѹ���Ԫ�أ����Ѿ����ھͲ�ѹ���� 
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
