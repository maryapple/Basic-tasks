#include <stdio.h>

//int create_new_array(int, int);

int main(){
	int N;
	int A[100], i=0, n=0;
	printf("enter array A[]:\n");
	for (i=0; i<=100; i++){
		scanf("%d", &A[i]);
		if (A[i]<0) break;
	}
	n=i;
	printf("\nA[]:");
	for (i=0; i<n; i++) printf ("%d ", A[i]);
	
	int B[n];
	printf("\n\nenter array B[]:\n");
	for (i=0; i<n; i++) scanf("%d", &B[i]);
	printf("\nB[]:");
	for (i=0; i<n; i++) printf ("%d ", B[i]);
	
	int C[n]; 
	C[n] = create_new_array(A[n], B[n], n); 
	
	printf("\nC[]:");
	for (i=0; i<n; i++) printf ("%d ", C[i]);
	
	return 0;
}

int enter_the_arrays(int A1[], int A2[], int L){
	int i=0, C[L];
	for(i=0; i<L; i++){
		if ((A1[i]+A2[i])%2!=0) C[i] = A1[i]*A1[i] + A2[i]*A2[i];
		else C[i] = A2[i];
	}
	return C[L];
}
