#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<string> hand;
	vector<string> eye;
	vector<string> mouth;
	string s;
	for(int i=0;i<3;i++){
		getline(cin,s);
		for(int j=0;j<s.length();j++){
			if(s[j]=='['){
				for(int k=j+1;k<s.length();k++){
					if(s[k]==']'){
						switch(i){
							//调用substr时一定要注意这里调用的substr(a,b)中a是起始位置，但b并非终止位置，而是截取字符数 
							case 0:hand.push_back(s.substr(j+1,k-j-1));break;
							case 1:eye.push_back(s.substr(j+1,k-j-1));break;
							case 2:mouth.push_back(s.substr(j+1,k-j-1));break;
							default:break;
						}
						break;
					}
				}
			}
		}
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a[5];
		bool isExist = true;
		for(int j=0;j<5;j++){
			cin>>a[j];
			if(a[j]<=0)
				isExist = false;
		}
		if(a[0]>=hand.size()||a[1]>=eye.size()||a[2]>=mouth.size()||a[3]>=eye.size()||a[4]>=hand.size())
				isExist = false;
		if(isExist){
			cout<<hand[a[0]-1]<<"("<<eye[a[1]-1]<<mouth[a[2]-1]<<eye[a[3]-1]<<")"<<hand[a[4]-1]<<endl;
		}else{
			cout<<"Are you kidding me? @\\/@"<<endl;
		}
	}
	return 0; 
} 
