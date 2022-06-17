/*
�����Ҳ��һ���Լ���û��ʲô˼·���⣬�������˰���Ľ����Ұָ��һ�ѣ�������ָ
���쿴���е�����֪����̬������һ�����������ԺܺõĽ�������Ŀ
*/
#include<iostream>
#include<algorithm>

#define SIZE 100000
using namespace std;

struct Node{
    int date;
    int nextaddress;
};
//������������������ 
struct List{
	int address;
	int date;
    int nextaddress;
};
//���������� 
void creatList(int n,Node *node){
    int address;
    for(int i=0;i<n;i++){
        cin>>address;//����������ֳ����ξͻᱨ����clion�Ͳ��ᡣԭ��Ӧ����û�аѶ����address�浽�������棬�Ʋ�dev�ǵ�һ�г���ִ������֮���ٴ������ 
		cin>>node[address].date>>node[address].nextaddress;
    }
}
//�������� 
void foreachList(int firstaddress,List *myList,int n){
    for(int i=0;i<n-1;i++){
    	printf("%05d %d %05d\n",myList[i].address,myList[i].date,myList[i].nextaddress);
	}
	printf("%05d %d %d",myList[n-1].address,myList[n-1].date,myList[n-1].nextaddress);
}
//�Ѿ�̬������������У����ڽ���reverse 
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
//��ת���� 
void reverse(List *myList,int k,int n){
	int begin = 0;
	//����ķ�ת����Ҫ����ÿһ��ÿһ�εķ�ת�������ô��ȥʵ���Ǻ����˿��յģ����˺ܶ�ʱ���������� 
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
//�����鿴���������������ӵģ����������� 
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
    //���������������������� 
    List myList[n];
    creatList(n,node);
    addforList(firstaddress,node,myList,n);
//    foreachList(firstaddress,myList,n);
    reverse(myList,k,n);
    relinkList(myList,n);
    foreachList(firstaddress,myList,n);
    return 0;
}
