/*С�᣺�������ֻ��һ���о������Ƿ�������Ŀ˼��ܼ򵥣�����Ҳ�ܼ򵥣����ǲ�ͬ��������ж�ȷʵ�ܷ���
		���ǿ��Ի���Ϊ�򣬰�ֵ�ʹ����ֿ�����������ٺܶ����Ļ���
*/		 
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
//���ﶨ��Ľṹ�壬һ��������ʾ��������ʵ��Ϊ���жϵ�����û�����ֵ�������0�жϻ����ģ���һ��������ʾֵ 
struct number{
	int amount;
	double value;
};
int main(){
	//���ﶨ���cnt�����ж�ѭ���Ƿ���� 
    int cnt = 0;
    //n�����洢�������ֵĸ��� 
    int n;
    //�����num���ڴ洢��������� 
    int num;
    //���ﶨ���iֻ��Ϊ����һ��pow��������case1���õ� 
    int i = 0;
    cin>>n;
    struct number numl[5];
    //��ʼ������numl�ṹ�������ֵ 
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
    //�����numl[3]value��ƽ���� 
    numl[3].value /= numl[3].amount;
    //���������ʽ��ͬ����˿��Ƿֿ����
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
	}//�����￪ʼע��Ͳ�Ҫ�ټӿո��� 
	if(numl[4].amount == 0){
		cout<<"N";
	}else{
		printf("%.0f",numl[4].value);
	}
    return 0;
}
