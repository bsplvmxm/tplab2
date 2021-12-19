#include "helper.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

bool isSplitterSuggestion(const char& ch) {
	return ch == '.' || ch == '?' || ch == '!' || ch == ')' || ch == '(' || ch == '\n' || ch == '\0';
}


bool isSplitterWord(const char& ch) {
	return isSplitterSuggestion(ch) || ch == ',' || ch == ' ' || ch == ':';
}

std::string task(const string& s, const string& word) {
	std::string ans = "";
	bool isWord = false, isSuggestion = false;
	int countWord = 0;
	int startWord = -1;
	int startSuggestoin = 0;
	int number = 1;
	for (int i = 0; i < s.size(); i++) {
		if (isSplitterWord(s[i])) {
			if (isWord) {
				bool flag = true;
				if (word.size() != i - startWord)
					flag = false;
				else
					for (int j = 0; j < word.size(); j++)
						if (word[j] != s[startWord + j])
							flag = false;
				if (flag)
					countWord++;
			}
			isWord = false;
			if (isSplitterSuggestion(s[i])) {
				if (countWord > 0)
					ans.append(s.substr(startSuggestoin, i + 1 - startSuggestoin));
				startSuggestoin = i + 1;
				countWord = 0;
			}
		}
		else {
			if (!isWord) {
				isWord = true;
				startWord = i;
			}
		}
	}
	return !ans.empty() ? ans : "В файле нет предложений заданной длины\n";
}

string readFile(ifstream& input) {
	string s = "";
	string tmpS;
	while (getline(input, tmpS))
		s.append(tmpS).append("\n");
	return s;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string word;
	cout << "Введите слово: ";
	getline(cin, word);

	string filename;
	processInputNameOfInputFile(filename);
	ifstream input(filename);
	cout << "Результат работы:\n" << task(readFile(input), word);
	input.close();
}