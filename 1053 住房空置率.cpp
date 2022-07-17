#include<iostream>
using namespace std;
int main(){
	//挑了个简单题做一做，下乡不大方便 
	int n;
	double e;
	int D;
	cin>>n>>e>>D;
	int mayEmp = 0;
	int emp = 0;
	for(int i=0;i<n;i++){
		int K;
		cin>>K;
		int temp = 0;
		for(int j=0;j<K;j++){
			double E;
			cin>>E;
			if(E<e){
				temp++;
			}
		}
		if(temp>K/2){
			mayEmp++;
			if(K>D){
				mayEmp--;
				emp++;
			}
		}
	}
	double R1 = mayEmp*100.0/n;
	double R2 = emp*100.0/n;
	printf("%.1f",R1);
	cout<<"% ";
	printf("%.1f",R2);
	cout<<"%";
	return 0;
}
