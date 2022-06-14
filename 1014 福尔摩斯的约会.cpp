#include<iostream>
#include<string>
#include<vector>
/*
这个题是目前为止做过的最为“阴险”的题目了，边界条件、隐含条件之多，令人乍舌。
如果不是靠着网上的测试案例慢慢测试补bug，我可能一辈子也找不到bug和这些隐藏条件
*/ 
using namespace std;
int main(){
    vector<char>character;
    vector<char>::iterator it;
    char n[3];
    //两个用来存输入字符的string类型 
    string sentence1,sentence2;
    //这里定义的一个bool类型其实是为了防止'N'以后的字符被直接压入栈中作为第一个元素了 
    bool flag = false;
    cin>>sentence1>>sentence2;
    for(int i=0;i<sentence1.length();i++){
        if(sentence1[i]==sentence2[i]){
        	//第一对相同字符串只接收大写字母，这点要注意 
            if(sentence1[i]>='A'&&sentence1[i]<='G'&&flag == false){
                character.push_back(sentence1[i]);
                //第一个元素读入之后，就把flag变为1，即现在开始允许读入第二对字符了 
                flag = true;
            }
            //第二对字符必须是从'0'到'N'的字符，这点需要注意。一开始我当成所有字符都可以，就会出错 
            else if(flag == true&&sentence1[i]<='N'&&sentence1[i]>='0'){
                character.push_back(sentence1[i]);
                break;
            }
        }
    }
    cin>>sentence1>>sentence2;
    for(int i=0;i<sentence1.length();i++){
    	//第三对字符串要求是只需要是字母就可以了 
        if(sentence1[i]==sentence2[i]&&sentence1[i]>='A'&&sentence1[i]<='z'){
            character.push_back(i);
            break;
        }
    }
    //这里是把vector中的元素赋给了数组，便于后续的输出 
    it = character.begin();
    for(int i=0;i<3;i++){
        n[i] = *it;
        it++;
    }
    //判断星期的一个switch 
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
    //这里的字符需要分情况，从'0'到'9'和从'A'到'Z'需要进行的处理是不同的，需要分开 
    if(n[1]>='0'&&n[1]<='9')
    	//需要改成C语言风格输出便于更改格式，这里如果不这样输出会没有前置0 
        printf("%02d",n[1]-'0');
    else if(n[1]>='A'&&n[1]<='Z')
    //这里的加10是因为需要进行一个便宜操作，A表示的实际上是10 
        cout<<n[1]-'A'+10;
    cout<<":";
    //这里的n[2]似乎直接转换成int类型了，不用去-'0'，这点是我比较奇怪的 
    printf("%02d",n[2]);
    return 0;
}
/*附上CSDN上面看到的测试用例，用这个慢慢把bug找出来的 
测试一：
3469djDkxh4hhG0 
2974dlDfkkkkgg0dsb 
s&hgfdkiggggs
d&Hycvnmzzzzs
 
输出：
THU 00:12
 
测试二：
IcCO2eA
IcCO2eB
cCaseC
cCaseD
 
输出
WED 02:00
 
 
测试三:
6985djEkxh4hhGE 
2984adEfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
 
输出:
FRI 14:04
 
 
测试四:
3485djGkxh4hhG2 
2984akGfkkkkgg2dsb 
s&hgsfdk 
d&hyscvnm
 
输出:
SUN 02:02
 
测试五：
3485djDkxh4hhG82984akDfkkkkggEdsb
2984akDfkkkkgg8da
s&hgsfdk
d&Hyscvnm
 
输出：
*/
