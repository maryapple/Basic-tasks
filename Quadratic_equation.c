#include <stdio.h>
#include <math.h>

int main(){
	double a=0, b=0, c=0, D=0;
	printf("Enter a, b, c: ");
	scanf("%lf%lf%lf", &a, &b, &c);
	if (a==0 && b==0 && c==0) printf ("There is an infinite set of solutions");
	else if (a==0 && b==0) printf ("No solution");
	else if (a==0) printf("x=%lf", -c/b);
	else{
		D=b*b-4*a*c;
		if (D<0) printf("Complex roots");
		else if (D==0) printf ("x=%lf", -b/(2*a));
		else{
			printf("x1=%f\nx2=%f", (-b+sqrt(D))/(2*a), (-b-sqrt(D))/(2*a));
		}
	}
	return 0;
}
