#include<iostream>
#include<string>
using namespace std;
//������� 
void myPrint(long long num,long long a,long long b){
	//���²��Ե���ͨ������������ף������ӷ�ĸ��Ϊ0�������Ӧ�ðѸ���������
	//ͬʱ������������ʱ��Ҳ�п��ܷ����÷�ĸС�����������������������Ҫ��ת���� 
	if(b<0){
		a = -a;
		b = -b;
	}
	//�������bΪ0ʱ��ʵ����Ҳ���Ƿ�ĸΪ0����ʱ���Inf���˳� 
	if(b==0){
		cout<<"Inf";
		return;
	}
	//���������ֻ�����С������С��0��ʱ�򣬸��������������� 
	if(num<0||a<0)
		cout<<"(";
	//���������ֲ�Ϊ0��ʱ�򣬾ͽ������ 
	if(num!=0){
		cout<<num;
		//�����Ӳ��ֲ�Ϊ0��ʱ��Ҳ�������(������Ԥ���ո�) 
		if(a!=0)
			cout<<" ";
	}
	if(a!=0)
		cout<<a<<"/"<<b;
	//ֻ���������ֺͷ��Ӷ���0�ķ�����������0 
	if(num==0&&a==0)
		cout<<"0";
	//��ȫ���� 
	if(num<0||a<0)
		cout<<")";		
}
void simplify(long long &num,long long &a,long long &b){
	if(b==0)
		return;
	long long temp;
	long long t1 = a,t2 = b;
	//��t1��t2ת�������� 
	if(a<0)
		t1 = -a;
	if(b<0)
		t2 = -b;
	//������ȷ��շת����ĳ����ͱ������������ǲ���long long���Ǿ������Ե�2�ܷ�ͨ���Ĺؼ� 
	long long m = t1>t2?t1:t2;
	long long n = t1<=t2?t1:t2;
	//��nΪ0ʱ������ĸΪ0��ֱ��return�� 
	if(n==0){
		a = 0;
		return;
	}
	//�����������ֵ�ֵ 
	num = a / b;
	//����������ֵ�ֵ�Ѿ�С��0����ô���Ӳ��ֿ϶�Ҳ�Ǹ����������Ϊ���� 
	if(num<0)
		a = -a;
	a %= b;
//	long long min = t1<t2?t1:t2;
//	for(int i=2;i<=min;i++) {
//		if(a%i==0&&b%i==0)
//			temp = i;
//	}

	//�����õ�շת���������ʱ�临�Ӷȣ���Ȼ���Ե�3��4���ᳬʱ 
	while(m%n != 0){
		temp = m;
		m = n;
		n = temp % n;
	}
	//��򻯷��ӷ�ĸ 
	a /= n;
	b /= n;
}
//�ӷ�ʵ�� 
void addition(long long a1,long long b1,long long a2,long long b2){
	long long num1 = 0;
	long long num2 = 0;
	long long child = a1 * b2 + a2 * b1;
	long long mother = b1 * b2;
	simplify(num1,a1,b1);
	simplify(num2,a2,b2);
	myPrint(num1,a1,b1);
	cout<<" + ";
	myPrint(num2,a2,b2);
	cout<<" = ";
	long long num = 0;
	simplify(num,child,mother);
	myPrint(num,child,mother);
	cout<<endl;
}
//����ʵ�� 
void subtraction(long long a1,long long b1,long long a2,long long b2){
	long long num1 = 0;
	long long num2 = 0;
	long long child = a1 * b2 - a2 * b1;
	long long mother = b1 * b2;
	simplify(num1,a1,b1);
	simplify(num2,a2,b2);
	myPrint(num1,a1,b1);
	cout<<" - ";
	myPrint(num2,a2,b2);
	cout<<" = ";
	long long num = 0;
	simplify(num,child,mother);
	myPrint(num,child,mother);
	cout<<endl;
}
//�˷�ʵ�� 
void mutiply(long long a1,long long b1,long long a2,long long b2){
	long long num1 = 0;
	long long num2 = 0;
	long long child = a1 * a2;
	long long mother = b1 * b2;
	simplify(num1,a1,b1);
	simplify(num2,a2,b2);
	myPrint(num1,a1,b1);
	cout<<" * ";
	myPrint(num2,a2,b2);
	cout<<" = ";
	long long num = 0;
	simplify(num,child,mother);
	myPrint(num,child,mother);
	cout<<endl;
}
//����ʵ�� 
void division(long long a1,long long b1,long long a2,long long b2){
	long long num1 = 0;
	long long num2 = 0;
	long long child = a1 * b2;
	long long mother = b1 * a2;
	simplify(num1,a1,b1);
	simplify(num2,a2,b2);
	myPrint(num1,a1,b1);
	cout<<" / ";
	myPrint(num2,a2,b2);
	cout<<" = ";
	long long num = 0;
	simplify(num,child,mother);
	myPrint(num,child,mother);
	cout<<endl;
}
int main(){
	long long a1,b1,a2,b2;
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	addition(a1,b1,a2,b2);
	subtraction(a1,b1,a2,b2);
	mutiply(a1,b1,a2,b2);
	division(a1,b1,a2,b2);
	return 0;
}
