#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	//��������ֱ���˳� 
	if(n==0)
		return 0; 
	int sch[n] = {0};
	for(int i=0;i<n;i++){
		int IDnum,score;
		cin>>IDnum>>score;
		sch[IDnum-1] += score;//ֱ�Ӳ��ø���Ӧ�����ֵ�ķ���������ʹ�ýṹ�� 
	}
	int maxnum = 1;
	int max = sch[0];
	for(int i=0;i<n;i++){
		if(sch[i]>max){
			max = sch[i];
			maxnum = i+1;//maxnumʵ������i+1 
		}
	}
	cout<<maxnum<<" "<<max;
	return 0;
}
