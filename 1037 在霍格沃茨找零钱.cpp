#include<iostream>
using namespace std;
struct Money{
	int Galleon;
	int Sickle;
	int Knut;
};
//�ж�ǰ���Ƿ�Ⱥ��ߴ�ĺ��� 
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
	//��ʽ�����룬��ȡֵ 
	scanf("%d.%d.%d",&P.Galleon,&P.Sickle,&P.Knut);
	scanf("%d.%d.%d",&A.Galleon,&A.Sickle,&A.Knut);
	Money back;
	//��Զ�Ǵ��С 
	if(isBigger(A,P)){
		back.Galleon = A.Galleon - P.Galleon;
		back.Sickle = A.Sickle - P.Sickle; 
		back.Knut = A.Knut - P.Knut;
	}else{
		back.Galleon = P.Galleon - A.Galleon;
		back.Sickle = P.Sickle - A.Sickle; 
		back.Knut = P.Knut - A.Knut;
	}
	//�����Ľ�λ����ʵ�� 
	if(back.Knut<0){
		back.Knut += 29;
		back.Sickle -= 1;
	}
	if(back.Sickle<0){
		back.Sickle += 17;
		back.Galleon -= 1;
	}
	//��Ҫ����ֵ���ϸ���  
	if(!isBigger(A,P))
		cout<<"-";
	cout<<back.Galleon<<"."<<back.Sickle<<"."<<back.Knut;
	return 0;
}
