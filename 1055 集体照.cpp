#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class stu{
	public:
		int height;
		char name[99];
};
//����������������ߺ����ֵĶ������� 
bool cmp(stu a,stu b){
	if(a.height==b.height)return a.name<b.name;
	return a.height>b.height;
}
int main(){
	int n;
	cin>>n;
	int row;
	cin>>row;
	stu myStu[n];
	vector<stu> sortedStu;
	for(int i=0;i<n;i++){
		cin>>myStu[i].name>>myStu[i].height;
		sortedStu.push_back(myStu[i]);
	}
	vector<stu>::iterator it;
	it = sortedStu.begin();
	sort(it,it+sortedStu.size(),cmp);
	int j = 0;
	for(int i=0;i<row;i++){
		int middle = row/2+1;
		char row[n/row+n%row][99] = {0};
		row [middle] = sortedStu[j++];
		//��Ϊ���ң����ڴ����ַ������� 
		int right = middle+1;
		int left = middle-1;
	}
}
