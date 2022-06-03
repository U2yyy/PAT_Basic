#include <stdio.h>
typedef struct {
    int position;
    int numl;
}num;
int main() {
    int n,mov;
    scanf("%d %d",&n,&mov);
    int i;
    num a[n];
    for(i=0;i<n;i++){
        a[i].position = i+1+mov;
        int muti = a[i].position/n;
        if(a[i].position > n) {
            a[i].position -= n * muti;
            if(a[i].position == 0)
                a[i].position = n;
        }
        scanf("%d",&a[i].numl);
    }
    int cnt = 1;
    int j;
    for(j=0;j<n;j++) {
        for (i = 0; i < n; i++) {
            if (a[i].position == cnt) {
                printf("%d", a[i].numl);
                cnt++;
                if(j<n-1)
                    printf(" ");
                break;
            }
        }
    }
    return 0;
}
