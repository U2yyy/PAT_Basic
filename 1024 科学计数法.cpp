/*
这个题全部是用string的类型和各种方法完成的，我愿称之为string类型大调用 
*/ 
#include<iostream>
#include<string>
using namespace std;
int main(){
	char NorP1,NorP2;
	cin>>NorP1;
	string numA;
	//这里可以使用定义在<string>里的函数getline()，将会极大简化过程
	getline(cin,numA,'E'); 
	//使用string的find方法找到小数点位置
	int pos = numA.find('.');
	//使用erase方法抹去小数点
	numA.erase(pos,1); 
	cin>>NorP2;
	//定义字符串用来存指数
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
		//使用length方法找到小数点后面的数的个数
		int pLength = numA.length()-1;
		//这里又要分两种情况，一种是小数点后面数字比指数次数还小的情况，这种情况是仍有小数点的
		index -= pLength;
		if(index>=0){
			cout<<numA;
			while(index>0){
				cout<<"0";
				index--;
			}
		}else{
			//使用insert方法把小数点再插入进去
			numA.insert(numA.length()+index,1,'.');
			cout<<numA; 
		}
	}
	return 0;
}
