#include <iostream>
using std::cin;
using std::cout;

int main(void) {

	cout << "Enter a number: ";
	char digit;
	while (true) {
		digit = cin.get();
		cout << int(digit) << " ";
	}

	return 0;
}
