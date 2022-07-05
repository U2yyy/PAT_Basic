#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin>>s;
	int cnt = 0;
	//下面是暴力求解的解法，会造成三个测试点超时，也算是意料之中 
	/*for(int i=0;i<s.length();i++){
		if(s[i]=='P'){
			for(int j=i+1;j<s.length();j++){
				if(s[j]=='A'){
					for(int k=j+1;k<s.length();k++){
						if(s[k]=='T'){
							cnt++;
							break;
						}
					}
				}
			}
		}
	}*/
	//下面的解法已经明白了可以利用每个A的前P数量和后T数量相乘得到，但仍然没有改变时间复杂度过高的事实 
	/*
	int numP = 0;
	int numT = 0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='A'){
			for(int j=0;j<i;j++){
				if(s[j]=='P')
					numP++;
			}
			for(int k=i+1;k<s.length();k++){
				if(s[k]=='T')
					numT++;
			}
			cnt += numP*numT;
			numP = 0;
			numT = 0;
		}
	}
	*/
	//下面是看了柳神的博客之后明白的思路，不得不承认确实非常灵性
	int numP = 0;
	int numT = 0;
	for(int i=0;i<s.length();i++){
		//只需要把T的数量全部先算出来 
		if(s[i]=='T')
			numT++;
	}
	for(int i=0;i<s.length();i++){
		if(numT==0)
			break;
		//每遍历到P时，就对numP进行加一操作 
		if(s[i]=='P')
			numP++;
		//每遍历到T时，就对numT进行减一操作 
		if(s[i]=='T')
			numT--;
		//cnt其实就是每个A前面的P和后面的T的数目的乘积 
		if(s[i]=='A')
			cnt = (cnt+(numP*numT)%1000000007)%1000000007;
	}
	cout<<cnt;
	return 0;
}
