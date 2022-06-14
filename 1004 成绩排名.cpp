#include<iostream>
using namespace std;
struct stu{
	char name[11];
	char num[11];
	int score;
};
void findLocation(struct stu *mystu,int &max,int &min,int n){
	for(int i=0;i<n;i++){
		if(mystu[i].score > mystu[max].score)
			max = i;
		if(mystu[i].score < mystu[min].score)
			min = i;	
	}
}
int main(){
	int n;
	cin>>n;
	struct stu mystu[n];
	for(int i=0;i<n;i++){
		cin>>mystu[i].name>>mystu[i].num>>mystu[i].score;
	}
	int max = 0;
	int min = 0;
	findLocation(mystu,max,min,n);
	cout<<mystu[max].name<<" "<<mystu[max].num<<endl;
	cout<<mystu[min].name<<" "<<mystu[min].num<<endl;
	return 0;
}

