#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    int cnt = 0;
    int n;
    cin>>n;
    int num;
    int i = 0,i4 = 0;
    int a1=0,a2=0,a3=0,a4=0,a5=0;
    if(n>0){
        while(cin>>num){
            switch (num%5) {
                case 0:if(num%2==0)
                    a1+=num;
                    break;
                case 1:a2+=num* pow(-1,i++);
                    break;
                case 2:a3++;
                    break;
                case 3:a4+=num;
                    i4++;
                    break;
                case 4:if(num>a5)
                    a5=num;
                    break;
                default:
                    break;
            }
        if(++cnt==n)
            break;
        }
    }
    double real4 = 0;
    if(i4!=0)
        real4 = 1.0*a4/i4;
    if(a1!=0)
        cout<<a1<<" ";
    else
        cout<<"N"<<" ";
    if(a2!=0)
        cout<<a2<<" ";
    else
        cout<<"N"<<" ";
    if(a3!=0)
        cout<<a3<<" ";
    else
        cout<<"N"<<" ";
    if(real4!=0)
        cout<<setprecision(2)<<real4<<" ";
    else
        cout<<"N"<<" ";
    if(a5!=0)
        cout<<a5;
    else
        cout<<"N";

    return 0;
}