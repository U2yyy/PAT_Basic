//此题涉及到复数的极坐标与直角坐标转化，实际上根据题意来就能解题 
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	double R1,P1,R2,P2;
	cin>>R1>>P1>>R2>>P2;
	double x1 = R1*cos(P1);
	double y1 = R1*sin(P1);
	double x2 = R2*cos(P2);
	double y2 = R2*sin(P2);
	double A = x1*x2-y1*y2;
	double B = x1*y2+x2*y1;
	double myA = A,myB = B;
	if(A<0)
		myA = -A;
	if(B<0)
		myB = -B; 
	if(myA<0.01)
		A = 0;
	if(myB<0.01)
		B = 0;
	if(B>=0){
		printf("%.2f+%.2fi",A,B);
	}else{
		printf("%.2f-%.2fi",A,-B);
	}
	return 0;
} 
