#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//������ 
int cmp(int a,int b){
	return a>b;
}
int main(){
    int num[10000] = {0}; 
    int n;
    cin>>n;
    //�ٴ���һ�������������ڴ洢���������
	int prt[n]; 
    vector<int>cover;
    vector<int>::iterator it;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        //����������ִ������������
		prt[i] = number; 
        while(number!=1){
            if(number%2 == 0){
                number /= 2;
                //��num[number]��Ϊ1��ʾ�Ѿ������ǹ� 
                num[number] = 1;
            }else{
                number = (3*number+1)/2;
                //��num[number]��Ϊ1��ʾ�Ѿ������ǹ� 
                num[number] = 1;
            }
        }
    }
    //�������ǵ���ȫ��ѹ��cover vector������ 
    for(int i=0;i<10000;i++){
        if(num[i]==1)
            cover.push_back(i);
    }
    //�����������ж�����������Ƿ񱻸���,�ٴ����µ�������
	int newarr[n] = {0};
	int j=0;
	for(int i=0;i<n;i++){
		bool flag = false;
		for(it=cover.begin();it!=cover.end();it++){
			if(prt[i] == *it){
				flag = true;
				break;
			}
		}
		//���δ������������������� 
		if(flag == false)
			newarr[j++] = prt[i];
	}
	//��������Ԫ�ؽ��дӴ�С����
	sort(newarr,newarr+n,cmp);
	//���
	int i = 0;
	while(newarr[i] != 0){
		cout<<newarr[i++];
		if(newarr[i]!=0)
			cout<<" ";
	} 
    return 0;
}
