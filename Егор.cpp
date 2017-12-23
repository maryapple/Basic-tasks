#include <iostream>
#include <vector>
using namespace std;
bool IsOdd (int a)
{
    if (a % 2 == 1)
        return true;
    return false;
}
void Input (vector<int> A, vector<int> B)
{
    int num = 0;
    cin >> num;
    while (num >= 0)
    {
        A.push_back (num);
        cin >> num;
    }
    num = 0;
    while (num >= 0)
    cin >> num;
    {
        B.push_back (num);
        cin >> num;
    }
}
void CreateC (vector<int> A, vector<int> B, vector<int> C)
{
    for (int i = 0; i < sizeof (A); i++)
    {
        if (IsOdd (A [i] + B [i]))
            C [i] = A [i] * A [i] - B [i] * B [i];
        else
            C [i] = B [i];
    }
}
int FindZero (vector<int> A)
{
    for (int i = 0; i < sizeof (A); i++)
        if (A [i] == 0)
            return i;
    return -1;
}
void Sort (vector<int> a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int tmp = a [i];
        int j = i - 1;
        for ( ; j >= 0 && a [j] < tmp; j--)
            a [j + 1] = a [j];
        a [j + 1] = tmp;
    }
}
int main ()
{
    vector<int> A;
    vector<int> B;
    vector<int> C;
    Input (A, B);
    CreateC (A, B, C);
    for (int i = 0; i < sizeof (C); i++)
        cout << C [i] << " ";
    cout << endl << endl;
    cout << "First zero in A: " << FindZero (A) << "First zero in B: " << FindZero (B) << "First zero in C: " << FindZero (C) << "(If '-1' printed, no 0 in array)" << endl;
    Sort (C, sizeof (C));
    cout << "Sorted Array: ";
    for (int i = 0; i < sizeof (C); i++)
        cout << C [i] << " ";
    return 0;
}
