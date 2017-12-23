#include <iostream>
#define n 4
#define m 5

using namespace std;

void input(int A[n][m]);
void output2(int A[n][m]);
void make_array(int A[n][m], int B[n]);
void output1(int B[n]);
void sort_columns(int A[n][m]);

int main(){
	int A[n][m], B[n];
	input(A);
	cout << "\nInitial array: \n";
	output2(A);
	make_array(A, B);
	cout << "\nArray of even numbers: \n";
	output1(B);
	sort_columns(A);
	cout << "\nSorted array:\n";
	output2(A);
	return 0;
}

void input(int A[n][m]){
	int i=0, j=0;
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			cout << "Enter [" << i << "][" << j << "] element: ";
			cin >> A[i][j];
		}
	}
}

void output2(int A[n][m]){
	int i=0, j=0;
	for (i=0; i<n; i++){
		for (j=0; j<m; j++) cout << "\t" << A[i][j];
		cout << endl;
	}
}

void make_array(int A[n][m], int B[n]){
	int i=0, j=0, min=0, k=0;
	for (i=0; i<n; i++){
		k=0;
		for (j=0; j<m; j++){
			if (A[i][j]%2!=0){
				k++;
			}
		}
		B[i]=k;
	}
}

void output1(int B[n]){
	int j=0;
	for (j=0; j<n; j++) cout << B[j] << "\t";
}

void sort_columns(int A[n][m]){
	int i, j, k, tmp;
	for (j = 0; j < m; j++){
		for (k = 0; k < n - 1; k++){
			for (i = 0; i < n - 1; i++){
				if (A[i][j] > A[i + 1][j]){
					tmp = A[i][j];
					A[i][j] = A[i + 1][j];
					A[i + 1][j] = tmp;
				}
			}
		}
	}
}
