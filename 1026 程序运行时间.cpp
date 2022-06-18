#include<iostream>
#include<iomanip>

int findLocation(int num,int &remain){
	int cmp = 1;
	int n = 1;
	//如果num连三都不到，说明就一行 
	if(num<3){
		remain = num - 1;
		return n;
	}
	while(cmp<=num){
		remain = num - cmp;
		cmp += (2*n+1)*2;
		n++;
	}
	return n-1; 
}
using namespace std;
int main(){
	int num;
	int remain;
	char ch;
	cin>>num>>ch;
	int loc = findLocation(num,remain);
	//把行数和列数表示出来 
	int NumofRow = (2*loc-1);
	int NumofCol = (2*loc-1);
	while(NumofRow!=1){
		//输出空格 
		for(int i=0;i<(NumofCol-NumofRow)/2;i++){
			cout<<" ";
		}
		for(int i=0;i<NumofRow;i++){
			cout<<ch;
		}
		cout<<endl;
		NumofRow -= 2;
	}
	while(NumofRow<=NumofCol){
		for(int i=0;i<(NumofCol-NumofRow)/2;i++){
			cout<<" ";
		}
		for(int i=0;i<NumofRow;i++){
			cout<<ch;
		}
		cout<<endl;
		NumofRow += 2;
	}
	cout<<remain;
}
