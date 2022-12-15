#include<iostream>
using namespace std;


//#define POINTERS_TEORY

void main() {
#ifdef POINTERS_TEORY
	int a = 2;
	int* pa = &a;
	cout << a << endl; //вывод переменной a
	cout << &a << endl; // взятие адреса переменной a при выводе
	cout << pa << endl; //вывод адреса переменной а
	cout << *pa << endl; //разыименование указателя pa
#endif //POINTERS_TEORY

	const int n = 5;
	int arr[n] = { 3, 2, 5, 8, 9 };
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
		cout << arr + i << "\t";
	cout << endl;
}