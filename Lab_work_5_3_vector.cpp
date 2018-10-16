#include<iostream>
#include<vector>


int main() {

	std::vector<int> vec;
	for (int i = 1; i < 99; ++i) {
		if (i % 2 == 0) {
			vec.push_back(i);
		}
	}
	std::cout << "Size:" << '\t' << vec.size() << std::endl;
	std::cout << "Capacity:" << '\t' << vec.capacity() << std::endl;
	vec[0] = vec.size();
	
	for (int i = 0; i < vec.size(); ++i) {
		if (i == 7 || i == 14 - 1 || i == 21 - 2) {
			for (int j = i; j < vec.size() - 1; ++j) {
				while (j < vec.size() - 1) {
					int tmp = vec[j];
					vec[j] = vec[j + 1];
					vec[j + 1] = tmp;
					++j;
				}
			}
		}
	}
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	
	int count = 0;
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] % 4 == 0) {
			++count;
		}
	}
	std::cout << "Count of elements is multiple 4:" << '\t' << count << std::endl;

	vec[20] = 99;
	vec.pop_back();
	vec[vec.size() - 1] = 101;

	std::cout << "Vector size end elements:" << std::endl;
	std::cout << vec.size() << '\t';
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	
	system("pause");
	return 0;
}