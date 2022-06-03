#include<stdio.h>
int main(){
    int num;

    int n = 0;

    scanf("%d",&num);

    for(n=0; ;n++){
        if(num == 1)
        break;

        if(num % 2 == 0){
            num /= 2;
        }else{
            num = (3*num + 1)/2;
        }
    }

    printf("%d",n);

    return 0;
}