#include <iostream>
#include <string>
#include <cmath>

int sumString(const std::string& str) {
	int sum = 0;
	int negative = false;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ',') {
			continue;
		}

		int code = int(str[i] - '0');

		if (str[i] == '-') {
			negative = true;
			continue;
		}

		if (negative) {
			code *= -1;
			negative = false;
		}

		sum += code;
	}

	return sum;
}
