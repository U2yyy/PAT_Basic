#include<iostream>
using namespace std;
int main(){
	int num[101] = {0};
	int n = 0;
	cin>>n;
	//�����˼·��Ϊ��������ת�����Ƚϼ� 
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		num[temp]++;
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		cout<<num[temp];
		if(i!=n-1)
			cout<<" ";
	}
	return 0;
}
