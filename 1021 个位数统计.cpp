#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char N[1002];
	//�����N������N[1002]������N[1001]�Ҹ��˻�δ��⣬�Ͼ��ַ�������ֻ��Ҫ��һ���� 
	memset(N,'#',sizeof(N));
	cin >> N;
	int num[10] = {0};
	for(int i=0;N[i]!='#';i++){
		switch(N[i]){
			case '0':
				num[0]++;break;
			case '1':
				num[1]++;break;
			case '2':
				num[2]++;break;
			case '3':
				num[3]++;break;
			case '4':
				num[4]++;break;
			case '5':
				num[5]++;break;
			case '6':
				num[6]++;break;
			case '7':
				num[7]++;break;
			case '8':
				num[8]++;break;
			case '9':
				num[9]++;break;									
		}
	}
	for(int i=0;i<10;i++){
		if(num[i]!=0){
			cout<<i<<":"<<num[i]<<endl;
		}
	}
	return 0;
}
