#include<iostream>
#include<map>


template<typename T>
void printMap(std::map<T, T> map) {
	for (auto it = map.begin(); it != map.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
}


int main() {

	std::map<int, int> myMap;
	for (int i = 1; i <= 9; ++i) {
		myMap[i] = i * i;
	}
	std::cout << "Dictionary:" << std::endl;
	printMap(myMap);
	
	if (myMap.count(7) == 1) {
		myMap[7] = 14;
	}
	if (myMap.count(10) == 0) {
		myMap[10] = 30;
	}
	myMap.erase(5);

	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		(it->second) += (it->first);
	}

	if (myMap.count(7) == 0) {
		myMap[7] = 5;
	}

	std::cout << "Multiplication:" << std::endl;
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		if ((it->first) % 2 != 0) {
			std::cout << (it->first) * (it->second) << std::endl;
		}
	}
	std::cout << "Dictionary:" << std::endl;
	printMap(myMap);
	
	system("pause");
	return 0;
}
