#include<iostream>
#include<iomanip>
#define CLK_TCK 100
using namespace std;
int main(){
	int C1,C2;
	cin>>C1>>C2;
	double time = 1.0*(C2-C1)/CLK_TCK;
	int h = time / 3600;
	int mytime;
	//对小数点后的秒进行四舍五入操作 
	if(time-(int)time>=0.5)
		mytime = (int)time + 1;
	else
		mytime = (int)time; 
	mytime %= 3600;
	int m = mytime / 60;
	int s = mytime % 60;
	cout<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<":"<<setw(2)<<setfill('0')<<s;
}
