#include<stdio.h>
int main(){

    int i;

    int cnt = 0;

    int sum = 0;

    char ch = getchar();

    while(ch != '\n'){
        switch(ch){
            case '1' : sum += 1;
              break;
            case '2' : sum += 2;
              break;  
            case '3' : sum += 3;
              break;                
            case '4' : sum += 4;
              break;                             
            case '5' : sum += 5;
              break;
            case '6' : sum += 6;
              break;  
            case '7' : sum += 7;
              break;  
            case '8' : sum += 8;
              break;  
            case '9' : sum += 9;
              break;  
            case '0' : sum += 0;
              break;     
        }
        ch = getchar();
    }

    int mid = sum;

    for(i=0; ;i++){
        sum /= 10;
        cnt++;
        if(sum == 0)
        break;
    }

    sum = mid;

    int a[cnt];

    for(i=0;i<cnt;i++){
        a[i] = sum % 10;
        sum /= 10;
    }

    for(i=0;i<cnt;i++){
        switch(a[cnt-i-1]){
            case 0:printf("ling");
             break;
            case 1:printf("yi");
             break;
            case 2:printf("er");
             break;
            case 3:printf("san");
             break;
            case 4:printf("si");
             break;
            case 5:printf("wu");
             break;
            case 6:printf("liu");
             break;
            case 7:printf("qi");
             break;
            case 8:printf("ba");
             break;
            case 9:printf("jiu");
             break;         
        }
        if (i<cnt-1){
            printf(" ");
        }
    }

    return 0;
}