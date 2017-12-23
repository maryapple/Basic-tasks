#include <iostream>

using namespace std;

int main(){
	int num=0, i=2;
	cin >> num;
	while (num>1){
		while (num%i==0){
			cout << i << "\t";
			num/=i;
		}
		i++;
	}
	return 0;
}
