#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> belowed;
	vector<int>::iterator it;
	int n;
	cin>>n;
	//尽管这个方法牺牲了空间，但带来了程序的简化 
	int List[1002] = {0};
	for(int i=0;i<n;i++){
		int list;
		int id;
		int score;
		scanf("%d-%d %d",&list,&id,&score);
		//用容器装列出的队伍名，是为了简化程序运算 
		belowed.push_back(list);
		List[list] += score;
	}
	int max = 0;
	int maxid = 0;
	for(it=belowed.begin();it!=belowed.end();it++){
		if(List[*it]>max){
			max = List[*it];
			maxid = *it;
		}
	}
	cout<<maxid<<" "<<max;
	return 0;
}
