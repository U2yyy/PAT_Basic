#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	//������������ÿһ���ַ����е���ĸ���ִ����� 
	int a[1000] = {0};
	int b[1000] = {0};
	for(int i=0;i<s1.length();i++){
		a[s1[i]]++;
	}
	for(int i=0;i<s2.length();i++){
		b[s2[i]]++;
	}
	int num = 0;
	//���s2�е�ĳ���ַ���s1��û�У��ͽ���Ϊ0��num-1 
	for(int i=0;i<s2.length();i++){
		if(a[s2[i]]!=0){
			a[s2[i]]--;
		}else{
			num--;
		}
	}
	//����isComleteΪfalse�������Ƿ������⴮���� 
	bool isComplete = false; 
	//ֻ���ڲ�ȱ��ʱ������򣬼�num == 0 ��ʱ�� 
	if(num == 0)
		isComplete = true;
	//Ҳֻ���ڲ�ȱ��ʱ��ͳ�ƶ��˶������Ӳ������� 
	if(isComplete){
		for(int i=0;i<s1.length();i++){
			if(b[s1[i]]!=0){
				b[s1[i]]--;
			}else{
				num++;
			}
		}
	}
	if(num>=0){
		cout<<"Yes "<<num;
	}else{
		cout<<"No "<<-num;
	}
	return 0;
}
