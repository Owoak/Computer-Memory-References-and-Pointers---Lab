#include <vector>
#include <iostream>
#include <map>

using namespace std;

void firstSubTask(vector<char>& buffer) {
	cout << "Address of buffer's first byte: " << buffer.data() << endl;
	cout << "sizeof(char): " << sizeof(char) << ", sizeof(int) : " << sizeof(int);
}
void bumpGrade(int& grade, int amount) {
	cout << "Bumping last student's grade by 5..." << endl << "Before: " << grade << " After: " << grade + amount;
	grade += amount;
}

const char* findStudentName(unsigned int id, const map<unsigned int, const char*>& roster) {
	return nullptr;
}

int main()
{
	vector<unsigned int> insertionOrder;
	vector<int> grades;
	vector<char> buffer;
	buffer.reserve(1000);
	buffer.resize(1);
	const char* ptr = &buffer[0];
	map<unsigned int, const char*> roster;

	bool firstTime = true;

	while (true) {
		string name;
		cin >> name;
		if (name == "end")
			break;
		int id, grade;
		cin >> id, grade;

		if (firstTime) {
			ptr++;
			firstTime = false;
		}

		for (char& a : name) {
			buffer.push_back(a);
		}
		buffer.push_back('\0');

		roster[id] = ptr;
		grades.push_back(grade);
		insertionOrder.push_back(id);
	}
	int& grade = grades.back();
	bumpGrade(grade, 5);

	return 0;
}