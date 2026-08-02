#include <unordered_map>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	char buffer[10000] = {};
	char* nextName = buffer;

	unordered_map<int, char*> map;

	while (true) {
		string name;
		cin >> name;

		if (name == "end")
			break;

		int id;
		cin >> id;

		strcpy(nextName, name.c_str());
		map[id] = nextName;

		nextName += name.size() + 1;
	}

	int searchID;
	cin >> searchID;

	auto it = map.find(searchID);
	if (it == map.end()) {
		cout << "[not found]";
	}
	else {
		cout << (*it).second << ' ' << (*it).first << endl;
	}
}