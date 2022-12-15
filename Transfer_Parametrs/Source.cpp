#include <iostream>
using namespace std;


void exchange(int* a, int* b) { 
	int temp = *a;
	*a = *b;
	*b = temp;
}
void main() {
	int a = 2; int b = 3;
	cout << a << " " << b << endl;
	exchange(&a, &b);
	cout << a << " " << b << endl;
}