#include<iostream>
#include<iomanip>

int findLocation(int num,int &remain){
	int cmp = 1;
	int n = 1;
	//���num������������˵����һ�� 
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
	//��������������ʾ���� 
	int NumofRow = (2*loc-1);
	int NumofCol = (2*loc-1);
	while(NumofRow!=1){
		//����ո� 
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
