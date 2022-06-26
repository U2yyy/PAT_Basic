#include<iostream>
#include<string>
using namespace std;
struct fenshu{
	int child;
	int mother;
	int num;
	bool positive;
};
void fun(int &a,int &b){
	int max = 1;
	int n1 = a;
	int n2 = b;
	for(int i=2;i<=n1;i++){
		if(n1%i==0&&n2%i==0)
			max = i;
	}
	a /= max;
	b /= max;
}
void simplify(string s,fenshu *a){
	if(s[0]=='-'){
		a->positive = false;
		int s1=s[1]-'0';
		int s3=s[3]-'0';
		if(s1%s3==0){
			a->num=s1/s3;
			a->mother=a->child=-1;
		}else{
			a->child=s1%s3;
			a->num=s1/s3;
			a->mother=s3;
			fun(a->child,a->mother);	
		}
	}else{
		int s0=s[0]-'0';
		int s2=s[2]-'0';
		a->positive = true;
		if(s0%s2==0){
			a->num=s0/s2;
			a->mother=a->child=-1;
		}else{
			a->child=s0%s2;
			a->num=s0/s2;
			a->mother=s2;
			fun(a->child,a->mother);	
		}
	}
}
void myPrint(fenshu a){
		if(!a.positive){
		cout<<"-";
	}
	if(a.mother==-1){
			cout<<a.num;
	}else{
		if(a.num)
			cout<<a.num<<" ";
		if(a.child==0){
			cout<<a.num;
		}else{
			cout<<a.child<<"/"<<a.mother;
		}
	}
}
void yunsuan(fenshu *a,fenshu *b){
	a->child *= b->mother;
	a->mother *= b->mother;
	b->child *= a->mother;
	b->mother *= a->mother;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	fenshu a,b;
	simplify(s1,&a);
	simplify(s2,&b);
	myPrint(a);
	myPrint(b);
}
