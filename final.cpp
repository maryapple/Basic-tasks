#include <iostream>
#define n 6
#define m 4

using namespace std;

void input(int A[n][m]);
void output2(int A[n][m]);
void make_array(int A[n][m], int B[m]);
void output1(int B[m]);
void sort_lines(int A[n][m]);

int main(){
	int A[n][m], B[m];
	input(A);
	cout << "\nInitial array: \n";
	output2(A);
	make_array(A, B);
	cout << "\nArray of indexes of minimal elements in columns: \n\t";
	output1(B);
	sort_lines(A);
	cout << "\n\nSorted array:\n";
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

void make_array(int A[n][m], int B[m]){
	int i=0, j=0, min=0, index=0;
	for (j=0; j<m; j++){
		min=A[0][j]; 
		index=0;
		for (i=0; i<n; i++){
			if (A[i][j] < min){ 
				min=A[i][j];
				index=i;
			}
		}
		B[j]=index;
	}
}

void output1(int B[m]){
	int j=0;
	for (j=0; j<m; j++) cout << B[j] << "\t";
}

void sort_lines(int A[n][m]){
	int i=0, j=0, buf=0, k=0;
	for (i=0; i<n; i++){
		for (k=0; k<m-1; k++){
			for (j=0; j<m-1; j++){
				if (A[i][j] > A[i][j+1]){
					buf=A[i][j];
					A[i][j]=A[i][j+1];
					A[i][j+1]=buf;
				}
			}
		}
	}
}
