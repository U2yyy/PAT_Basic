#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> belowed;
	vector<int>::iterator it;
	int n;
	cin>>n;
	//����������������˿ռ䣬�������˳���ļ� 
	int List[1002] = {0};
	for(int i=0;i<n;i++){
		int list;
		int id;
		int score;
		scanf("%d-%d %d",&list,&id,&score);
		//������װ�г��Ķ���������Ϊ�˼򻯳������� 
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
