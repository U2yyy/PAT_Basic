#include<iostream>
using namespace std;
int main(){
	int num;
	char s;
	cin>>num>>s;
	for(int i=0;i<num;i++){
		cout<<s;
	}
	cout<<endl;
	//��һ��ʵ������������� 
	int temp = num;
	if(temp%2)
		temp += 1;
	for(int i=0;i<temp/2-2;i++){
		cout<<s;
		for(int i=0;i<num-2;i++){
		cout<<" ";
		}
		cout<<s<<endl;
	}
	for(int i=0;i<num;i++){
		cout<<s;
	}
}
