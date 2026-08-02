#include <iostream>
#include <sstream>

using namespace std;

int const maxSize = 100;

int main()
{
	int* arr = new int[maxSize];

	string input;
	getline(cin, input);
	istringstream buffer(input);

	int count = 0;
	bool firstTime = true;

	do {
		if (!firstTime) {
			count++;
		}
		else {
			firstTime = false;
		}
		if (count >= maxSize) {
			cerr << "Out Of Space";
			break;
		}
	} while (buffer >> arr[count]);

	///lets sum it now
	int* ptr = arr;
	int* endPtr = arr + count - 1;

	while (ptr < endPtr) {
		cout << *ptr + *endPtr << ' ';
		ptr++;
		endPtr--;
	}
	if (ptr == endPtr) {
		cout << *ptr;
		ptr++;
		endPtr--;
	}

	delete[]arr;
	ptr = nullptr; endPtr = nullptr;
	return 0;
}