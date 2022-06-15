#include<iostream>
using namespace std;
int main(){
	int num[10] = {0};
	//输入每个数的个数 
	for(int i=0;i<10;i++){
		cin>>num[i];
	}
	//因为0不能在最前面，所以在最前面的应该是除了0尽量小的数字，然后有0就输出0，没0就继续输出这个数字 
	//判断num[0]是否为0，分情况
	if(num[0] == 0){
		for(int i=1;i<10;i++){
			while(num[i]>0){
				cout<<i;
				num[i]--;
			}
		}
	}else{
		for(int i=1;i<10;i++){
			if(num[i]!=0){
				cout<<i;
				num[i]--;
				break;
			}
		}
		for(int i=0;i<10;i++){
			while(num[i]>0){
				cout<<i;
				num[i]--;
			}
		}
	}
	return 0;
}
