#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int main(){
	int n;
	cin>>n;
	int k = 0;
	char a[50];
	char b[50];
	double temp = 0.0;
	double sum = 0.0;
	for(int i=0;i<n;i++){
		bool isLegal = true;
		cin>>a;
		//����Ĺؼ�˼·��������sscanf��sprintf���������Ը�ʽ����ȡ�͸�ʽ�����룬��������������Ҫ 
		sscanf(a,"%lf",&temp);//sscanf�ܱ�׼����ȡ�����ｫ�ַ���ת������˫������ 
		sprintf(b,"%.2f",temp);//sprintf�ܱ�׼�����룬���ｫ˫��������С���㱣����λ����ʽ����b�� 
		for(int j=0;j<strlen(a);j++){
			if(a[j]!=b[j]){
				isLegal = false;
				break;
			}
		}
		if(!isLegal||temp<-1000||temp>1000){
			cout<<"ERROR: "<<a<<" is not a legal number"<<endl;
		}else{
			sum += temp;
			k++;
		}
	}
	double ave = sum / k;
	if(k==0){
		cout<<"The average of 0 numbers is Undefined";
	}else if(k==1){
		cout<<"The average of 1 number is ";
		printf("%.2f",ave);
	}else{
		cout<<"The average of "<<k<<" numbers is ";
		printf("%.2f",ave);
	}
	return 0;
}
