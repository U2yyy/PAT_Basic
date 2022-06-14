//这是一段已经被废弃的代码
/*
#include<stdio.h>
typedef struct student{
    char name[10];
    char id[10];
    int score;
}load;
int main(){
    int n,i;

    int maxnum = 0,minnum = 0;

    scanf("%d",&n);

    load stu[99];

    for(i=0;i<n;i++){
        int j;
        for(j=0;j<10;j++){
            stu[i].name[j] = '#';
            stu[i].id[j] = '#';
        }
    }

    for(i=0;i<n;i++){
        scanf("%s",stu[i].name);
        scanf("%s",stu[i].id);
        scanf("%d",&stu[i].score);
    }

    for(i=0;i<n;i++){
        if(stu[maxnum].score < stu[i].score){
            maxnum = i;
        }
        if(stu[minnum].score > stu[i].score){
            minnum = i;
        }
    }

    for(i=0;i<10;i++){
        if(stu[maxnum].name[i] != '#'){
            printf("%c",stu[maxnum].name[i]);
        }
    }
    printf(" ");

    for(i=0;i<10;i++){
        if(stu[maxnum].id[i] != '#'){
            printf("%c",stu[maxnum].id[i]);
        }
    }
    printf("\n");

    for(i=0;i<10;i++){
        if(stu[minnum].name[i] != '#'){
            printf("%c",stu[minnum].name[i]);
        }
    }
    printf(" ");

    for(i=0;i<10;i++){
        if(stu[minnum].id[i] != '#'){
            printf("%c",stu[minnum].id[i]);
        }
    }
    printf("\n");

    return 0;
}
*/