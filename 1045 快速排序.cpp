#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> myNum;
	vector<int> afterCheck;
	vector<int>::iterator it;
	vector<int>::iterator beforeit;
	vector<int>::iterator afterit;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		myNum.push_back(a);
	}
	int cnt = 0;
	for(it=myNum.begin();it!=myNum.end();it++){
		bool flag = true;
		beforeit = it;
		afterit = it;
		while(beforeit!=myNum.begin()){
			beforeit--;
			if(*beforeit>*it){
				flag = false;
				break;
			}
		}
		while(afterit!=myNum.end()-1){
			afterit++;
			if(*afterit<*it){
				flag = false;
				break;
			}
		}
		if(flag){
			cnt++;
			afterCheck.push_back(*it);
		}
	}
	sort(afterCheck.begin(),afterCheck.end()-1);
	cout<<cnt<<endl; 
	for(it=afterCheck.begin();it!=afterCheck.end();it++){
		cout<<*it;
		if(it!=afterCheck.end()-1)
			cout<<" ";
	}
	return 0;
}
