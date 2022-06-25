#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	//错误用例直接退出 
	if(n==0)
		return 0; 
	int sch[n] = {0};
	for(int i=0;i<n;i++){
		int IDnum,score;
		cin>>IDnum>>score;
		sch[IDnum-1] += score;//直接采用给对应数组加值的方法，避免使用结构体 
	}
	int maxnum = 1;
	int max = sch[0];
	for(int i=0;i<n;i++){
		if(sch[i]>max){
			max = sch[i];
			maxnum = i+1;//maxnum实际上是i+1 
		}
	}
	cout<<maxnum<<" "<<max;
	return 0;
}
