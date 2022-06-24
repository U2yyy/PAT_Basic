#include<iostream>
#include<string>
using namespace std;
//����հ�Cpp����Ͷ����ǿ���˽���һ�飬�������������õ��������������������� 
struct ID{
	char num[19];
	char checkcode;
	bool flag;
	//��ʼ��flag 
	void InitFlag(){
		flag = true;
	}
	//��num�������в�Ϊ���ֵ��ַ�����ȷ������Ч 
	void IsNum(){
		for(int i=0;i<17;i++){
			if(num[i]<'0'||num[i]>'9')
				flag = false;
		}
	}
	//����ĿҪ����м��� 
	int Code(){
		int sum = (num[0]-'0')*7+(num[1]-'0')*9+(num[2]-'0')*10+(num[3]-'0')*5+(num[4]-'0')*8+(num[5]-'0')*4+(num[6]-'0')*2+(num[7]-'0')*1+(num[8]-'0')*6+
		          (num[9]-'0')*3+(num[10]-'0')*7+(num[11]-'0')*9+(num[12]-'0')*10+(num[13]-'0')*5+(num[14]-'0')*8+(num[15]-'0')*4+(num[16]-'0')*2;
		return sum%11;
	}
	//�Ƚ�У���� 
	void IsOK(int code){
		char relcode;
		switch(code){
			case 0:
				relcode = '1';break;
			case 1:
				relcode = '0';break;
			case 2:
				relcode = 'X';break;
			case 3:
				relcode = '9';break;
			case 4:
				relcode = '8';break;
			case 5:
				relcode = '7';break;
			case 6:
				relcode = '6';break;
			case 7:
				relcode = '5';break;
			case 8:
				relcode = '4';break;
			case 9:
				relcode = '3';break;
			case 10:
				relcode = '2';break;	
		}
		if(relcode!=checkcode)
			flag = false;
	}
};
int main(){
	int n;
	cin>>n;
	ID myTest[n];
	for(int i=0;i<n;i++){
		cin>>myTest[i].num;
		//��ʼ��flag 
		myTest[i].InitFlag();
		//�ж��Ƿ�Ϊ���� 
		myTest[i].IsNum();
		//��У���븳��myTest[i]���е�checkcode��Ա 
		myTest[i].checkcode = myTest[i].num[17];
		//��code�������հ�����Ŀ��Ȩ�����ȡģ��ֵ 
		int code = myTest[i].Code();
		//�ж����code������У�����Ƿ���� 
		myTest[i].IsOK(code);
	}
	//����һ��bool���������ж��Ƿ�ȫ��ͨ�� 
	bool Allpassed = true;
	for(int i=0;i<n;i++){
		//ֻҪ��һ��myTest����ͨ�����Ͱ�Allpassed��Ϊfalse 
		if(myTest[i].flag == false){
			Allpassed = false;
			break;
		}
	}
	if(Allpassed)
		cout<<"All passed";
	else{
		for(int i=0;i<n;i++){
			if(myTest[i].flag == false)
				cout<<myTest[i].num<<endl;
		}
	}
	return 0;
}
