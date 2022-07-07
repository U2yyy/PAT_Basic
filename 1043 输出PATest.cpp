#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int numP = 0;
	int numA = 0;
	int numT = 0;
	int nume = 0;
	int nums = 0;
	int numt = 0;
	for(int i=0;i<s.length();i++){
		switch(s[i]){
			case 'P':numP++;break;
			case 'A':numA++;break;
			case 'T':numT++;break;
			case 'e':nume++;break;
			case 's':nums++;break;
			case 't':numt++;break;
			default: break;
		}
	}
	while(numP+numA+numT+nume+nums+numt>0)
	{
		if(numP>0){
		cout<<"P";
		numP--;
		}
		if(numA>0){
			cout<<"A";
			numA--;
		}
		if(numT>0){
			cout<<"T";
			numT--;
		}
		if(nume>0){
			cout<<"e";
			nume--;
		}
		if(nums>0){
			cout<<"s";
			nums--;
		}
		if(numt>0){
			cout<<"t";
			numt--;
		}
	}
	return 0;
} 
