#include<iostream>
#include<string> 
using namespace std;
class stuID{
public:
	char ID[17];
	int Shiji;
	int Kaoshi; 
};
//���ýṹ��������ܽ�Ϊ�򵥵ؽ��������⣬�Ͳ�д���������� 
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
