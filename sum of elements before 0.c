#include <stdio.h>

int main(){
	float A[10], sum=0;
	int i=0, k=0, flag=0, position=-1;
	for (i=0; i<10; i++){
		printf("enter the element: ");
		scanf("%f", &A[i]);
	}
	printf("\nThe initial array:\n");
	for (i=0; i<10; i++) printf("%f ", A[i]);
	
	printf("\n\nThe positions: ");
	for (i=0; i<10; i++){
		if (A[i]==0) printf("%d ", i+1);
	}
	
	for (i=9; i>=0; i--){
		if (A[i]==0){
			flag++;
			if (flag==1) {
				position=i+1;
				printf("\nthe position of last 0 is: %d", position);
				break;
			}
		}
	}
	
	if (position == -1) printf("\nThere is no 0 in the array");
	else{
		for (i=0; i<position-1; i++){
			if ((int)(A[i])%2==0){
				k++;
				sum+=A[i];
			}
		}
		
		printf("\nThe amount of even num before last 0: %d\nThe sum: %f", k, sum);
	}
	return 0;
}
