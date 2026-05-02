#pragma once
#include <iostream>
#include <vector>
using namespace std;

enum eWhatToCount { SmallLetters = 0, CapitalLetters = 1, all = 2 };

class clsString {

private:
	string _value;

public:
	clsString() {
		_value = "";
	}

	clsString(string value) {
		_value = value;
	}

	//Set value
	void setValue(string value) {
		_value = value;
	}

	//Get value
	string value() {
		return _value;
	}

	static void printFirstLetterEachWord(string word) {
		bool isFirstLetter = true;
		cout << "\nFirst letters of this string:\n";

		for (short i = 0; i < word.size(); i++) {
			if (word[i] != ' ' && isFirstLetter) {
				cout << word[i] << endl;
			}
			isFirstLetter = (word[i] == ' ' ? true : false);
		}
	}
	void printFirstLetterEachWord() {
		return printFirstLetterEachWord(_value);
	}

	static string convertFirstLetterEachWordtoUppar(string word) {
		bool isFirstLetter = true;

		for (short i = 0; i < word.size(); i++) {
			if (word[i] != ' ' && isFirstLetter) {
				word[i] = toupper(word[i]);
			}
			isFirstLetter = (word[i] == ' ' ? true : false);
		}

		return word;
	}

	void convertFirstLetterEachWordtoUppar() {
		_value = convertFirstLetterEachWordtoUppar(_value);
	}

	static string convertFirstLetterEachWordtoLower(string word) {
		bool isFirstLetter = true;

		for (short i = 0; i < word.size(); i++) {
			if (word[i] != ' ' && isFirstLetter) {
				word[i] = tolower(word[i]);
			}
			isFirstLetter = (word[i] == ' ' ? true : false);
		}

		return word;
	}

	void convertFirstLetterEachWordtoLower() {
		_value = convertFirstLetterEachWordtoLower(_value);
	}

	static string upperAllLettersWithString(string s1) {
		for (short i = 0; i < s1.size(); i++) {
			s1[i] = toupper(s1[i]);
		}

		return s1;
	}

	void upperAllLettersWithString() {
		_value = upperAllLettersWithString(_value);
	}

	static string lowerAllLettersWithString(string s1) {
		for (short i = 0; i < s1.size(); i++) {
			s1[i] = tolower(s1[i]);
		}

		return s1;
	}

	void lowerAllLettersWithString() {
		_value = lowerAllLettersWithString(_value);
	}

	static char invertedLetter(char character) {
		return isupper(character) ? tolower(character) : toupper(character);
	}

	static string invertedAllLetters(string& s1) {
		for (short i = 0; i < s1.size(); i++) {
			s1[i] = invertedLetter(s1[i]);
		}
		return s1;
	}

	string invertedAllLetters() {
		return invertedAllLetters(_value);
	}

	static short countLetters(string s1, eWhatToCount whatToCount = eWhatToCount::all) {
		if (whatToCount == eWhatToCount::all) {
			return s1.length();
		}

		int count = 0;

		for (short i = 0; i < s1.length(); i++) {
			if (whatToCount == eWhatToCount::SmallLetters && islower(s1[i])) {
				count++;
			}
			else if (whatToCount == eWhatToCount::CapitalLetters && isupper(s1[i])) {
				count++;
			}
		}
		return count;
	}

	short countLetters() {
		return countLetters(_value, all);
	}

	int countSmallLetters(string s1) {
		int count = 0;

		for (short i = 0; i < s1.length(); i++) {
			if (islower(s1[i])) {
				count++;
			}
		}
		return count;
	}

	int countSmallLetters() {
		return countSmallLetters(_value);
	}

	int countCapitalLetters(string s1) {
		int count = 0;

		for (short i = 0; i < s1.length(); i++) {
			if (isupper(s1[i])) {
				count++;
			}
		}
		return count;
	}

	int countCapitalLetters() {
		return countCapitalLetters(_value);
	}

	static int countSpecificLetter(string s1, char c1, bool matchCase = true) {
		short count = 0;

		for (short i = 0; i < s1.length(); i++) {
			if (matchCase) {
				if (s1[i] == c1) {
					count++;
				}
			}
			else {
				if (tolower(s1[i]) == tolower(c1)) {
					count++;
				}
			}
		}
		return count;
	}

	int countSpecificLetter(char c1, bool matchCase = true) {
		return countSpecificLetter(_value, c1, matchCase);
	}

	static bool checkIfVowelChar(char char1) {
		char1 = tolower(char1);

		return ((char1 == 'a' || char1 == 'e' || char1 == 'i' || char1 == 'o' || char1 == 'u'));
	}

	static int countVowel(string s1) {
		int count = 0;

		for (short i = 0; i < s1.length(); i++) {
			if (checkIfVowelChar(s1[i])) {
				count++;
			}
		}
		return count;
	}

	int countVowel() {
		return countVowel(_value);
	}

	static int countEachWordInString(string s1) {
		string delim = " ";
		short pos = 0;
		string sWord;
		short count = 0;

		while ((pos = s1.find(delim)) != string::npos) {
			sWord = s1.substr(0, pos);
			if (sWord != "") {
				count++;
			}
			s1.erase(0, pos + delim.length());
		}
		if (s1 != "") {
			count++;
		}
		return count;
	}

	int countEachWordInString() {
		return countEachWordInString(_value);
	}

	static vector <string> spiltString(string s1, string delim) {
		vector <string> vWords;

		short pos = 0;
		string sWord;

		while ((pos = s1.find(delim)) != string::npos) {
			sWord = s1.substr(0, pos);
			if (sWord != "") {
				vWords.push_back(sWord);
			}
			s1.erase(0, pos + delim.length());
		}
		if (s1 != "") {
			vWords.push_back(s1);
		}

		return vWords;
	};

	vector <string> spiltString(string delim) {
		return spiltString(_value, delim);
	}
};