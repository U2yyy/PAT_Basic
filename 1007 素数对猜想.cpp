#include<iostream>
#include<cmath>
#include<vector>
/*������Ҿ��ó��ĺ�ʺ���ǵģ���ʺ����Ϊ��Ŀ�е�n��û��˵�����ʲôn�������ߺ�����
�뵽���n�᲻����dn�����n����ô�����nָ�ľ������������ˣ����������֣���������ˣ�
��������ô�����ǰ״Ȼ����Ŀ��n��ʵ�������֣��������￨�˰��죬����*/ 
using namespace std;
//дһ�����׵��ж��Ƿ��������ĺ�����Υ���˵�һ����ԭ�� 
bool isprime_num(int num){
    if(num == 1)
        return false;
    if(num == 2)
        return true;
	//������sqrt(num)�Ἣ��ļ��ٳ��������������Ҫע����<=����Ȼ4��4��ƽ����2���൱��û����ѭ�������ˣ�Ҳ�ᱻ��������ѹ���������� 
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
    //��С�ڵ������n��������������������ѹ�������� 
    for(int i=1;i<=n;i++){
        if(isprime_num(i) == true)
            prime_num.push_back(i);
    }
    //����cnt�����������������������Ϊ2ʱ�ͼ�һ 
    int cnt = 0;
    //���������е����֣����ж� 
    for(it=prime_num.begin();it!=prime_num.end();it++){
        if(*(it+1)-*it == 2)
            cnt++;
    }
    cout<<cnt;
    return 0;
}
