#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int cnt = 1;
	vector<int> maxof;
	vector<int>::iterator itend;
	vector<long> arr;
	vector<long>::iterator it;
	long n,p;
	cin>>n>>p;
	for(int i=0;i<n;i++){
		long a;
		cin>>a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	for(it=arr.begin();it!=arr.end();it++){
		cnt = 1;
		if(arr.size()==1)
			break;
		for(vector<long>::iterator itafter=it+1;itafter!=arr.end();itafter++){
			if(*itafter<=*it*p)
				cnt++;
			else{
				if(itafter == it+1)
					cnt = 0;
				break;
			}
		}
		maxof.push_back(cnt);
	}
	if(arr.size()==1)
		cout<<"1";
	else{
		sort(maxof.begin(),maxof.end());
		itend = maxof.end()-1;
		cout<<*itend;
	}
	return 0;
} 
