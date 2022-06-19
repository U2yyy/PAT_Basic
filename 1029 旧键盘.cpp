#include<iostream>
using namespace std;
void addfortimes(int *a,char *b){
	for(int i=0;b[i]!='\0';i++){
		a[b[i]]=1;
	} 
}
void judge(int *a,char *b,int *c){
	int k = 0;
	for(int i=48;i<126;i++){
		if(a[i]==1){
			bool flag = true;
			for(int j=0;b[j]!='\0';j++){
				if(b[j]==i){
					flag = false;
					break;
				}
			}
			if(flag==true)
				c[k++] = i;
		}
	} 
}
void judgeagain(int *a){
		//如果大小写字母同时出现，应当只保留大写字母，若小写字母出现，则变为大写字母 
	for(int i=0;i<80;i++){
		if(a[i]!=0&&a[i]>='a'){
			for(int j=0;j<80;j++){
				if(a[j]==a[i]-32){
					a[i] = 0;
				}
			}
			a[i] -= 32;	
		}
	}
} 
int main(){
	//定义整型数组用来存字符出现次数 
	int times[126] = {0};
	//定义一个整型数组用来存最终坏的字符的ASCII码 
	int arr[80] = {0}; 
	char oricha[81];
	char cha[81];
	cin>>oricha>>cha;
	addfortimes(times,oricha);
	judge(times,cha,arr);
	judgeagain(arr);
	for(int i=0;i<80;i++){
		if(arr[i]>=0)
			cout<<char(arr[i]);
	}
	return 0;
} 
