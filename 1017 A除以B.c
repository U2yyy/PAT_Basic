#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char A[1001] = {0};
	int B,Q,R;
	scanf("%s %d",A,&B);
	//ִ�����������ֹ������Ĳ���
	int numpos = strlen(A);
	int ten = A[0] - '0';
	int ge = A[1] - '0';
	int i = 0; 
	//��һ�����������¼�����̵�����
	int shang[1000] = {0};
	//��Ҫһ����ֵ��������洢�˶���λ
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
	//����ten��ʵ������������������
	//��ԭ������
	for(int i=0;i<shangpos;i++){
		printf("%d",shang[i]);
	}
	if(Q == 0)
		printf("%d",Q);
	printf(" %d",ten);
	return 0;
}
