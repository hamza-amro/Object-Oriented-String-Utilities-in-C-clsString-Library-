#include <iostream>
#include <vector>
#include "clsString.h"
using namespace std;

int main(){
    clsString string1;

    string1.setValue("Hamza amro");
    cout << string1.value() << endl;

    string1.printFirstLetterEachWord();

    string1.convertFirstLetterEachWordtoUppar();
    string1.convertFirstLetterEachWordtoLower();

    string1.upperAllLettersWithString();
    string1.lowerAllLettersWithString();

    cout << string1.invertedAllLetters() << endl;

    cout << "Count letters: " << string1.countLetters() << endl;
    cout << "Count Small letters: " << string1.countSmallLetters() << endl;
    cout << "Count Capital letters: " << string1.countCapitalLetters() << endl;

    cout << "Count Specific letter: " << string1.countSpecificLetter('a', false) << endl;
    cout << "Count Vowel letters: " << string1.countVowel() << endl;

    cout << "Count Words In String: " << string1.countEachWordInString() << endl;

    clsString string2;
    string2.setValue("I-Love-Programming");

    vector <string> vStr = string2.spiltString("-");

    for (string word : vStr) {
        cout << word << endl;
    }
}

