#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
//������ʽ����������ļ�
#include<iomanip> 
using namespace std;
/*������õ���˼��Ƚ����⣬��Ҳ�ǲ��˱Ƚ϶�Ľ֮ⷨ���˽⵽��һ�ⷨ
���ǰ����ͱ���ת��Ϊ�ַ����ͣ�Ȼ���ٽ�������֮���ֱ������*/
bool cmp(char a,char b){
	return a>b;
}
int main(){
	int num,num1,num2;
	cin>>num;
	char n1[5],n2[5];
	do{
		//ʹ��sprintf����������ת��Ϊ�ַ��� 
		sprintf(n1,"%04d",num);
		sprintf(n2,"%04d",num); 
		/*
		sort(n1[0],n1[4],cmp);
		sort(n2[0],n2[4]);//Ĭ�������Ǵ�С�����ţ������Ӵ�С�ţ���Ҫ�Լ�дһ��bool���� 
		��һ������һ������sort����Ҫ����Ǵ�������ĵ�ַ�������ô��ݣ������a[]�Ļ��൱����ֵ���ݣ��²⣩ �����Դ��� 
		*/
		//��ȷʹ��sort��������
		sort(n1,n1+4,cmp);
		sort(n2,n2+4);
		//ʹ��atoi�������ַ���ת��Ϊ����
		num1 = atoi(n1);
		num2 = atoi(n2);
		num  = num1 - num2;
		//cout<<setw(4)<<setfill('0')<<num1<<" - "<<setw(4)<<setfill('0')<<num2<<" = "<<num<<endl;
		//������һ�θ�Ϊ�����C����������֮�����ȫͨ������ƽ̨�ж������Ǹ㲻��Ϊʲô
		printf("%04d - %04d = %04d\n",num1,num2,num);
	}while(num != 6174&& num != 0); 
	return 0;
}
