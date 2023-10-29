#include <iostream>
using std::cin;
using std::cout;

int double_digit_value(int digit);

int main(void) {

	char  digit;
	int odd_length_checksum = 0;
	int even_length_checksum = 0;
	int position = 1;

	cout << "Enter a number: ";
	digit = cin.get();
	while (digit != 10) {
		if (position % 2 == 0) {
			odd_length_checksum += double_digit_value(digit - '0');	
			even_length_checksum += digit - '0';	
		} else {
			odd_length_checksum += digit - '0';	
			even_length_checksum += double_digit_value(digit - '0');	
		}
		digit = cin.get();
		position++;
	}

	int checksum;
	if ((position - 1) % 2 == 0) {
		checksum = even_length_checksum;	
	} else {
		checksum = odd_length_checksum;	
	}

	cout << "Checksum is  " << checksum << ". \n";

	if (checksum % 10 == 0) {
		cout << "Checksum is divisible by 10. Valid. \n";
	} else {
		cout << "Checksum is not divisible by 10. Invalid. \n";
	}

	return 0;	
}

int double_digit_value(int digit) {
	int double_digit = digit * 2;
	int sum;

	if (double_digit >= 10) {
		sum = 1 + double_digit % 10;
	} else {
		sum = double_digit;	
	}

	return sum;
}
