#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool isLexicographicallySmaller(const string& a, const string& b) {
	return a < b;
}

bool isShorter(const string& a, const string& b) {
	return a.length() < b.length();
}

bool isLonger(const string& a, const string& b) {
	return a.length() > b.length();
}

int main() {
	string lineBuf;
	getline(cin, lineBuf);
	istringstream istr(lineBuf);

	vector<string> words;
	while (istr >> lineBuf)
		words.push_back(lineBuf);

	int type;
	cin >> type;

	bool (*func)(const string & a, const string & b) = nullptr;

	switch (type) {
	case 1:
		func = isLexicographicallySmaller;
		break;
	case 2:
		func = isShorter;
		break;
	case 3:
		func = &isLonger;
		break;
	}

	string result = words[0];
	for (size_t idx = 1; idx < words.size(); idx++)
		if (func(words[idx], result))
			result = words[idx];

	cout << result << endl;

	return 0;
}