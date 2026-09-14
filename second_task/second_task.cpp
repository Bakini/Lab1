#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

int main() {
	srand(time(NULL));
	int colvo;
	std::cin >> colvo;
	std::vector<int> a(colvo);
	for (int i = 0;i < colvo;i++) {
		a[i] = rand() % 51;
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
}
