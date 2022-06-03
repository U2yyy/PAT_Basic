#include <stdio.h>
int Bbytes(int a);
int Sbytes(int a);
int main() {
    int num;

    scanf("%d",&num);

    int numB = 0,numS = 0;

    numB = Bbytes(num);

    numS = Sbytes(num);

    int i;

    for(i=0;i<numB;i++){
        printf("B");
    }
    for(i=0;i<numS;i++){
        printf("S");
    }
    int G = num % 10;
    for(i=1;i<=G;i++){
        printf("%d",i);
    }
    printf("\n");

    return 0;
}
int Bbytes(int a){
    int cnt = 0;
    cnt = a / 100;
    return cnt;
}
int Sbytes(int a){
    int cnt = 0;
    a %= 100;
    cnt = a / 10;
    return cnt;
}
