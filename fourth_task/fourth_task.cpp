#include <iostream>
#include <cstdlib>

int main() {
	srand(time(NULL));
	int mass[20][20];
	for (int i = 0;i < 20;i++) {
		for (int j = 0;j < 20;j++) {
			mass[i][j] = rand() % 20;
			std::cout << mass[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";

	for (int j = 0;j < 20;j++) {
		int sum = 0;
		for (int i = 0;i < 20;i++) {
			sum += mass[i][j];
		}
		std::cout << "ROW: " << j+1 << " - " << sum << "\n";
	}
}