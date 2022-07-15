#include<iostream>
//这个题本质上是个数学问题，记录一下我犯的蠢，数数字个数都没数对，导致找规律没找出来 
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
	如果题目没有要求要连续，那么可以使用这个解法 
	//因为题目要求是连续，我们通过数学找规律可以找出来这个关系
	//同时因为双精度有精度方面的缺陷，因此我们使用longlong类型先进行存储 
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
	//这里换成long double以避免精度不够 
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
