#include<iostream>
#include<cmath>
#include<vector>
/*这个题我觉得出的很屎，是的，很屎，因为题目中的n并没有说清楚是什么n，做题者很容易
想到这个n会不会是dn里面的n，那么这里的n指的就是质数个数了，而并非数字，这里想错了，
后面再怎么做都是白搭，然后题目的n其实就是数字，我在这里卡了半天，无语*/ 
using namespace std;
<<<<<<< HEAD
//дһ�����׵��ж��Ƿ��������ĺ�����Υ���˵�һ����ԭ�� 
=======
//写一个简易的判断是否是质数的函数（违反了单一出口原则） 
>>>>>>> aa7620d7493584310ba5de3f8f45ead024fb90bc
bool isprime_num(int num){
    if(num == 1)
        return false;
    if(num == 2)
        return true;
	//这里用sqrt(num)会极大的减少程序计算量，但是要注意是<=，不然4（4的平方是2，相当于没进行循环就走了）也会被当成质数压入容器中了 
    for(int i=2;i<=sqrt(num);i++){
        if(num %i == 0)
            return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> prime_num;
    vector<int>::iterator it;
    //将小于等于这个n的数中属于质数的数都压入容器中 
    for(int i=1;i<=n;i++){
        if(isprime_num(i) == true)
            prime_num.push_back(i);
    }
    //定义cnt用来计数，即两个质数相减为2时就加一 
    int cnt = 0;
    //遍历容器中的数字，并判断 
    for(it=prime_num.begin();it!=prime_num.end();it++){
        if(*(it+1)-*it == 2)
            cnt++;
    }
    cout<<cnt;
    return 0;
}
