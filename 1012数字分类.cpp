/*小结：做这个题只有一个感觉：就是繁琐，题目思想很简单，计算也很简单，但是不同的输出和判断确实很繁琐
		我们可以化繁为简，把值和次数分开，这样会减少很多出错的机会
*/		 
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//这里定义的结构体，一个用来表示次数（其实是为了判断到底有没有这个值，如果用0判断会出错的），一个用来表示值 
struct number{
	int amount;
	double value;
};
int main(){
	//这里定义的cnt用来判断循环是否结束 
    int cnt = 0;
    //n用来存储输入数字的个数 
    int n;
    //定义的num用于存储输入的数字 
    int num;
    //这里定义的i只是为了用一下pow函数，在case1中用到 
    int i = 0;
    cin>>n;
    struct number numl[5];
    //初始化所有numl结构体里面的值 
    for(int i=0;i<5;i++){
    	numl[i].amount = 0;
    	numl[i].value = 0;
	}
    if(n>0){
        while(cin>>num){
            switch (num%5) {
                case 0:if(num%2==0){
                    numl[0].value+=num;
                    numl[0].amount++;
                }
                    break;
                case 1:numl[1].value+=num* pow(-1,i++);
                		numl[1].amount++;
                    break;
                case 2:numl[2].value++;
                		numl[2].amount++;
                    break;
                case 3:numl[3].value+=num;
                    	numl[3].amount++;
                    break;
                case 4:if(num>numl[4].value){
                	numl[4].value = num;
                	numl[4].amount++;
				};
            }
        if(++cnt==n)
            break;
        }
    }
    //计算出numl[3]value的平均数 
    numl[3].value /= numl[3].amount;
    //由于输出格式不同，因此考虑分开输出
	if(numl[0].amount == 0){
		cout<<"N ";
	}else{
		printf("%.0f ",numl[0].value);
	}
	if(numl[1].amount == 0){
		cout<<"N ";
	}else{
		printf("%.0f ",numl[1].value);
	}
	if(numl[2].amount == 0){
		cout<<"N ";
	}else{
		printf("%.0f ",numl[2].value);
	}
	if(numl[3].amount == 0){
		cout<<"N ";
	}else{
		printf("%.1f ",numl[3].value);
	}//从这里开始注意就不要再加空格了 
	if(numl[4].amount == 0){
		cout<<"N";
	}else{
		printf("%.0f",numl[4].value);
	}
    return 0;
}
