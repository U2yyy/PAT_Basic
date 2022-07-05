#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	//数组是用来存每一串字符串中的字母出现次数的 
	int a[1000] = {0};
	int b[1000] = {0};
	for(int i=0;i<s1.length();i++){
		a[s1[i]]++;
	}
	for(int i=0;i<s2.length();i++){
		b[s2[i]]++;
	}
	int num = 0;
	//如果s2中的某个字符在s1中没有，就将本为0的num-1 
	for(int i=0;i<s2.length();i++){
		if(a[s2[i]]!=0){
			a[s2[i]]--;
		}else{
			num--;
		}
	}
	//设置isComlete为false，表明是否能买这串项链 
	bool isComplete = false; 
	//只有在不缺的时候才能买，即num == 0 的时候 
	if(num == 0)
		isComplete = true;
	//也只有在不缺的时候统计多了多少珠子才有意义 
	if(isComplete){
		for(int i=0;i<s1.length();i++){
			if(b[s1[i]]!=0){
				b[s1[i]]--;
			}else{
				num++;
			}
		}
	}
	if(num>=0){
		cout<<"Yes "<<num;
	}else{
		cout<<"No "<<-num;
	}
	return 0;
}
