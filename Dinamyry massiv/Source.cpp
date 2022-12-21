#include<iostream>
using namespace std;

//#define CLASS
void Fillrand(int arr[], int n);
void print_array(int arr[], int n);
int* push_back(int* arr, int& size, int value);
int* insert(int* arr, int& size, int index, int value);
int* pop_back(int* arr, int& size);
int* pop_front(int* arr, int& size);
int* erase(int* arr, int& size, int index);


void main() {
#ifdef CLASS
	srand(time(NULL));
	int size; cout << "Enter count of elements: "; cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		*(arr + i) = rand() % 100;
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;

	Fillrand(arr, size);
	
	int value; cout << "Enter value: "; cin >> value;
	arr = push_back(arr, size, value);

	print_array(arr, size);
	delete[] arr;
#endif //CLASS
	srand(time(NULL));
	int size; cout << "Enter count of elements: "; cin >> size;
	int* arr = new int[size];
	cout << "Enter value and index: "; int index, value; cin >> value >> index;
	for (int i = 0; i < size; i++) 
		*(arr + i) = rand() % 100;
	print_array(arr, size);
	arr = insert(arr, size, index, value);
	print_array(arr, size);

	arr = pop_back(arr, size);
	print_array(arr, size);

	arr = pop_front(arr, size);
	print_array(arr, size);

	int index_erase; cout << "Enter index to erase: "; cin >> index_erase;
	arr = erase(arr, size, index_erase);
	print_array(arr, size);

	delete[] arr;
}

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

void Fillrand(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand();
	}
	print_array(arr, n);
}

int* push_back(int* arr, int& size, int value) {
	int* buffer = new int[size + 1];
	for (int i = 0; i < size; i++)
		buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[size] = value;
	size++;
	return arr;
}

int* insert(int* arr, int& size, int index, int value) {
	bool f = false;
	int* buffer = new int[size + 1];
	for (int i = 0; i < size + 1; i++) {
		if (i != index && not(f))
			buffer[i] = arr[i];
		else if (i == index) {
			f = true; 
			buffer[i + 1] = arr[i];
		}
		else buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	size++;
	return arr;
}

int* pop_back(int* arr, int& size) {
	int* buffer = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
		buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	size--;
	return arr;
}

int* pop_front(int* arr, int& size) {
	int* buffer = new int[size - 1];
	for (int i = 1; i < size; i++)
		buffer[i - 1] = arr[i];
	delete[] arr;
	arr = buffer;
	size--;
	return arr;
}

int* erase(int* arr, int& size, int index) {
	bool f = false;
	int* buffer = new int[size - 1];
	for (int i = 0; i < size - 1; i++) {
		if (i != index && not(f))
			buffer[i] = arr[i];
		else if (i == index) {
			f = true;
			buffer[i] = arr[i + 1];
		}
		else buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	--size;
	return arr;
}