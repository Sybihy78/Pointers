#include<iostream>
#include<ctime>
#include<vector>


void print_array(int myArray[], const int size);
void print_vector(std::vector<int> myVec);
void print_vector_with_delete_same_elements(std::vector<int> myVec);
std::vector<int> vec_all_elements(int myArray_1[], const int size_1, int myArray_2[], const int size_2);
std::vector<int> vec_same_elements(int myArray_1[], const int size_1, int myArray_2[], const int size_2);
std::vector<int> vec_only_arr1_elements(int myArray_1[], const int size_1, int myArray_2[], const int size_2);
std::vector<int> vec_arr1_or_arr2_elements(int myArray_1[], const int size_1, int myArray_2[], const int size_2);


int main() {

	srand(time(NULL));
	const int SIZE = 10;
	int arr_1[SIZE];
	int arr_2[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		arr_1[i] = rand() % 10;
	}
	for (int i = 0; i < SIZE; ++i) {
		arr_2[i] = rand() % 10;
	}
	print_array(arr_1, SIZE);
	print_array(arr_2, SIZE);
	
	vec_all_elements(arr_1, SIZE, arr_2, SIZE);
	vec_same_elements(arr_1, SIZE, arr_2, SIZE);
	vec_only_arr1_elements(arr_1, SIZE, arr_2, SIZE);
	vec_arr1_or_arr2_elements(arr_1, SIZE, arr_2, SIZE);

	std::cout << std::endl;
	system("pause");
	return 0;
}


std::vector<int> vec_all_elements(int myArray_1[], const int size_1, int myArray_2[], const int size_2) {

	std::vector<int> myVec;

	int* pa_1 = myArray_1;
	int* pa_2 = myArray_2;
	
	while (pa_1 != myArray_1 + size_1) {
		myVec.push_back(*pa_1);
		++pa_1;
	}
	while (pa_2 != myArray_2 + size_2) {
		myVec.push_back(*pa_2);
		++pa_2;
	}
	print_vector(myVec);
	return myVec;
}


std::vector<int> vec_same_elements(int myArray_1[], const int size_1, int myArray_2[], const int size_2) {

	std::vector<int> myVec;

	for (int* prev1 = myArray_1; prev1 < myArray_1 + size_1; ++prev1) {
		for (int* prev2 = myArray_2; prev2 < myArray_2 + size_2; ++prev2) {
			if (*prev1 == *prev2) {
				myVec.push_back(*prev1);
				break;
			}
		}
	}

	if (myVec.size() == 0) {
		std::cout << "Not the same elements in arrays" << std::endl;
	}
	else {
		print_vector_with_delete_same_elements(myVec);
	}

	return myVec;
}


std::vector<int> vec_only_arr1_elements(int myArray_1[], const int size_1, int myArray_2[], const int size_2) {

	std::vector<int> myVec;

	for (int* prev1 = myArray_1; prev1 < myArray_1 + size_1; ++prev1) {
		int sum = 0;
		for (int* prev2 = myArray_2; prev2 < myArray_2 + size_2; ++prev2) {
			if (*prev1 != *prev2) {
				++sum;
			}
		}
		if (sum == size_2) {
			myVec.push_back(*prev1);
		}
	}

	if (myVec.size() == 0) {
		std::cout << "Not the different elements in first array" << std::endl;
	}
	else {
		print_vector_with_delete_same_elements(myVec);
	}

	return myVec;
}


std::vector<int> vec_arr1_or_arr2_elements(int myArray_1[], const int size_1, int myArray_2[], const int size_2) {

	std::vector<int> myVec;

	for (int* prev1 = myArray_1; prev1 < myArray_1 + size_1; ++prev1) {
		int sum = 0;
		for (int* prev2 = myArray_2; prev2 < myArray_2 + size_2; ++prev2) {
			if (*prev1 != *prev2) {
				++sum;
			}
		}
		if (sum == size_2) {
			myVec.push_back(*prev1);
		}
	}
	for (int* prev2 = myArray_2; prev2 < myArray_2 + size_2; ++prev2) {
		int sum = 0;
		for (int* prev1 = myArray_1; prev1 < myArray_1 + size_1; ++prev1) {
			if (*prev2 != *prev1) {
				++sum;
			}
		}
		if (sum == size_1) {
			myVec.push_back(*prev2);
		}
	}

	if (myVec.size() == 0) {
		std::cout << "Not the different elements in first and second array" << std::endl;
	}
	else {
		print_vector_with_delete_same_elements(myVec);
	}

	return myVec;
}


void print_array(int myArray[], const int size) {

	for (int i = 0; i < size; ++i) {
		std::cout << myArray[i] << " ";
	}
	std::cout << std::endl;
}


void print_vector(std::vector<int> myVec) {

	for (int i = 0; i < myVec.size(); ++i) {
		std::cout << myVec[i] << " ";
	}
	std::cout << std::endl;
}


void print_vector_with_delete_same_elements(std::vector<int> myVec) {

	for (int i = 0; i < myVec.size(); ++i) {
		int sum = 0;
		for (int j = i + 1; j < myVec.size(); ++j) {
			if (myVec[i] != myVec[j]) {
				++sum;
			}
			else {
				break;
			}
		}
		if (sum == myVec.size() - (i + 1)) {
			std::cout << myVec[i] << " ";
		}
	}
	std::cout << std::endl;
}



