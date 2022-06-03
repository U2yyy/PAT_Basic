#include<iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        cout<<"Case #"<<i+1<<": ";
        if(a+b>c)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}
