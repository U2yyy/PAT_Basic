/*
这个题也是一个自己做没有什么思路的题，昨天做了半天的结果是野指针一堆，到处乱指
今天看大佬的题解才知道静态链表这一概念，用这个可以很好的解决这个题目
*/
#include<iostream>
#include<algorithm>

#define SIZE 100000
using namespace std;

struct Node{
    int date;
    int nextaddress;
};
//这个是用来存结点的数组 
struct List{
	int address;
	int date;
    int nextaddress;
};
//用来存数据 
void creatList(int n,Node *node){
    int address;
    for(int i=0;i<n;i++){
        cin>>address;//这里如果不分成两段就会报错，但clion就不会。原因应该是没有把读入的address存到变量里面，推测dev是等一行程序执行完了之后再存变量的 
		cin>>node[address].date>>node[address].nextaddress;
    }
}
//遍历函数 
void foreachList(int firstaddress,List *myList,int n){
    for(int i=0;i<n-1;i++){
    	printf("%05d %d %05d\n",myList[i].address,myList[i].date,myList[i].nextaddress);
	}
	printf("%05d %d %d",myList[n-1].address,myList[n-1].date,myList[n-1].nextaddress);
}
//把静态链表放在数组中，便于进行reverse 
void addforList(int firstaddress,Node *node,List *myList,int &n){
	int i = 0;
	n = 0;
    for(int address=firstaddress;;address=node[address].nextaddress){
        myList[i].address = address;
        myList[i].date = node[address].date;
        myList[i].nextaddress = node[address].nextaddress;
        i++;
        n++;
        if(node[address].nextaddress == -1)
        	break;
    }
}
//反转链表 
void reverse(List *myList,int k,int n){
	int begin = 0;
	//这里的反转由于要进行每一段每一段的反转，因此怎么样去实现是很令人苦恼的，花了很多时间在这上面 
	while(begin+k <= n){
		int end = begin + k - 1;
		for(int i=begin;i<end;i++){
			List temp = myList[i];
			myList[i] = myList[end];
			myList[end] = temp;
			end--;
		}
		begin += k;
	}
}
//让数组看起来好像是有连接的，即重连链表 
void relinkList(List *myList,int n){
	for(int i=0;i<n-1;i++){
		myList[i].nextaddress = myList[i+1].address;
	}
	myList[n-1].nextaddress = -1;
}
int main(){
    Node node[SIZE];
    int firstaddress,n,k;
    cin>>firstaddress>>n>>k;
    //创建数组用来存链表数据 
    List myList[n];
    creatList(n,node);
    addforList(firstaddress,node,myList,n);
//    foreachList(firstaddress,myList,n);
    reverse(myList,k,n);
    relinkList(myList,n);
    foreachList(firstaddress,myList,n);
    return 0;
}
