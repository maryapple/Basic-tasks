#include <stdio.h>

int main(){
	float A[12];
	int k=0, i=0;
	for (i=0; i < 10; i++){
		printf("enter the element: ");
		scanf("%d", &A[i]);
	}
	for (i=0; i<10; i++){
		if (A[i]==0.) printf("%d ", i);
	}
	return 0;
}
