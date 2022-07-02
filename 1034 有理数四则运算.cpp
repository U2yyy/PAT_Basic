#include<iostream>
#include<string>
using namespace std;
//输出操作 
void myPrint(long long num,long long a,long long b){
	//导致测试点四通不过的罪魁祸首，即分子分母都为0的情况下应该把负号消除掉
	//同时做除法操作的时候，也有可能发生让分母小于零的情况，这两种情况都需要反转符号 
	if(b<0){
		a = -a;
		b = -b;
	}
	//当这里的b为0时，实际上也就是分母为0，此时输出Inf并退出 
	if(b==0){
		cout<<"Inf";
		return;
	}
	//当整数部分或者是小数部分小于0的时候，给有理数加上括号 
	if(num<0||a<0)
		cout<<"(";
	//当整数部分不为0的时候，就进行输出 
	if(num!=0){
		cout<<num;
		//当分子部分不为0的时候，也进行输出(这里是预留空格) 
		if(a!=0)
			cout<<" ";
	}
	if(a!=0)
		cout<<a<<"/"<<b;
	//只有整数部分和分子都是0的分数才真正是0 
	if(num==0&&a==0)
		cout<<"0";
	//补全括号 
	if(num<0||a<0)
		cout<<")";		
}
void simplify(long long &num,long long &a,long long &b){
	if(b==0)
		return;
	long long temp;
	long long t1 = a,t2 = b;
	//把t1与t2转换成正数 
	if(a<0)
		t1 = -a;
	if(b<0)
		t2 = -b;
	//这里是确定辗转相除的除数和被除数，这里是不是long long型是决定测试点2能否通过的关键 
	long long m = t1>t2?t1:t2;
	long long n = t1<=t2?t1:t2;
	//当n为0时，即分母为0，直接return掉 
	if(n==0){
		a = 0;
		return;
	}
	//计算整数部分的值 
	num = a / b;
	//如果整数部分的值已经小于0，那么分子部分肯定也是负数，将其改为正数 
	if(num<0)
		a = -a;
	a %= b;
//	long long min = t1<t2?t1:t2;
//	for(int i=2;i<=min;i++) {
//		if(a%i==0&&b%i==0)
//			temp = i;
//	}

	//这是用的辗转相除法降低时间复杂度，不然测试点3、4都会超时 
	while(m%n != 0){
		temp = m;
		m = n;
		n = temp % n;
	}
	//最简化分子分母 
	a /= n;
	b /= n;
}
//加法实现 
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
//减法实现 
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
//乘法实现 
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
//除法实现 
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
