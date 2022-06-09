#include<iostream>
#include<algorithm>
using namespace std;
//定义月饼的结构体 
typedef struct{
	double K;//K表示库存量 
	double S;//S表示商品总售价 
	double D;//D表示商品单价，即S/K 
}makeyuebing;
//这个函数中传入了一个结构体数组的指针，一个数组的最大长度值，和一个指向最大数组位置的指针
//目的是能每次找到最大的数组数之后返回它并删除它，便于下次寻找时不出现它（其实破坏了结构体内的封装）
//同时利用引用传递从而把指向最大数组位置的i也实时更新 
double maxof(makeyuebing *date,int n,int *maxi){
	double maxnum = 0;
	int i;
	for(i=0;i<n;i++){
		if(date[i].D > maxnum){
			maxnum = date[i].D;
			*maxi = i;
		}
	}
	//把这个最大数变成0，这其实破坏了数据，但还没有想到更好的办法（再copy一个结构体？那样也可以，但是这里不要求数据完整，因此就这样摆着做了） 
	date[*maxi].D = 0;
	return maxnum;
}
int main(){
	int n,max;
	cin>>n>>max;
	//定义结构体数组 
	makeyuebing yuebing[1000];
	//为每个数组元素的库存赋值 
	for(int i=0;i<n;i++){
		cin>>yuebing[i].K; 
	}
	//为每个数组的元素总售价赋值并计算出每个数组元素的单价 
	for(int i=0;i<n;i++){
		cin>>yuebing[i].S;
		yuebing[i].D = yuebing[i].S / yuebing[i].K;
	}
	//maxi是指向数组最大元素的指针 
	int maxi = 0;
	//W是商品总利润 
	double W = 0;
	double maxnow = maxof(yuebing,n,&maxi);
	//定义一个比较次数，比较次数是不可能多于n的，当大于n时我们退出循环
	int cmp = 0; 
	do{
		//如果这个最大单价的月饼库存比max还大，那么直接让单价和max相乘就得到总利润，然后把max赋为0即可 
		if(yuebing[maxi].K>max){
			W += maxnow*(max);
			max = 0;
			cmp++; 
		}else{//如果不是，那么就让这个最大单价的月饼库存与它的库存相乘得到总利润，然后让max减去它的库存 
			W += maxnow*(yuebing[maxi].K);
			max = max-yuebing[maxi].K;
			cmp++; 
		}
		maxnow = maxof(yuebing,n,&maxi);
		//当比较次数已经达到n时，直接退出，此时说明max真的很大，所有月饼库存加起来都没它大 
		if(cmp == n)
			break;
		//如果max不是那么大的话，那么max一定是会有某月饼库存比现在动态的max大的情况，那么max会被赋为0，这就是退出循环的条件 
	}while(max!=0);
	//按照题目要求输出该数 
	printf("%.2f",W);
}
