#include <stdio.h>

int main(){
	int A[12], k=0, i=0, min=0;
	for (i=0; i < 10; i++){
		printf("enter the element: ");
		scanf("%d", &A[i]);
	}
	min = A[0];
	for (i=0; i < 10; i++){
		if (A[i] < min){
			min = A[i];
		}
	}
	printf("min: %d\n", min);
	for (i=0; i < 10; i++){
		if (A[i]==min){
			k++;
			printf("the position: %d\n", i+1);
		}
	}
	printf("quantity: %d", k);
	
	int New[12];
	
	for (i=0; i<10; i++){   // New[]
		if(i<5)
			New[i]=A[i+5];
		else 
			New[i]=A[i-5];
	}
	
	printf("\nThe initial array:\n");
	for (i=0; i<10; i++) printf("%d ", A[i]);
	
	printf("\nThe new array:\n");
	for (i=0; i<10; i++) printf("%d ", New[i]);
	
	return 0;
}
