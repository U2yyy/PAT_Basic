/*
�����ȫ������string�����ͺ͸��ַ�����ɵģ���Ը��֮Ϊstring���ʹ���� 
*/ 
#include<iostream>
#include<string>
using namespace std;
int main(){
	char NorP1,NorP2;
	cin>>NorP1;
	string numA;
	//�������ʹ�ö�����<string>��ĺ���getline()�����Ἣ��򻯹���
	getline(cin,numA,'E'); 
	//ʹ��string��find�����ҵ�С����λ��
	int pos = numA.find('.');
	//ʹ��erase����ĨȥС����
	numA.erase(pos,1); 
	cin>>NorP2;
	//�����ַ���������ָ��
	int index;
	cin>>index;
	if(NorP1 == '-')
		cout<<"-";
	if(NorP2 == '-'){
		cout<<"0.";
		while(index>1){
			cout<<"0";
			index--;
		}
		cout<<numA; 
	}else if(NorP2 == '+'){
		//ʹ��length�����ҵ�С�����������ĸ���
		int pLength = numA.length()-1;
		//������Ҫ�����������һ����С����������ֱ�ָ��������С��������������������С�����
		index -= pLength;
		if(index>=0){
			cout<<numA;
			while(index>0){
				cout<<"0";
				index--;
			}
		}else{
			//ʹ��insert������С�����ٲ����ȥ
			numA.insert(numA.length()+index,1,'.');
			cout<<numA; 
		}
	}
	return 0;
}
