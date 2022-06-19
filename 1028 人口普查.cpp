#include<iostream>
using namespace std;
struct Peo{
	char name[6];
	char birth[11];
	int year;
	int month;
	int day;
	bool ifExist;
};
int maxLoc(Peo *myPeo,int n){
	int max = 0;
		/*这一题似乎oj有检测你的结构体数组是否有效，如果你的这个结构体数组里面的数字是无效的，
	即使你下面用了一个if判断数字是否有效，并只输出有效数字仍然会判定错误，这是我觉得非常坑的一点 
	下面的这些for循环是为了让初始的maxnum和minnum指向有意义的值，但其实我已经用if判断能通过测试点0了
	看来即使是浙大的oj也无可避免会出现这些问题*/
//	for(int i=0;i<n;i++){
//		if(myPeo[i].ifExist==true){
//			max = i;
//			break;
//		}
//	}
	for(int i=0;i<n;i++){
		if(myPeo[i].ifExist == false)
			continue;
		if(myPeo[i].year<myPeo[max].year)
			max = i;
		else if(myPeo[i].year==myPeo[max].year&&myPeo[i].month<myPeo[max].month)
			max = i;
		else if(myPeo[i].year==myPeo[max].year&&myPeo[i].month==myPeo[max].month&&myPeo[i].day<myPeo[max].day)
			max = i;	
	}
	return max;
}
int minLoc(Peo *myPeo,int n){
	int min = 0;
//	for(int i=0;i<n;i++){
//		if(myPeo[i].ifExist==true){
//			min = i;
//			break;
//		}
//	}
	for(int i=0;i<n;i++){
		if(myPeo[i].ifExist == false)
			continue;
		if(myPeo[i].year>myPeo[min].year)
			min = i;
		else if(myPeo[i].year==myPeo[min].year&&myPeo[i].month>myPeo[min].month)
			min = i;
		else if(myPeo[i].year==myPeo[min].year&&myPeo[i].month==myPeo[min].month&&myPeo[i].day>myPeo[min].day)
			min = i;	
	}
	return min;
}
int main(){
	int n;
	int realn = 0;
	cin>>n;
	Peo myPeo[n];
	for(int i=0;i<n;i++){
		cin>>myPeo[i].name>>myPeo[i].birth;
		myPeo[i].ifExist = true;
		myPeo[i].year = (myPeo[i].birth[0]-'0')*1000+(myPeo[i].birth[1]-'0')*100+(myPeo[i].birth[2]-'0')*10+myPeo[i].birth[3]-'0';
		myPeo[i].month = (myPeo[i].birth[5]-'0')*10+myPeo[i].birth[6]-'0';
		myPeo[i].day = (myPeo[i].birth[8]-'0')*10+myPeo[i].birth[9]-'0';
		//判断是否是有效出生日期
		if(myPeo[i].year<2014&&myPeo[i].year>1814){
			realn++;
			continue;
		}
		if(myPeo[i].year==2014&&myPeo[i].month<9){
			realn++;
			continue;
		}
		if(myPeo[i].year==2014&&myPeo[i].month==9&&myPeo[i].day<=6){
			realn++;
			continue;
		}
		if(myPeo[i].year==1814&&myPeo[i].month>9){
			realn++;
			continue;
		}
		if(myPeo[i].year==1814&&myPeo[i].month==9&&myPeo[i].day>=6){
			realn++;	
			continue;		
		}
		myPeo[i].ifExist = false;
	}
	int maxNum = maxLoc(myPeo,n);
	int minNum = minLoc(myPeo,n);
	cout<<realn;
	if(myPeo[maxNum].ifExist==true)
		cout<<" ";
	/*这一题似乎oj有检测你的结构体数组是否有效，如果你的这个结构体数组里面的数字是无效的，
	即使你下面用了一个if判断数字是否有效，并只输出有效数字仍然会判定错误，这是我觉得非常坑的一点 */ 
	if(myPeo[maxNum].ifExist==true)
		cout<<myPeo[maxNum].name<<" ";
	if(myPeo[minNum].ifExist==true)	
		cout<<myPeo[minNum].name;
}
