#include <iostream>
using std::cin;
using std::cout;

int main(void) {

	cout << "Enter a number 1-26: ";
	int number;
	cin >> number;
	char output_character;
	output_character = number + 'a' - 1;
	cout << "Equivalent symbol: " << output_character << "\n";

	return 0;
}
