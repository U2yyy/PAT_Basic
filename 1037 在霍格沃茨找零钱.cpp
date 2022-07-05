#include<iostream>
using namespace std;
struct Money{
	int Galleon;
	int Sickle;
	int Knut;
};
//判断前者是否比后者大的函数 
bool isBigger(Money bigger,Money smaller){
	bool flag = false;
	if(bigger.Galleon>smaller.Galleon){
		flag = true;
	}else if(bigger.Galleon==smaller.Galleon){
		if(bigger.Sickle>smaller.Sickle){
			flag = true;
		}else if(bigger.Sickle==smaller.Sickle){
			if(bigger.Knut>=smaller.Knut){
				flag = true;
			}
		}
	}
	return flag;
}
int main(){
	Money P,A;
	//格式化输入，读取值 
	scanf("%d.%d.%d",&P.Galleon,&P.Sickle,&P.Knut);
	scanf("%d.%d.%d",&A.Galleon,&A.Sickle,&A.Knut);
	Money back;
	//永远是大减小 
	if(isBigger(A,P)){
		back.Galleon = A.Galleon - P.Galleon;
		back.Sickle = A.Sickle - P.Sickle; 
		back.Knut = A.Knut - P.Knut;
	}else{
		back.Galleon = P.Galleon - A.Galleon;
		back.Sickle = P.Sickle - A.Sickle; 
		back.Knut = P.Knut - A.Knut;
	}
	//减法的借位操作实现 
	if(back.Knut<0){
		back.Knut += 29;
		back.Sickle -= 1;
	}
	if(back.Sickle<0){
		back.Sickle += 17;
		back.Galleon -= 1;
	}
	//需要给负值加上负号  
	if(!isBigger(A,P))
		cout<<"-";
	cout<<back.Galleon<<"."<<back.Sickle<<"."<<back.Knut;
	return 0;
}
