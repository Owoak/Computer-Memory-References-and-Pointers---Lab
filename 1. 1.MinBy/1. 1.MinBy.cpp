#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

const string* lexicographically(const vector <string>& words) {
	const string* earlies = &words[0];

	for (size_t n = 1; n < words.size(); n++) {
		const string* next = &words[n];
		if (*earlies > *next) {
			earlies = next;
		}
	}

	return earlies;
}

const string* shortestString(const vector <string>& words) {
	const string* shortest = &words[0];

	for (size_t i = 1; i < words.size(); i++) {
		const string* next = &words[i];
		if ((*shortest).size() > (*next).size()) {
			shortest = next;
		}
	}

	return shortest;
}
const string* longestString(const vector <string>& words) {
	const string* longest = &words[0];

	for (size_t i = 1; i < words.size(); i++) {
		const string* next = &words[i];
		if ((*longest).size() < (*next).size()) {
			longest = next;
		}
	}

	return longest;
}

int main()
{
	string input;
	getline(cin, input);
	istringstream buffer(input);

	vector <string> words;
	string word;
	while (buffer >> word) {
		words.push_back(word);
	}

	int type;
	cin >> type;

	const string* (*func)(const vector <string>&words);

	switch (type) {
	case 1:
		func = lexicographically;
		cout << *(func(words));
		break;
	case 2:
		func = shortestString;
		cout << *(func(words));
		break;
	case 3:
		func = longestString;
		cout << *(func(words));
		break;
	}

	return 0;
}