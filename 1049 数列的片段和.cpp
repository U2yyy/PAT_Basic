#include<iostream>
//����Ȿ�����Ǹ���ѧ���⣬��¼һ���ҷ��Ĵ��������ָ�����û���ԣ������ҹ���û�ҳ��� 
using namespace std;
double calculate(double a[],int n){
	double sum = 0;
	for(int i=0;i<n;i++){
		sum += a[i];
	}
	return sum;
}
double fun(double a[],int n){
	double cal = 0;
	for(int i=0;i<n;i++){
		cal += a[i];
	}
	for(int j=0;j<n;j++){
		double *b = a;
		for(int i=j;i<n;i++){
			b[i] = 0;
			cal += calculate(b,n);
		}
	}
	return cal;
} 
int main(){
	int n;
	cin>>n;
	double sum;
	double a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sum = fun(a,n);
	printf("%.2f",sum);
	return 0;
}
