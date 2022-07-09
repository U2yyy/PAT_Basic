#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
void funNum(string s){
	int byte = s.length();
	int num = 0;
	for(int i=0;i<s.length();i++){
		num += (s[i]-'0')*pow(10,byte-1);
		byte--;
	}
	int highByte = num / 13;
	int lowByte = num % 13;
	//非常需要注意这里的格式化输出问题 
	switch(highByte){
		case 0:break;
		case 1:cout<<"tam";break;
		case 2:cout<<"hel";break;
		case 3:cout<<"maa";break;
		case 4:cout<<"huh";break;
		case 5:cout<<"tou";break;
		case 6:cout<<"kes";break;
		case 7:cout<<"hei";break;
		case 8:cout<<"elo";break;
		case 9:cout<<"syy";break;
		case 10:cout<<"lok";break;
		case 11:cout<<"mer";break;
		case 12:cout<<"jou";break;
		default:break;
	}
	if(highByte!=0&&lowByte!=0)
		cout<<" ";
	switch(lowByte){
		case 0:if(highByte==0)cout<<"tret";break;
		case 1:cout<<"jan";break;
		case 2:cout<<"feb";break;
		case 3:cout<<"mar";break;
		case 4:cout<<"apr";break;
		case 5:cout<<"may";break;
		case 6:cout<<"jun";break;
		case 7:cout<<"jly";break;
		case 8:cout<<"aug";break;
		case 9:cout<<"sep";break;
		case 10:cout<<"oct";break;
		case 11:cout<<"nov";break;
		case 12:cout<<"dec";break;
		default:break;
	}
	cout<<endl;
}
//这个题最值得一提的就是string方法的调用，这里用到了substr方法用以copy字符串 
void funCha(string s){
	string s1,s2;
	if(s.length()<=4){
		s1 = '#';
		s2 = s;
	}else{
		s1 = s.substr(0,3);
		s2 = s.substr(4,7);
	}
	int num = 0;
	for(int i=0;i<13;i++){
		if(s1==b[i]||s2==b[i])
			num += i*13;
		if(s2==a[i])
			num += i;
	}
	cout<<num<<endl; 
}
int main(){
	int n;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		if(s[0]>='0'&&s[0]<='9'){
			funNum(s);
		}else{
			funCha(s);
		}
	}
	return 0;
}
