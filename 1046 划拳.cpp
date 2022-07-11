#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int jia = 0;
	int yi = 0;
	for(int i=0;i<n;i++){
		int temp1,temp2,a,b;
		cin>>temp1>>a>>temp2>>b;
		int sum = temp1 + temp2;
		if(sum==a&&sum!=b)yi++;
		if(sum==b&&sum!=a)jia++;
	}
	cout<<jia<<" "<<yi;
	return 0;
}
