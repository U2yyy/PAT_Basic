#include<iostream>
using namespace std;
int main(){
	int num[10] = {0};
	//����ÿ�����ĸ��� 
	for(int i=0;i<10;i++){
		cin>>num[i];
	}
	//��Ϊ0��������ǰ�棬��������ǰ���Ӧ���ǳ���0����С�����֣�Ȼ����0�����0��û0�ͼ������������� 
	//�ж�num[0]�Ƿ�Ϊ0�������
	if(num[0] == 0){
		for(int i=1;i<10;i++){
			while(num[i]>0){
				cout<<i;
				num[i]--;
			}
		}
	}else{
		for(int i=1;i<10;i++){
			if(num[i]!=0){
				cout<<i;
				num[i]--;
				break;
			}
		}
		for(int i=0;i<10;i++){
			while(num[i]>0){
				cout<<i;
				num[i]--;
			}
		}
	}
	return 0;
}
