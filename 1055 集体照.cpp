#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class stu{
	public:
		int height;
		char name[99];
};
//这个排序函数兼顾了身高和名字的二次排序 
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
		if(i==0){
			int numofRow = n/row+n%row;
			int middle = numofRow/2+1;
			string myrow[numofRow];
			myrow[middle-1]= sortedStu[j++].name;
			//分为左右，便于存入字符数组中 
			int right = middle;
			int left = middle-2;
			while(left!=-1||right!=numofRow){
				if(left>=0){
					myrow[left--] = sortedStu[j++].name;
				}
				if(right<numofRow){
					myrow[right++] = sortedStu[j++].name;
				}
			}
			if(left==-1&&right==numofRow){
				for(int k=0;k<numofRow;k++){
					cout<<myrow[k];
					if(k!=numofRow-1)
						cout<<" ";
				}
				cout<<endl;
			}
		}else{
			int numofRow = n/row;
			int middle = numofRow/2+1;
			string myrow[numofRow];
			myrow[middle-1]= sortedStu[j++].name;
			//分为左右，便于存入字符数组中 
			int right = middle;
			int left = middle-2;
			while(left!=-1||right!=numofRow){
				if(left>=0){
					myrow[left--] = sortedStu[j++].name;
				}
				if(right<numofRow){
					myrow[right++] = sortedStu[j++].name;
				}
			}
			if(left==-1&&right==numofRow){
				for(int k=0;k<numofRow;k++){
					cout<<myrow[k];
					if(k!=numofRow-1)
						cout<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
