#include<iostream>


template<typename T>
void print_array(T myArray[], const int size);


int main() {

	const int SIZE = 8;
	int arr[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	std::cout << "Array: " << std::endl;
	std::cout << '\t';
	print_array(arr, SIZE);
	
	for (int i = 0; i < SIZE - 1; ++i) {
		int* pa = &arr[i];
		if (i % 2 == 0) {
			int tmp = *pa;
			*pa = *(pa + 1);
			*(pa + 1) = tmp;
		}
	}
	std::cout << std::endl;

	std::cout << "Change" << std::endl;
	std::cout << " array: " << std::endl;
	std::cout << '\t';
	print_array(arr, SIZE);
	
	system("pause");
	return 0;
}


template<typename T>
void print_array(T myArray[], const int size) {

	for (int i = 0; i < size; ++i) {
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;
}