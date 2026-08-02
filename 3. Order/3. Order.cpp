#include <map>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
	map <unsigned int, const char*> map;
	char buffer[1000] = {};
	char* currentChar = buffer;// or = &buffer[0]

	int i = 0;

	while (true) {
		string nameInput;
		cin >> nameInput;
		if (nameInput == "end")
			break;
		unsigned int id;
		cin >> id;
		;
		//strcpy(currentChar, nameInput.c_str());

		for (char& a : nameInput) {
			buffer[i] = a;
			i++;
		}
		i++;

		map[id] = currentChar; //!!!!
		currentChar += nameInput.size() + 1;
	}

	for (auto it = map.begin(); it != map.end(); it++) {
		cout << (*it).second << ' ' << (*it).first << endl;
	}

	return 0;
}