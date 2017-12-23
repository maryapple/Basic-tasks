#include <stdio.h>

int main(){
	int A[10], N=0, i=0, k=0;
	float sum=0, av=0;
	for (i=0; i<10; i++){
		printf("enter the element: ");
		scanf("%d", &A[i]);
	}
	
	printf("\nenter N: ");
	scanf("%d", &N);
	for (i=10-N; i<10; i++){
		sum+=A[i];
	}
	printf("\nsum: %f", sum);
	av = sum/N;
	printf("\nav: %f", av);
	
	for (i=0; i<10; i++){
		if (A[i]%2!=0) k++;
	}
	printf("\nk: %d", k);
	
	printf("\nthe array: ");
	for (i=0; i<10; i++){
		printf("%d ", A[i]);
	}
	return 0;
}
