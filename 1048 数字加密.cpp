#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int a[100] = {0};
	int b[100] = {0};
	int c[100] = {0};
	int j = 0;
	//�������һ��С�ӣ������ǰѸ�λ��Ϊ��һλ�ģ��������������ֱ�ӴӸ�λ��ʼ�� 
	for(int i=s1.length()-1;i>=0;i--){
		a[j] = s1[i]-'0';
		j++;
	}
	j = 0;
	for(int i=s2.length()-1;i>=0;i--){
		b[j] = s2[i]-'0';
		j++;
	}
	//��Ϊλ���Ѿ����������������ˣ�������ǿ���ֱ�ӽ��м��� 
	for(int i=0;i<s1.length()||i<s2.length();i++){
		if(i%2==0){
			c[i] = (a[i] + b[i]) % 13;
		}else{
			int temp = b[i] - a[i];
			if(temp<0)
				temp += 10;
			c[i] = temp;
		}
	}
	int length = s1.length()>s2.length()?s1.length():s2.length();
	for(int i=length-1;i>=0;i--){
		if(c[i]<10){
			cout<<c[i];
		}
		else{
			switch(c[i]){
				case 10:cout<<"J";break;
				case 11:cout<<"Q";break;
				case 12:cout<<"K";break;
				default:break; 
			}
		}
	}
	return 0;
}
