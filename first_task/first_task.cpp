#include <iostream>
#include <ctime>

int main() {
	srand(time(NULL));
	int arr[20];
	for (int i = 0;i < 20;i++) {
		arr[i] = rand() % 51;
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	int max = arr[0];
	int min = arr[1];
	for (int i = 0;i < 20;i++) {
		if (arr[i] > max)max = arr[i];
		if (arr[i] < min)min = arr[i];
	}

	std::cout << "Разница = " << max - min << "\n";
}