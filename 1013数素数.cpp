#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    vector<int> sushu;
    int cnt = 0;
    int beg,end;
    cin>>beg>>end;
    for(int num =2;num<=104729;num++){
        int rel = 1;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0){
                rel = 0;
                break;
            }
        }
        if(num==2||num==3)
            rel = 1;
        if(rel)
            sushu.push_back(num);
    }
    for(int i=beg-1;i<end;i++){
        cout<<sushu[i];
        if(i!=end-1&&cnt!=9)
            cout<<" ";
        cnt++;
        if(cnt==10){
            cout<<endl;
            cnt-=10;
        }
    }
    return 0;
}