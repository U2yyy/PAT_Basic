#include<iostream>
#include<algorithm>
using namespace std;
//�����±��Ľṹ�� 
typedef struct{
	double K;//K��ʾ����� 
	double S;//S��ʾ��Ʒ���ۼ� 
	double D;//D��ʾ��Ʒ���ۣ���S/K 
}makeyuebing;
//��������д�����һ���ṹ�������ָ�룬һ���������󳤶�ֵ����һ��ָ���������λ�õ�ָ��
//Ŀ������ÿ���ҵ�����������֮�󷵻�����ɾ�����������´�Ѱ��ʱ������������ʵ�ƻ��˽ṹ���ڵķ�װ��
//ͬʱ�������ô��ݴӶ���ָ���������λ�õ�iҲʵʱ���� 
double maxof(makeyuebing *date,int n,int *maxi){
	double maxnum = 0;
	int i;
	for(i=0;i<n;i++){
		if(date[i].D > maxnum){
			maxnum = date[i].D;
			*maxi = i;
		}
	}
	//�������������0������ʵ�ƻ������ݣ�����û���뵽���õİ취����copyһ���ṹ�壿����Ҳ���ԣ��������ﲻҪ��������������˾������������ˣ� 
	date[*maxi].D = 0;
	return maxnum;
}
int main(){
	int n,max;
	cin>>n>>max;
	//����ṹ������ 
	makeyuebing yuebing[1000];
	//Ϊÿ������Ԫ�صĿ�渳ֵ 
	for(int i=0;i<n;i++){
		cin>>yuebing[i].K; 
	}
	//Ϊÿ�������Ԫ�����ۼ۸�ֵ�������ÿ������Ԫ�صĵ��� 
	for(int i=0;i<n;i++){
		cin>>yuebing[i].S;
		yuebing[i].D = yuebing[i].S / yuebing[i].K;
	}
	//maxi��ָ���������Ԫ�ص�ָ�� 
	int maxi = 0;
	//W����Ʒ������ 
	double W = 0;
	double maxnow = maxof(yuebing,n,&maxi);
	//����һ���Ƚϴ������Ƚϴ����ǲ����ܶ���n�ģ�������nʱ�����˳�ѭ��
	int cmp = 0; 
	do{
		//��������󵥼۵��±�����max������ôֱ���õ��ۺ�max��˾͵õ�������Ȼ���max��Ϊ0���� 
		if(yuebing[maxi].K>max){
			W += maxnow*(max);
			max = 0;
			cmp++; 
		}else{//������ǣ���ô���������󵥼۵��±���������Ŀ����˵õ�������Ȼ����max��ȥ���Ŀ�� 
			W += maxnow*(yuebing[maxi].K);
			max = max-yuebing[maxi].K;
			cmp++; 
		}
		maxnow = maxof(yuebing,n,&maxi);
		//���Ƚϴ����Ѿ��ﵽnʱ��ֱ���˳�����ʱ˵��max��ĺܴ������±�����������û���� 
		if(cmp == n)
			break;
		//���max������ô��Ļ�����ômaxһ���ǻ���ĳ�±��������ڶ�̬��max����������ômax�ᱻ��Ϊ0��������˳�ѭ�������� 
	}while(max!=0);
	//������ĿҪ��������� 
	printf("%.2f",W);
}
