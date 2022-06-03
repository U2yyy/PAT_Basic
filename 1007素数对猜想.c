#include<stdio.h>
int whether(int a);
int main(){
    int num;
    scanf("%d",&num);
    int i;
    int cnt = 0;
    int n1 = 0,n2 = 0;
    for(i=2;i<=num;i++){
        if(whether(i)){
            n1 = i;
            int j;
            for(j=i+1;j<=num;j++) {
                if (whether(j)) {
                    n2 = j;
                    break;
                }
            }
            if(n2-n1 == 2)
                cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
int whether(int a){
    int rel = 1;
    int i;
    for(i=2;i<=a/2;i++){
        if(a%i == 0){
            rel = 0;
            break;
        }
    }
    return rel;
}
