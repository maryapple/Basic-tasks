#include <stdio.h>

int main(){
	int A[10], i=0, N=0, sum=0, proizv=1;
	for (i=0; i<10; i++){    //���� �������
		printf("enter the element: ");
		scanf("%d", &A[i]);
	}
	printf("\nThe initial array:\n");
	for (i=0; i<10; i++) printf("%d ", A[i]);  //������� ��������� ������ �� �����
	
	printf("enter N: ");
	scanf("%d", &N);
	
	for(i=10-N; i<10; i++){   //�������� ���� � ��������, ������� ����� �� ������� 10-N
		sum+=A[i];
		proizv*=A[i];
	}
	printf("The sum: %d\nThe proizv: %d", sum, proizv);
	
	for(i=0; i<10; i++){
		if(A[i]%2==0) A[i] = -1;  // �������� �������� � ������ ��������� �� -1
	}
	
	printf("\nThe new array:\n");
	for (i=0; i<10; i++) printf("%d ", A[i]);  //������� ����� ������ �� �����
	
	return 0;
}
