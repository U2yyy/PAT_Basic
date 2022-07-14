#include<iostream>
//这个题本质上是个数学问题，记录一下我犯的蠢，数数字个数都没数对，导致找规律没找出来 
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
