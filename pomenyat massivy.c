#include <stdio.h>

int main(){
	int A[12], k=0, i=0, max=0;
	for (i=0; i < 12; i++){
		printf("enter the element: ");
		scanf("%d", &A[i]);
	}
	max = A[0];
	for (i=0; i < 12; i++){
		if (A[i] > max){
			max = A[i];
		}
	}
	printf("max: %d\n", max);
	for (i=0; i < 12; i++){
		if (A[i]==max){
			k++;
			printf("the position: %d\n", i+1);
		}
	}
	printf("quantity: %d", k);
	
	int New[12];
	
	for (i=0; i<12; i++){   // New[]
		if(i<6)
			New[i]=A[i+6];
		else 
			New[i]=A[i-6];
	}
	
	printf("\nThe initial array:\n");
	for (i=0; i<12; i++) printf("%d ", A[i]);
	
	printf("\nThe new array:\n");
	for (i=0; i<12; i++) printf("%d ", New[i]);
	
	return 0;
}
