#include <stdio.h>

 int main(){
 	int n=0, i=0;
	double sum=0, element=0;
 	printf("enter n: ");
 	scanf("%d", &n);
 	for (i=1; i<=n; i++){
 		printf("number: %d   ", i);
 		if (i%2==0) element = ((-1)*(i+1.0)*(i+2.0))/(50*(5*i-1)*(5*i-1)*(5*i-1));
		else element = ((i+1.0)*(i+2.0))/(50*(5*i-1)*(5*i-1)*(5*i-1));
		
		printf("element: %lf   ", element);
		sum+=element;
		printf("sum: %lf\n", sum);
	 }
	 return 0;
 }
