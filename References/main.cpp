#include <iostream>
using namespace std;

void main() {
	int a = 2;
	int& ra = a;
	cout << ra << endl;
	cout << &ra;
}