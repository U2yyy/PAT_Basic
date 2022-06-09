#include<iostream>
#include<algorithm>
using namespace std;
typedef struct{
	double K;
	double S;
	double D; 
}makeyuebing;
double maxof(makeyuebing *date,int n,int *maxi){
	double maxnum = 0;
	int i;
	for(i=0;i<n;i++){
		if(date[i].D > maxnum){
			maxnum = date[i].D;
			*maxi = i;
		}
	}
	date[*maxi].D = 0;
	return maxnum;
}
int main(){
	int n,max;
	double num[1000];
	cin>>n>>max;
	makeyuebing yuebing[1000];
	for(int i=0;i<n;i++){
		cin>>yuebing[i].K; 
	}
	for(int i=0;i<n;i++){
		cin>>yuebing[i].S;
		yuebing[i].D = yuebing[i].S / yuebing[i].K;
	}
	int maxi = 0;
	double W = 0;
	double maxnow = maxof(yuebing,n,&maxi);
	do{
		if(yuebing[maxi].K>max){
			W += maxnow*(max);
			max = 0;
		}else{
			W += maxnow*(yuebing[maxi].K);
			max = max-yuebing[maxi].K;
		}
		maxnow = maxof(yuebing,n,&maxi);
	}while(max!=0);
	printf("%.2f",W);
}
