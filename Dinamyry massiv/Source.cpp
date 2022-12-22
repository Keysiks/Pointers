#include<iostream>
using namespace std;


//#define CLASS
//#define Dynamiry
//#define MATRIX
#define HOMEWORK
template<typename T>void Fillrand(T arr[], int n);
template<typename T>void print_array(T arr[], int n);
template<typename T>T* push_back(T* arr, int& size, T value);
template<typename T>T* insert(T* arr, int& size, int index, T value);
template<typename T>T* pop_back(T* arr, int& size);
template<typename T>T* pop_front(T* arr, int& size);
template<typename T>T* erase(T* arr, int& size, int index);

void FillRand(int** arr, int rows, int cols);
template<typename T>void print_array(T** arr, int rows, int cols);

template<typename T>T** push_row_back(T** arr, int& rows, int& cols);
template<typename T>T** push_row_front(T** arr, int& rows, int& cols);
template<typename T>T** insert_row(T** arr, int& rows, int& cols, int index);
template<typename T>T** pop_row_back(T** arr, int& rows, int& cols);
template<typename T>T** pop_row_front(T** arr, int& rows, int& cols);
template<typename T>T** erase_row(T** arr, int& rows, int& cols, int index);
template<typename T>void push_col_back(T** arr, int rows, int& cols);

template<typename T>T** allocate(int rows, int cols);
template<typename T>void clear(T** arr, int rows, int cols);

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

#ifdef HOMEWORK
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
	clear(arr, rows, cols);
#endif //HOMEWORK

	//int rows, cols;
	//cout << "Enter count of rows and cols: "; cin >> rows >> cols;
	//int** arr = new int* [rows];
	//for (int i = 0; i < rows; i++)
	//	//создаем строки двумерного массива
	//	arr[i] = new int[cols];
	//FillRand(arr, rows, cols);
	//print_array(arr, rows, cols);
	//cout << endl;

	//push_col_back(arr, rows, cols);
	//print_array(arr, rows, cols);
}
template<typename T>void print_array(T arr[], int n) {
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

template<typename T>T* push_back(T* arr, int& size, T value) {
	T* buffer = new T[size + 1];
	for (int i = 0; i < size; i++)
		buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[size] = value;
	size++;
	return arr;
}

template<typename T>T* insert(T* arr, int& size, int index, T value) {
	bool f = false;
	T* buffer = new T[size + 1];
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

template<typename T>T* pop_back(T* arr, int& size) {
	T* buffer = new T[size - 1];
	for (int i = 0; i < size - 1; i++)
		buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	size--;
	return arr;
}

template<typename T>T* pop_front(T* arr, int& size) {
	T* buffer = new T[size - 1];
	for (int i = 1; i < size; i++)
		buffer[i - 1] = arr[i];
	delete[] arr;
	arr = buffer;
	size--;
	return arr;
}

template<typename T>T* erase(T* arr, int& size, int index) {
	bool f = false;
	T* buffer = new T[size - 1];
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

template<typename T>void print_array(T** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}

template<typename T>T** push_back_row(T** arr, int& rows, int& cols) {
	//1. —оздаем буферный массив указателей
	T** buffer = new T*[rows + 1];
	//2.  опируем указатели
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i];
	//3. ”дал€ем исходный массив указателей и мен€ем адрес arr нa buffer
	delete[] arr;
	arr = buffer;
	//4. —оздаем новую строку
	buffer[rows] = new T[cols];
	//5. ѕосле добавлени€ строки, кол-во строк увеличиваетс€
	rows++;
	return arr;
}

template<typename T>T** push_row_front(T** arr, int& rows, int& cols) {
	T** buffer = new T* [rows + 1];
	for (int i = 1; i < rows + 1; i++)
		buffer[i] = arr[i - 1];
	delete[] arr;
	rows++;
	buffer[0] = new T[cols] {};
	return buffer;
}

template<typename T>T** insert_row(T** arr, int& rows, int& cols, int index) {
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows + 1; i++)
		if (i < index) buffer[i] = arr[i]; else buffer[i + 1] = arr[i];
	delete[] arr;
	rows++;
	buffer[index] = new T[cols] {};
	return buffer;

}

template<typename T>T** pop_row_back(T** arr, int& rows, int& cols) {
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
		buffer[i] = arr[i];
	delete[] arr[rows - 1];
	rows--;
	delete[] arr;
	return buffer;
}

template<typename T>T** pop_row_front(T** arr, int& rows, int& cols) {
	T** buffer = new T* [rows - 1];
	for (int i = 1; i < rows; i++)
		buffer[i - 1] = arr[i];
	delete[] arr[0];
	rows--;
	delete[] arr;
	return buffer;
}

template<typename T>T** erase_row(T** arr, int& rows, int& cols, int index) {
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows; i++)
		if (i < index) buffer[i] = arr[i]; else buffer[i] = arr[i + 1];
	delete[] arr[index];
	delete[] arr;
	return buffer;
}

template<typename T>T** allocate(int rows, int cols) {
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
		//создаем строки двумерного массива
		arr[i] = new int[cols];
	return arr;
}

template<typename T>void clear(T** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;
}

template<typename T>void push_col_back(T** arr, int rows, int& cols) {
	for (int i = 0; i < rows; i++) {
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)
			buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
