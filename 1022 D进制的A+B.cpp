#include<iostream>
#include<vector>
using namespace std;
int main(){
	int A,B,D;
	vector<int>outcome;
	cin>>A>>B>>D;
	int n = A + B;
	//改进后发现是n=0时输出不正确 
	if(n == 0){
		cout<<"0";
		return 0;
	}
	for(;n>0;){
		outcome.push_back(n%D);
		n /= D;
	}
	for(int i=outcome.size()-1;i>=0;i--){
		cout<<outcome[i];
	}
	return 0;
}
