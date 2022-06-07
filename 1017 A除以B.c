#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char A[1001] = {0};
	int B,Q,R;
	scanf("%s %d",A,&B);
	//执行类似于人手工除法的操作
	int numpos = strlen(A);
	int ten = A[0] - '0';
	int ge = A[1] - '0';
	int i = 0; 
	//用一个整型数组记录各个商的数字
	int shang[1000] = {0};
	//还要一个数值用来计算存储了多少位
	int shangpos = 0;
	Q = 99; 
	if(numpos==1){
		if(A[0]-'0'<B){
			Q = 0;
			R = A[0]-'0';
		}else{
			Q = 1;
			R = A[0]-'0'-B;
		}
	}else{
		while(A[i+1]){
			int num = 10 * ten + ge;
			shang[i] = num / B;
			shangpos++;
			ten = num % B;
			ge = A[i+2] - '0';
			i++;
		}
	}
	//最后的ten其实就是整个除法的余数
	//还原商数组
	for(int i=0;i<shangpos;i++){
		printf("%d",shang[i]);
	}
	if(Q == 0)
		printf("%d",Q);
	printf(" %d",ten);
	return 0;
}
