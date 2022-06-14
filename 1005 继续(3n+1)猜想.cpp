#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//排序函数 
int cmp(int a,int b){
	return a>b;
}
int main(){
    int num[10000] = {0}; 
    int n;
    cin>>n;
    //再创建一个变量数组用于存储输入的数字
	int prt[n]; 
    vector<int>cover;
    vector<int>::iterator it;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        //将输入的数字存入变量数组中
		prt[i] = number; 
        while(number!=1){
            if(number%2 == 0){
                number /= 2;
                //将num[number]变为1表示已经被覆盖过 
                num[number] = 1;
            }else{
                number = (3*number+1)/2;
                //将num[number]变为1表示已经被覆盖过 
                num[number] = 1;
            }
        }
    }
    //将被覆盖的数全部压入cover vector容器中 
    for(int i=0;i<10000;i++){
        if(num[i]==1)
            cover.push_back(i);
    }
    //接下来就是判断输入的数字是否被覆盖,再存入新的数组中
	int newarr[n] = {0};
	int j=0;
	for(int i=0;i<n;i++){
		bool flag = false;
		for(it=cover.begin();it!=cover.end();it++){
			if(prt[i] == *it){
				flag = true;
				break;
			}
		}
		//如果未被覆盖则存入新数组中 
		if(flag == false)
			newarr[j++] = prt[i];
	}
	//对新数组元素进行从大到小排序
	sort(newarr,newarr+n,cmp);
	//输出
	int i = 0;
	while(newarr[i] != 0){
		cout<<newarr[i++];
		if(newarr[i]!=0)
			cout<<" ";
	} 
    return 0;
}
