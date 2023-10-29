#include <iostream>
using std::cin;
using std::cout;

int main(void) {

	char output_character;
	enum MODETYPE {UPPERCASE, LOWERCASE, PUNCTUATION};
	MODETYPE mode = UPPERCASE; 
	char digit_char;

	do {
		digit_char = cin.get();	
		int number = (digit_char - '0');
		digit_char = cin.get();	

		while ((digit_char != 10) && (digit_char != ',')) {
			number = number * 10 + (digit_char - '0');
			digit_char = cin.get();	
		}
		switch (mode) {
			case UPPERCASE:
				number = number % 27;
				output_character = number + 'A' -1;
				if (number == 0) {
					mode = LOWERCASE;
					continue;
				}
				break;
			case LOWERCASE:
				number = number % 27;
				output_character = number + 'a' -1;
				if (number == 0) {
					mode = PUNCTUATION;
					continue;
				}
				break;
			case PUNCTUATION:
				number = number % 9;
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
				if (number == 0) {
					mode = UPPERCASE;
					continue;
				}
				break;
		}
		cout << output_character;
	} while (digit_char != 10);
	cout << "\n";
	
	return 0;
}
