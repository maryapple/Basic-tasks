#include <iostream>

using namespace std;

int input(int A[]);
void newArray1(int A[], int B[], int A1[], int N);
void newArray2(int A[], int B[], int B1[], int N);
void output(int A[], int N);
int sum(int A[], int N, int n);
void sort(int A[], int N);

int main(){
	int A[100], B[100], A1[100], B1[100], N=0, n=0;
	cout << "Enter the elements of A[]:\n";
	N = input(A);
	cout << "\nEnter the elements of B[]:\n";
	N = input(B);
	cout << "A[]: ";
	output(A, N);
	cout << "\nB[]: ";
	output(B, N);
	newArray1(A, B, A1, N);
	newArray2(A, B, B1, N);
	cout << "\nNew A[]: ";
	output(A1, N);
	cout << "\nNew B[]: ";
	output(B1, N);
	
	cout << "\nEnter n: ";
	cin >> n;
	cout << "\nThe sum of elements that are >n in A[] is: ";
	cout << sum(A, N, n);
	cout << "\nThe sum of elements that are >n in B[] is: ";
	cout << sum(B, N, n);
	cout << "\nThe sum of elements that are >n in A1[] is: ";
	cout << sum(A1, N, n);
	cout << "\nThe sum of elements that are >n in B1[] is: ";
	cout << sum(B1, N, n);
	
	sort(A1, N);
	cout << "\nSorted A1[]: ";
	output(A1, N);
	sort(B1, N);
	cout << "\nSorted B1[]: ";
	output(B1, N);
	return 0;
}

int input(int A[]){
	int i=0;
	for (i=0; i<100; i++){
		cout << "enter the element, negative to exit: ";
		cin >> A[i];
		if (A[i] < 0) return i;
	}
	return i;
}

void newArray1(int A[], int B[], int A1[], int N){
	int i=0;
	for (i=0; i<N; i++) A1[i] = A[i]+B[i];
}

void newArray2(int A[], int B[], int B1[], int N){
	int i=0;
	for (i=0; i<N; i++) B1[i] = A[i]*B[i];
}

void output(int A[], int N){
	int i=0;
	for (i=0; i<N; i++) cout << A[i] << " ";
}

int sum(int A[], int N, int n){
	int sum=0, i=0;
	for (i=0; i<N; i++){
		if (A[i] > n) sum+=A[i];
	}
	return sum;
}

void sort(int A[], int N){
	int i=0, buf=0, j=0;
	for (j=0; j<N-1; j++){
		for (i=0; i<N-1; i++){
			if(A[i] > A[i+1]){
				buf=A[i];
				A[i]=A[i+1];
				A[i+1]=buf;
			}
		}
	}
}
