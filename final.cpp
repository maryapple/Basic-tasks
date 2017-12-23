#include <iostream>
#define N 3
#define M 4

using namespace std;

void input(int ** A, int *n);
void output_array2(int ** A);
void output(int * A, int negative_odd_cnt, int negative_even_cnt, int n);
void make_array(int ** A, int * B);
void get_answer(int * A, int n, int *negative_odd_cnt, int *negative_even_cnt);

int main() {
	int n = 0, negative_odd_cnt = 0, negative_even_cnt = 0;
	int ** A = new int *[N];
	for (int i = 0; i < N; i++)
		A[i] = new int[M];
	int * B = new int[N * M];
	input(A, &n);
	make_array(A, B);
	get_answer(B, n, &negative_odd_cnt, &negative_even_cnt);
	output_array2(A);
	output(B, negative_odd_cnt, negative_even_cnt, n);

	return 0;
}

void input(int ** A, int *n)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << "Enter A[" << i << "][" << j << "]: ";
			cin >> A[i][j];
		}
	}
	cout << "Enter n: ";
	cin >> *n;
}

void output_array2(int ** A)
{
	cout << "2-dimensions array:\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << "\t" << A[i][j];
		cout << "\n";
	}
}

void output(int * A, int negative_odd_cnt, int negative_even_cnt, int n)
{
	cout << "1-dimension array:\n";
	for (int i = 0; i < N * M; i++)
		cout << A[i] << " ";
	cout << "\n";
	if (negative_even_cnt + negative_odd_cnt < n)
		cout << "There are less than " << n << " negative numbers in the array!\n";
	else
		cout << "There are " << negative_even_cnt << " even negative numbers and " << negative_odd_cnt << " odd negative numbers among first " << n << " negative elements in the array.\n";
}

void make_array(int ** A, int * B)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			B[i * M + j] = A[i][j];
}

void get_answer(int * A, int n, int *negative_odd_cnt, int *negative_even_cnt)
{
	*negative_odd_cnt = 0;
	*negative_even_cnt = 0;
	for (int i = 0; i < N * M; i++)
	{
		if ((*negative_even_cnt) + (*negative_odd_cnt) == n)
			break;
		if (A[i] < 0)
		{
			if ((-A[i]) % 2 == 0)
				(*negative_even_cnt)++;
			else
				(*negative_odd_cnt)++;
		}
	}
}
