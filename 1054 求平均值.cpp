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
		//此题的关键思路就是运用sscanf和sprintf函数，可以格式化读取和格式化输入，这对这个题至关重要 
		sscanf(a,"%lf",&temp);//sscanf能标准化读取，这里将字符串转换成了双精度型 
		sprintf(b,"%.2f",temp);//sprintf能标准化输入，这里将双精度型以小数点保存两位的形式存在b中 
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
