#include<iostream>
using namespace std;


//#define POINTERS_TEORY

void main() {
#ifdef POINTERS_TEORY
	int a = 2;
	int* pa = &a;
	cout << a << endl; //����� ���������� a
	cout << &a << endl; // ������ ������ ���������� a ��� ������
	cout << pa << endl; //����� ������ ���������� �
	cout << *pa << endl; //�������������� ��������� pa
#endif //POINTERS_TEORY

	const int n = 5;
	int arr[n] = { 3, 2, 5, 8, 9 };
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
		cout << arr + i << "\t";
	cout << endl;
}