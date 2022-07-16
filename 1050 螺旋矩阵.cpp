#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
//这个函数是用来找相差最小的m和n的 
void matrix(int num,int &m,int &n){
    int a[num],b[num],c[num];
    for(int i=0;i<num;i++){
        a[i] = -1;
        b[i] = -2;
        c[i] = 99999;
    }
    int j = 0;
    for(int i=1;i<=num;i++){
        if(num%i==0){
            a[j] = i;
            b[j++] = num/i;
        }
    }
    int min = 99999;
    int minnum = 0;
    for(int i=0;i<num;i++){
        if(a[i]>0&&b[i]>0){
            c[i] = a[i] - b[i];
        }
        if(c[i]<=min&&c[i]>=0){
            min = c[i];
            minnum = i;
        }
    }
    m = a[minnum];
    n = b[minnum];
}
//这个函数是用来排序的 
int cmp(int a,int b){
    return a>b;
}
int main(){
    int num;
    cin>>num;
    int m,n;
    matrix(num,m,n);
    int myMat[m][n];
    memset(myMat,0,sizeof(myMat));
    vector<int> myNum;
    vector<int>::iterator it;
    for(int i=0;i<num;i++){
        int temp;
        cin>>temp;
        myNum.push_back(temp);
    }
    sort(myNum.begin(),myNum.end(),cmp);
    int i = 0;
    int j = -1;
    int cnt = 0;
    it = myNum.begin();
    //像这样碰壁式地将每个数字填到矩阵中去 
    while(cnt<num){
        while(j!=n-1&&myMat[i][j+1]==0){
            cnt++;
            myMat[i][++j] = *it++;
        }
        while(i!=m&&myMat[i+1][j]==0){
            cnt++;
            myMat[++i][j] = *it++;
        }
        while(j!=-1&&myMat[i][j-1]==0){
            cnt++;
            myMat[i][--j] = *it++;
        }
        while(i!=-1&&myMat[i-1][j]==0){
            cnt++;
            myMat[--i][j] = *it++;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<myMat[i][j];
            if(j!=n-1)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
