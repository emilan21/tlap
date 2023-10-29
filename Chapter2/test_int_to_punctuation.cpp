#include <iostream>
using std::cin;
using std::cout;

int main(void) {

	cout << "Enter a number 1-8: ";
	int number;
	cin >> number;
	char output_character;

	switch (number) {
		case 1: output_character = '!'; break;	
		case 2: output_character = '?'; break;	
		case 3: output_character = ','; break;	
		case 4: output_character = '.'; break;	
		case 5: output_character = ' '; break;	
		case 6: output_character = ';'; break;	
		case 7: output_character = '"'; break;	
		case 8: output_character = '\''; break;	
	}
	cout << "Equivalent symbol: " << output_character << "\n";

	return 0;
}
