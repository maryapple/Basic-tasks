#include <stdio.h>

int main(){
	int A[20], Length=20, i=0, j=0, buf=0, k=0, m=0;
	for (i=0; i<Length; i++){
		printf("enter the element: ");
		scanf("%d", &A[i]);
	}
	printf("The initial array:\n");
	for (i=0; i<Length; i++) printf("%d ", A[i]);
	
	for (i=0; i<Length; i++){
		buf=A[i];
		k=0;
		for (j=0; j<Length; j++){
			if (A[j]==buf) 
				k++;
		}
		if (k==3){
			m=1;
			for(j=i+1; j<Length; j++){
				if (A[j]==buf){
					m++;
					continue;
				}
				A[j-m] = A[j];
			}
			Length-=3;
			i--;
		}
	}
	printf("\nThe new array:");
	for (i=0; i<Length; i++) printf("%d ", A[i]);
	return 0;
}
