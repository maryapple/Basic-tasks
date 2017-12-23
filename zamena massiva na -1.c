#include <stdio.h>

int main(){
	int A[10], i=0, N=0, sum=0, proizv=1;
	for (i=0; i<10; i++){    //ввод массива
		printf("enter the element: ");
		scanf("%d", &A[i]);
	}
	printf("\nThe initial array:\n");
	for (i=0; i<10; i++) printf("%d ", A[i]);  //выводим начальный массив на экран
	
	printf("enter N: ");
	scanf("%d", &N);
	
	for(i=10-N; i<10; i++){   //Начинаем цикл с элемента, который стоит на позиции 10-N
		sum+=A[i];
		proizv*=A[i];
	}
	printf("The sum: %d\nThe proizv: %d", sum, proizv);
	
	for(i=0; i<10; i++){
		if(A[i]%2==0) A[i] = -1;  // Заменяем элементы с четным значением на -1
	}
	
	printf("\nThe new array:\n");
	for (i=0; i<10; i++) printf("%d ", A[i]);  //выводим новый массив на экран
	
	return 0;
}
