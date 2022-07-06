#include<iostream>
#include<string> 
using namespace std;
class stuID{
public:
	char ID[17];
	int Shiji;
	int Kaoshi; 
};
//利用结构体或是类能较为简单地解出来这道题，就不写过多的题解了 
int main(){
	int n;
	cin>>n;
	stuID stu[n];
	for(int i=0;i<n;i++){
		scanf("%s %d %d",stu[i].ID,&stu[i].Shiji,&stu[i].Kaoshi);
	}
	int checkNum;
	cin>>checkNum;
	for(int i=0;i<checkNum;i++){
		int temp;
		cin>>temp;
		for(int j=0;j<n;j++){
			if(temp==stu[j].Shiji){
				cout<<stu[j].ID<<" "<<stu[j].Kaoshi;
			if(i!=checkNum-1)
				cout<<endl;
			break;
			}
		}
	}
	return 0;
}
