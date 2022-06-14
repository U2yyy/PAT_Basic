#include<iostream>
#include<cstring>
using namespace std;
int main(){
	//这里的N必须是N[1002]而不是N[1001]我个人还未理解，毕竟字符串数组只需要留一个空 
	//6.14 14:29更新，初始化时虽然把所有的元素赋为#了，但是在输入1000个数的时候，会自动把N[1000]变为'\0'作为标记串结束，因此判断应为N[i] !='\0'
	char N[1002];
	//将N里面所有的值赋为'#' 
	memset(N,'#',sizeof(N));
	//输入数字（实际上转为字符了） 
	cin >> N;
	//将num数组元素全部初始化为0，似乎只有0能这样操作，别的值只会初始化第一个数组元素
	//这里的num数组表示位数 
	int num[10] = {0};
//	for(int i=0;N[i]!='#';i++){
	for(int i=0;N[i]!='\0';i++){ 
		switch(N[i]){
			case '0':
				num[0]++;break;
			case '1':
				num[1]++;break;
			case '2':
				num[2]++;break;
			case '3':
				num[3]++;break;
			case '4':
				num[4]++;break;
			case '5':
				num[5]++;break;
			case '6':
				num[6]++;break;
			case '7':
				num[7]++;break;
			case '8':
				num[8]++;break;
			case '9':
				num[9]++;break;									
		}
	}
	//只要num数组元素不为0，我们就进行输出 
	for(int i=0;i<10;i++){
		if(num[i]!=0){
			cout<<i<<":"<<num[i]<<endl;
		}
	}
	return 0;
}
