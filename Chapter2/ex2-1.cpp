#include <iostream>
using std::cin;
using std::cout;

int main(void) {
	for (int row = 1; row <= 4; row++) {
		for (int hash_num = 1; hash_num <= 9 - row; hash_num++) {
			cout << "#";
		}
		cout << "\n";
	}

	return 0;
}
