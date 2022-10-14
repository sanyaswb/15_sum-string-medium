#include "test.h"
#include "../index.h"
#include "termcolor.hpp"

#include <iostream>
#include <string>

using namespace std;

string boolString(bool value) {
	return value ? "true" : "false";
}

struct Option {
		int toBe;
		std::string str;
};

Option options[] = {
		{
				5,
				"-1,2,3,-4,5"
		},
		{
				15,
				"9,-6,4,7,1,-5,2,3,0"
		},
		{
				2,
				"3,2,-4,1"
		},
		{
				19,
				"6,3,-2,4,6,2"
		},
		{
				20,
				"53435"
		},
		{
				4,
				"-2,3,4,6,-7"
		}
};

void printGreen(const string& test, const string& result) {
	cout << termcolor::green << "TEST " << "\"" << test << "\"" << " PASSED! RESULT: " << result << endl;
}

void printRed(const string& test, const string& expected, const string& result) {
	cout << termcolor::red << "TEST " << "\"" << test << "\"" << " FAILED! EXPECTED: \"" << expected << "\" INSTEAD OF " << result << "!" << endl;
}

void test() {
	cout << endl;

	int optionsLength = sizeof(options) / sizeof(options[0]);

	for (int i = 0; i < optionsLength; i++) {
		Option option = options[i];

		int result = sumString(option.str);

		string testStr = option.str;

		if (result == option.toBe) {
			printGreen(testStr, to_string(result));
		} else {
			printRed(testStr, to_string(option.toBe), to_string(result));
		}

		cout << endl;
	}
}