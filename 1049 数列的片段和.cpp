#include<iostream>
//����Ȿ�����Ǹ���ѧ���⣬��¼һ���ҷ��Ĵ��������ָ�����û���ԣ������ҹ���û�ҳ��� 
using namespace std;
/*****************************************
long long fun(double a[],int n){
	/*************************
	double cal;
	int cnt = 1;
	for(int i=1;i<n;i++){
		cnt *= 2;
	}
	for(int i=0;i<n;i++){
		cal += a[i] * cnt;
	}
	�����Ŀû��Ҫ��Ҫ��������ô����ʹ������ⷨ 
	//��Ϊ��ĿҪ��������������ͨ����ѧ�ҹ��ɿ����ҳ��������ϵ
	//ͬʱ��Ϊ˫�����о��ȷ����ȱ�ݣ��������ʹ��longlong�����Ƚ��д洢 
	long long cal = 0;
	for(int i=0;i<n;i++){
		cal += (long long)(a[i]*1000)*(n-i+1)*i; 
	}
	return cal;
******************************************/
int main(){
	int n;
	cin>>n;
	double sum;
	//���ﻻ��long double�Ա��⾫�Ȳ��� 
	long double temp;
	long long biggerone = 0;
	for(int i=0;i<n;i++){
		cin>>temp;
		biggerone += (temp*1000)*(n-i)*(i+1); 
	}
	sum = (double)biggerone/1000;
	printf("%.2f",sum);
	return 0;
}
