#include<iostream>
#include<string>
#include<vector>
/*
�������ĿǰΪֹ��������Ϊ�����ա�����Ŀ�ˣ��߽���������������֮�࣬����է�ࡣ
������ǿ������ϵĲ��԰����������Բ�bug���ҿ���һ����Ҳ�Ҳ���bug����Щ��������
*/ 
using namespace std;
int main(){
    vector<char>character;
    vector<char>::iterator it;
    char n[3];
    //���������������ַ���string���� 
    string sentence1,sentence2;
    //���ﶨ���һ��bool������ʵ��Ϊ�˷�ֹ'N'�Ժ���ַ���ֱ��ѹ��ջ����Ϊ��һ��Ԫ���� 
    bool flag = false;
    cin>>sentence1>>sentence2;
    for(int i=0;i<sentence1.length();i++){
        if(sentence1[i]==sentence2[i]){
        	//��һ����ͬ�ַ���ֻ���մ�д��ĸ�����Ҫע�� 
            if(sentence1[i]>='A'&&sentence1[i]<='G'&&flag == false){
                character.push_back(sentence1[i]);
                //��һ��Ԫ�ض���֮�󣬾Ͱ�flag��Ϊ1�������ڿ�ʼ�������ڶ����ַ��� 
                flag = true;
            }
            //�ڶ����ַ������Ǵ�'0'��'N'���ַ��������Ҫע�⡣һ��ʼ�ҵ��������ַ������ԣ��ͻ���� 
            else if(flag == true&&sentence1[i]<='N'&&sentence1[i]>='0'){
                character.push_back(sentence1[i]);
                break;
            }
        }
    }
    cin>>sentence1>>sentence2;
    for(int i=0;i<sentence1.length();i++){
    	//�������ַ���Ҫ����ֻ��Ҫ����ĸ�Ϳ����� 
        if(sentence1[i]==sentence2[i]&&sentence1[i]>='A'&&sentence1[i]<='z'){
            character.push_back(i);
            break;
        }
    }
    //�����ǰ�vector�е�Ԫ�ظ��������飬���ں�������� 
    it = character.begin();
    for(int i=0;i<3;i++){
        n[i] = *it;
        it++;
    }
    //�ж����ڵ�һ��switch 
    switch(n[0]){
        case 'A':cout<<"MON ";
            break;
        case 'B':cout<<"TUE ";
            break;
        case 'C':cout<<"WED ";
            break;
        case 'D':cout<<"THU ";
            break;
        case 'E':cout<<"FRI ";
            break;
        case 'F':cout<<"SAT ";
            break;
        case 'G':cout<<"SUN ";
            break;
        default:
            break;
    }
    //������ַ���Ҫ���������'0'��'9'�ʹ�'A'��'Z'��Ҫ���еĴ����ǲ�ͬ�ģ���Ҫ�ֿ� 
    if(n[1]>='0'&&n[1]<='9')
    	//��Ҫ�ĳ�C���Է��������ڸ��ĸ�ʽ��������������������û��ǰ��0 
        printf("%02d",n[1]-'0');
    else if(n[1]>='A'&&n[1]<='Z')
    //����ļ�10����Ϊ��Ҫ����һ�����˲�����A��ʾ��ʵ������10 
        cout<<n[1]-'A'+10;
    cout<<":";
    //�����n[2]�ƺ�ֱ��ת����int�����ˣ�����ȥ-'0'��������ұȽ���ֵ� 
    printf("%02d",n[2]);
    return 0;
}
/*����CSDN���濴���Ĳ��������������������bug�ҳ����� 
����һ��
3469djDkxh4hhG0 
2974dlDfkkkkgg0dsb 
s&hgfdkiggggs
d&Hycvnmzzzzs
 
�����
THU 00:12
 
���Զ���
IcCO2eA
IcCO2eB
cCaseC
cCaseD
 
���
WED 02:00
 
 
������:
6985djEkxh4hhGE 
2984adEfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
 
���:
FRI 14:04
 
 
������:
3485djGkxh4hhG2 
2984akGfkkkkgg2dsb 
s&hgsfdk 
d&hyscvnm
 
���:
SUN 02:02
 
�����壺
3485djDkxh4hhG82984akDfkkkkggEdsb
2984akDfkkkkgg8da
s&hgsfdk
d&Hyscvnm
 
�����
*/
