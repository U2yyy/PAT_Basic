#include<iostream>
using namespace std;
struct peo{
	int numB;
	int numJ;
	int numC;
	int sheng;
	int fu;
	int ping;
};
void init(struct peo *date){
	date->fu = 0;
	date->numB = 0;
	date->numJ = 0;
	date->numC = 0;
	date->ping = 0;
	date->sheng = 0;
}
char max(struct peo *date){
	char B = 'B';
	char J = 'J';
	char C = 'C';
	//�ҳ�������ôд�Ļ���һ�ѱȽ�С������������B��զ�죬�����������ָ�����©���ٳ� 
//	if(date->numB == date->numC)
//		C = B;
//	if(date->numB == date->numJ)
//		J = B;
	//�������>�ĳ�>=���Ϳ�������������ѱ� 
	int maxnum = date->numB >= date->numC ? date->numB : date->numC;
	char max = date->numB >= date->numC ? B : C;
	max = maxnum >= date->numJ ? max : J;
	return max;
}
int main(){
	int n;
	cin>>n;
	char JIA,YI;
	struct peo J;
	struct peo Y;
	init(&J);
	init(&Y);
	for(int i=0;i<n;i++){
		cin>>JIA>>YI;
		if(JIA==YI){
			J.ping++;
			Y.ping++;
		}else if(JIA == 'B' && YI == 'C'){
			J.sheng++;
			Y.fu++;
			J.numB++;
		}else if(JIA == 'C' && YI == 'J'){
			J.sheng++;
			Y.fu++;
			J.numC++;
		}else if(JIA == 'J' && YI == 'B'){
			J.sheng++;
			Y.fu++;
			J.numJ++;
		}else if(JIA == 'B' && YI == 'J'){
			J.fu++;
			Y.sheng++;
			Y.numJ++;
		}else if(JIA == 'C' && YI == 'B'){
			J.fu++;
			Y.sheng++;
			Y.numB++;
		}else if(JIA == 'J' && YI == 'C'){
			J.fu++;
			Y.sheng++;
			Y.numC++;
		}			
	}
	cout<<J.sheng<<" "<<J.ping<<" "<<J.fu<<endl;
	cout<<Y.sheng<<" "<<Y.ping<<" "<<Y.fu<<endl;
	cout<<max(&J)<<" "<<max(&Y);
	return 0;
}
