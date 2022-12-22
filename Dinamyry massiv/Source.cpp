#include<iostream>
using namespace std;


//#define CLASS
//#define Dynamiry
//#define MATRIX
void Fillrand(int arr[], int n);
void print_array(int arr[], int n);
int* push_back(int* arr, int& size, int value);
int* insert(int* arr, int& size, int index, int value);
int* pop_back(int* arr, int& size);
int* pop_front(int* arr, int& size);
int* erase(int* arr, int& size, int index);

void FillRand(int** arr, int rows, int cols);
void print_array(int** arr, int rows, int cols);

int** push_row_back(int** arr, int& rows, int& cols);
int** push_row_front(int** arr, int& rows, int& cols);
int** insert_row(int** arr, int& rows, int& cols, int index);
int** pop_row_back(int** arr, int& rows, int& cols);
int** pop_row_front(int** arr, int& rows, int& cols);
int** erase_row(int** arr, int& rows, int& cols, int index);

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

#ifdef Dynamiry

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

#endif //Dynamiry

#ifdef MATRIX
	int rows, cols;
	cout << "Enter count of rows and cols: "; cin >> rows >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
		//создаем строки двумерного массива
		arr[i] = new int[cols];
	FillRand(arr, rows, cols);
	print_array(arr, rows, cols);

	arr = push_back_row(arr, rows, cols);
	print_array(arr, rows, cols);
	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
#endif //MATRIX
	srand(time(NULL));

	int rows, cols;
	cout << "Enter count of rows and cols: "; cin >> rows >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
		//создаем строки двумерного массива
		arr[i] = new int[cols];
	FillRand(arr, rows, cols);
	print_array(arr, rows, cols);
	cout << endl;

	arr = push_row_front(arr, rows, cols);
	print_array(arr, rows, cols);

	int index; cout << "Enter index: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	print_array(arr, rows, cols);
	cout << endl;

	arr = pop_row_back(arr, rows, cols);
	print_array(arr, rows, cols);
	cout << endl;

	arr = pop_row_front(arr, rows, cols);
	print_array(arr, rows, cols);
	cout << endl;

	cout << "Enter index: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	print_array(arr, rows, cols);
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

void FillRand(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 100;
		}
	}
}

void print_array(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}

int** push_back_row(int** arr, int& rows, int& cols) {
	//1. —оздаем буферный массив указателей
	int** buffer = new int*[rows + 1];
	//2.  опируем указатели
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i];
	//3. ”дал€ем исходный массив указателей и мен€ем адрес arr нa buffer
	delete[] arr;
	arr = buffer;
	//4. —оздаем новую строку
	buffer[rows] = new int[cols];
	//5. ѕосле добавлени€ строки, кол-во строк увеличиваетс€
	rows++;
	return arr;
}

int** push_row_front(int** arr, int& rows, int& cols) {
	int** buffer = new int* [rows + 1];
	for (int i = 1; i < rows + 1; i++)
		buffer[i] = arr[i - 1];
	delete[] arr;
	rows++;
	buffer[0] = new int[cols] {};
	return buffer;
}

int** insert_row(int** arr, int& rows, int& cols, int index) {
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++)
		if (i < index) buffer[i] = arr[i]; else buffer[i + 1] = arr[i];
	delete[] arr;
	rows++;
	buffer[index] = new int[cols] {};
	return buffer;

}

int** pop_row_back(int** arr, int& rows, int& cols) {
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
		buffer[i] = arr[i];
	rows--;
	delete[] arr;
	return buffer;
}

int** pop_row_front(int** arr, int& rows, int& cols) {
	int** buffer = new int* [rows - 1];
	for (int i = 1; i < rows; i++)
		buffer[i - 1] = arr[i];
	rows--;
	delete[] arr;
	return buffer;
}

int** erase_row(int** arr, int& rows, int& cols, int index) {
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows; i++)
		if (i < index) buffer[i] = arr[i]; else buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
