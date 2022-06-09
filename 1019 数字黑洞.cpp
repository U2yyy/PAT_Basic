#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
//包含格式化流输出的文件
#include<iomanip> 
using namespace std;
/*这个题用到的思想比较特殊，我也是查了比较多的解法之后了解到这一解法
就是把整型变量转换为字符串型，然后再进行排序之后又变成整型*/
bool cmp(char a,char b){
	return a>b;
}
int main(){
	int num,num1,num2;
	cin>>num;
	char n1[5],n2[5];
	do{
		//使用sprintf函数将整型转换为字符型 
		sprintf(n1,"%04d",num);
		sprintf(n2,"%04d",num); 
		/*
		sort(n1[0],n1[4],cmp);
		sort(n2[0],n2[4]);//默认排序是从小到大排，如果想从大到小排，需要自己写一个bool函数 
		这一段又是一个错误，sort函数要求的是传入数组的地址，即引用传递，如果传a[]的话相当于是值传递（猜测） ，所以错误 
		*/
		//正确使用sort（）函数
		sort(n1,n1+4,cmp);
		sort(n2,n2+4);
		//使用atoi函数将字符型转换为整型
		num1 = atoi(n1);
		num2 = atoi(n2);
		num  = num1 - num2;
		//cout<<setw(4)<<setfill('0')<<num1<<" - "<<setw(4)<<setfill('0')<<num2<<" = "<<num<<endl;
		//上面这一段改为下面的C语言输出风格之后才完全通过在线平台判定，真是搞不懂为什么
		printf("%04d - %04d = %04d\n",num1,num2,num);
	}while(num != 6174&& num != 0); 
	return 0;
}
