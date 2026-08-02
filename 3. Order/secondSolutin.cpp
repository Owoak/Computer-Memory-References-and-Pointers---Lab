#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	map <unsigned int, const char*> map;
	vector <char> buffer;
	buffer.reserve(1000);
	buffer.resize(1);
	const char* currentChar = buffer.data();// or = &buffer[0]

	bool firstRun = true;
	while (true) {
		string nameInput;
		cin >> nameInput;
		if (nameInput == "end")
			break;
		unsigned int id;
		cin >> id;

		for (char& a : nameInput) {
			buffer.push_back(a);
		}
		buffer.push_back('\0');

		if (firstRun) {
			currentChar++;
			firstRun = false;
		}
		map[id] = currentChar; //!!!!
		currentChar += nameInput.size() + 1;
	}

	for (auto it = map.begin(); it != map.end(); it++) {
		cout << (*it).second << ' ' << (*it).first << endl;
	}

	return 0;
}