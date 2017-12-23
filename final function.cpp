#include <iostream>

using namespace std;

int input(float A[]);
void output(float A[], int N);
void make_array(float A[], float B[], float C[], int N);
int max(float A[], float B[], int N, int i);
float proizv(float A[], int N, int n);
void sort(float A[], int N);

int main() {
	float A[100], B[100], C[100], mul1 = 0, mul2 = 0, mul3 = 0;
	int N = 0, n = 0;
	cout << "Enter the elements of A[]:\n";
	N = input(A);
	cout << "\nEnter the elements of B[]:\n";
	N = input(B);

	cout << "A[]: ";
	output(A, N);

	cout << "\nB[]: ";
	output(B, N);

	make_array(A, B, C, N);

	cout << "\nC[]: ";
	output(C, N);
	cout << endl;

	cout << "\nenter n: ";
	cin >> n;
	mul1 = proizv(A, N, n);
	mul2 = proizv(B, N, n);
	mul3 = proizv(C, N, n);
	cout << "\nmul1: " << mul1 << "\nmul2: " << mul2 << "\nmul3: " << mul3 << endl;

	sort(C, N);
	cout << "\nsorted C[]: ";
	output(C, N);
	cout << endl;
	return 0;
}

int input(float A[]) {
	int i = 0, N = 0;
	for (i = 0; i<100; i++) {
		cout << "Enter the element, negative to exit: ";
		cin >> A[i];
		if (A[i] < 0) return i;
	}
	return i;
}

void output(float A[], int N) {
	int i = 0;
	for (i = 0; i < N; i++) cout << "\t" << A[i];
}

void make_array(float A[], float B[], float C[], int N) {
	int i = 0;
	for (i = 0; i < N; i++) C[i] = B[i] / max(A, B, N, i);
}

int max(float A[], float B[], int N, int i) {
	float max = 0;
	if (A[i] >= B[i]) max = A[i];
	else max = B[i];
	//cout << "\nmax: " << max;
	return max;
}

float proizv(float A[], int N, int n) {
	int i = 0, flag = 0;
	float mul = 1;
	for (i = 0; i < N; i++) {
		if (A[i] > 3 * n) {
			mul *= A[i];
			flag = 1;
		}
	}
	if (flag) return mul;      // if (flag!=0) return mul;
//	else return (-1);
	return mul;
}

void sort(float A[], int N) {
	int i=0, j=0;
	float tmp=0;
	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			if (A[j] > A[j+1])
			{
				tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}
}
