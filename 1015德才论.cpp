#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct stu{
    int id;
    int descore;
    int caiscore;
}; 
vector<struct stu> decaijianbei;
vector<struct stu> debeicaibubei;
vector<struct stu> deshengcai;
vector<struct stu> decaijianbubei;
int judgement(struct stu *mystu,const int lowscore, const int highscore,int n){
	int amount = 0;
	for(int i=0;i<n;i++){
		if(mystu[i].caiscore>=highscore&&mystu[i].descore>=highscore){
			decaijianbei.push_back(mystu[i]);
			amount++;
		}else if(mystu[i].descore>=highscore&&mystu[i].caiscore>=lowscore&&mystu[i].caiscore<highscore){
			debeicaibubei.push_back(mystu[i]);
			amount++;
		}else if(mystu[i].caiscore<highscore&&mystu[i].caiscore<mystu[i].descore&&mystu[i].caiscore>=lowscore&&mystu[i].descore>=lowscore){
			deshengcai.push_back(mystu[i]);
			amount++;
		}else if(mystu[i].descore>=lowscore&&mystu[i].caiscore>=lowscore){
			decaijianbubei.push_back(mystu[i]);
			amount++;
		}
	}
	return amount;
}
bool LessSort(struct stu a,struct stu b){
	if(a.caiscore+a.descore != b.caiscore+b.descore)
		return (a.caiscore+a.descore > b.caiscore+b.descore);
	else if(a.descore != b.descore)
		return (a.descore > b.descore);
	else
		return (a.id < b.id);	
}
int main(){
    int n,lowscore,highscore;
    cin>>n>>lowscore>>highscore;
    struct stu mystu[n];
    for(int i=0;i<n;i++){
        cin>>mystu[i].id>>mystu[i].descore>>mystu[i].caiscore;
    }
    int passnum = judgement(mystu,lowscore,highscore,n);
    cout<<passnum<<endl;
	sort(decaijianbei.begin(),decaijianbei.end(),LessSort);
	sort(debeicaibubei.begin(),debeicaibubei.end(),LessSort);
	sort(deshengcai.begin(),deshengcai.end(),LessSort);
	sort(decaijianbubei.begin(),decaijianbubei.end(),LessSort);
    for(int i=0;i<decaijianbei.size();i++){
    	cout<<decaijianbei[i].id<<" "<<decaijianbei[i].descore<<" "<<decaijianbei[i].caiscore<<endl;
	}
	for(int i=0;i<debeicaibubei.size();i++){
    	cout<<debeicaibubei[i].id<<" "<<debeicaibubei[i].descore<<" "<<debeicaibubei[i].caiscore<<endl;
	}
	for(int i=0;i<deshengcai.size();i++){
    	cout<<deshengcai[i].id<<" "<<deshengcai[i].descore<<" "<<deshengcai[i].caiscore<<endl;
	}
	for(int i=0;i<decaijianbubei.size();i++){
    	cout<<decaijianbubei[i].id<<" "<<decaijianbubei[i].descore<<" "<<decaijianbubei[i].caiscore<<endl;
	}
//    cout<<passnum<<endl;
//    for(int i=0;i<n;i++){
//    	cout<<mystu[i].id<<mystu[i].descore<<mystu[i].caiscore<<endl;
//	}
    return 0;
}