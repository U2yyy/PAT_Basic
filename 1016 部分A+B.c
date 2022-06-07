#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char A[10],B[10];
	char DA,DB;
	scanf("%s %c %s %c",A,&DA,B,&DB);
	int numA = 0,numB = 0;
	for(int i=0;i<10;i++){
		if(A[i] == DA)
			numA++;
		if(B[i] == DB)
			numB++;			
	}
	int PA = 0,PB = 0;
	while(numA > 0){
		PA += pow(10,--numA) * (DA - '0');
	}
	while(numB > 0){
		PB += pow(10,--numB) * (DB - '0');
	}
	printf("%d",PA+PB);
	return 0;
}
