#include<iostream>
#include<string>
using namespace std;
//今天刚把Cpp中类和对象的强大了解了一遍，正好这个题可以用到，就用类把这个题解出来把 
struct ID{
	char num[19];
	char checkcode;
	bool flag;
	//初始化flag 
	void InitFlag(){
		flag = true;
	}
	//若num数组中有不为数字的字符，则确定其无效 
	void IsNum(){
		for(int i=0;i<17;i++){
			if(num[i]<'0'||num[i]>'9')
				flag = false;
		}
	}
	//按题目要求进行计算 
	int Code(){
		int sum = (num[0]-'0')*7+(num[1]-'0')*9+(num[2]-'0')*10+(num[3]-'0')*5+(num[4]-'0')*8+(num[5]-'0')*4+(num[6]-'0')*2+(num[7]-'0')*1+(num[8]-'0')*6+
		          (num[9]-'0')*3+(num[10]-'0')*7+(num[11]-'0')*9+(num[12]-'0')*10+(num[13]-'0')*5+(num[14]-'0')*8+(num[15]-'0')*4+(num[16]-'0')*2;
		return sum%11;
	}
	//比较校验码 
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
		//初始化flag 
		myTest[i].InitFlag();
		//判断是否为数字 
		myTest[i].IsNum();
		//将校验码赋给myTest[i]类中的checkcode成员 
		myTest[i].checkcode = myTest[i].num[17];
		//用code变量接收按照题目加权运算和取模的值 
		int code = myTest[i].Code();
		//判断这个code变量和校验码是否相等 
		myTest[i].IsOK(code);
	}
	//定义一个bool类型用来判断是否全能通过 
	bool Allpassed = true;
	for(int i=0;i<n;i++){
		//只要有一个myTest不能通过，就把Allpassed设为false 
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
