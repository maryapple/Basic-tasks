#include <stdio.h>

 int main(){
 	int n=0, i=0;
	double sum=0, element=0;
 	printf("enter n: ");
 	scanf("%d", &n);
 	for (i=0; i<n; i++){
 		printf("number: %d   ", i);
 		if (i%2!=0) element = ((-1)*(i+1.0))/(3*(i+3)*(i+3)*(i+3));
		else element = (i+1.0)/(3*(i+3)*(i+3)*(i+3));
		
		printf("element: %.10lf   ", element);
		sum+=element;
		printf("sum: %.10lf\n", sum);
	 }
	 return 0;
 }
