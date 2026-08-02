#include <iostream>
#include <string>
using namespace std;

bool isNumberString(string& input) {
	size_t count = 0;
	const char* ptr = input.c_str();

	while (count < input.size()) {
		if (!(*ptr >= '0' and *ptr <= '9')) {
			return false;
		}
		ptr++; count++;
	}
	return true;
}

int main()
{
	string input1, input2;
	cin >> input1 >> input2;

	bool isNumber1 = isNumberString(input1);
	bool isNumber2 = isNumberString(input2);

	if (isNumber1 and isNumber2) {
		cout << stoi(input1) + stoi(input2);
	}
	else {
		if (isNumber1) {
			cout << stoi(input1) << endl << "[error] " << input2;
		}
		else if (isNumber2) {
			cout << "[error] " << input1 << endl << stoi(input2);
		}
		else {
			cout << "[error] " << input1 << endl << "[error] " << input2;
		}
	}
}