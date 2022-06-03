#include<stdio.h>
int findA1(char a[],int *);
int findP(char a[],int *);
int findA2(char a[],int *);
int findT(char a[],int *);
int findA3(char a[],int *);
int main(){
    int n;
    int begin = 0;
    int numA1 = 0,numA2 = 0,numA3 = 0;
    int numP = 0,numT =0;
    char pat[101];
    int i;
    for(i=0;i<101;i++){
        pat[i] = '0';
    }
    i = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",pat);

        numA1 = findA1(pat,&begin);
        numP = findP(pat,&begin);
        numA2 = findA2(pat,&begin);
        numT = findT(pat,&begin);
        numA3 = findA3(pat,&begin);

        if(numP != 1 || numT != 1){
            printf("NO\n");
        }else if(numA1*numA2 == numA3 && numA2 != 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        begin = 0;
    }

    return 0;
}
int findA1(char a[],int *p){
    int num = 0;
    for(*p; ;(*p)++){
        if(a[*p] == 'A'){
            num++;
        }else{
            break;
        }
    }
    return num;
}

int findP(char a[],int *p){
    int num = 0;
    for(*p; ;(*p)++){
        if(a[*p] == 'P'){
            num++;
        }else{
            break;
        }
    }
    return num;
}

int findA2(char a[],int *p){
    int num = 0;
    for(*p; ;(*p)++){
        if(a[*p] == 'A'){
            num++;
        }else{
            break;
        }
    }
    return num;
}

int findT(char a[],int *p){
    int num = 0;
    for(*p; ;(*p)++){
        if(a[*p] == 'T'){
            num++;
        }else{
            break;
        }
    }
    return num;
}

int findA3(char a[],int *p){
    int num = 0;
    for(*p; ;(*p)++){
        if(a[*p] == 'A'){
            num++;
        }else{
            break;
        }
    }
    return num;
}
