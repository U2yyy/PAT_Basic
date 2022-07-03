#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int sorted[n];
	for(int i=0;i<n;i++){
		cin>>sorted[i]; 
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(sorted[i]<=sorted[i+1])
			cnt++;
		else
			break;
	}
	bool isInsert = true;
	for(int i=cnt+1;i<n;i++){
		if(sorted[i]!=arr[i]){
			isInsert = false;
			break;
		}
	}
	if(isInsert){
		cout<<"Insertion Sort"<<endl;
		if(cnt+2<n)
			sort(sorted,sorted+cnt+2);
		else
			sort(sorted,sorted+n);
		for(int i=0;i<n;i++){
			cout<<sorted[i];
			if(i!=n-1)
				cout<<" ";
		}
	}
	else{
		cout<<"Merge Sort"<<endl;
		int temp = 0;
		while(temp<n){
			sort(sorted+temp,sorted+temp+2*(cnt+1));
			temp += 2*(cnt+1);
			if(temp+2*(cnt+1)>n)
				break;
		}
		for(int i=0;i<n;i++){
			cout<<sorted[i];
			if(i!=n-1)
				cout<<" ";
		}
	}
	return 0;
}
