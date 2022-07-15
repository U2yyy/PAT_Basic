#include<iostream>
#include<vector>
using namespace std;
void matrix(int num,int &m,int &n){
	int a[num],b[num],c[num];
	for(int i=0;i<num;i++){
		a[i] = -1;
		b[i] = -2;
		c[i] = 99999;
	}
	int j = 0;
	for(int i=1;i<=num;i++){
		if(num%i==0){
			a[j] = i;
			b[j++] = num/i;
		}
	}
	int min = 99999;
	int minnum = 0;
	for(int i=0;i<num;i++){
		if(a[i]>0&&b[i]>0){
			c[i] = a[i] - b[i];
		}
		if(c[i]<=min&&c[i]>=0){
			min = c[i];
			minnum = i;
		}
	}
	m = a[minnum];
	n = b[minnum];
}
int main(){
	int num;
	cin>>num;
	int m,n;
	matrix(num,m,n);
	int myMat[m][n];
	bool isFilled[m][n] = {false};
	int i = 0;
	int j = 0;
	int k = 0;
	int h = 0;
	int cnt = 0;
	while(cnt<=num){
		while(j!=n&&isFilled[i][j]==false){
			cnt++;
			int temp;
			cin>>temp;
			myMat[i][j++] = temp;
			isFilled[k][h++] = true;
		}
		while(i!=m&&isFilled[i][j]==false){
			cnt++;
			int temp;
			cin>>temp;
			myMat[i++][j] = temp;
			isFilled[k++][h] = true;
		}
		while(j!=-1&&isFilled[i][j]==false){
			cnt++;
			int temp;
			cin>>temp;
			myMat[i][j--] = temp;
			isFilled[k][h--] = true;
		}
		while(i!=-1&&isFilled[i][j]==false){
			cnt++;
			int temp;
			cin>>temp;
			myMat[i--][j] = temp;
			isFilled[k--][h] = true;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<myMat[i][j];
			if(j!=n-1)
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
