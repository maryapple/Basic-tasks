#include <stdio.h>

int main(){
	float A[10], max=0, sum=0;
	int i=0, k=0, pos1=0, pos2=0, flag=0;
	for(i=0;i<10;i++){
		printf("enter the element: ");
		scanf("%f", &A[i]);
	}
	printf("\nThe initial array:\n");
	for (i=0; i<10; i++) printf("%f ", A[i]);
	
	max=A[0];
	for(i=0; i<10; i++){
		if (A[i]>max) max=A[i];
	}
	printf("\nmax:%f ", max);
	
	printf("\nThe positions of max:\n");
	for(i=0; i<10; i++){
		if (A[i]==max){
			k++;
			printf("%d ", i);
		}
	}
	printf("\nThe quantity of max: %d", k);
	
	for(i=0; i<10; i++){
		if(A[i]==max){
			flag++;
			if (flag==1)
				pos1=i;
		}
	}
	printf("\npos1: %d\n", pos1);
	flag=0;
	for(i=9; i>=0; i++){
		if(A[i]==max){
			flag++;
			if(flag==1)
				pos2=i;
		}
	}
	printf("\npos2: %d\n", pos2);
	return 0;
}
