#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include "OldPhoneButton.h"

using namespace std;

string OldPhoneButton::getListOfNumber() {
    string numberArray;
    getline(cin, numberArray); // Read the entire line from 
    if (!numberArray.empty() && numberArray.back() != '#') {
        return "Invaiid input";
    }
    else {
        int  position = numberArray.find("#");
        return numberArray.substr(0, (position));
    }
}

void OldPhoneButton::welcomeWord() {
    cout << "Welcome to old phone..." << endl << "Type list of number: ";
}

string OldPhoneButton::OldPhonePad(string input) {
    const unordered_map<string, string> phonePad = {
        {"1", "&"}, {"11", "'"}, {"111", "("},
        {"2", "A"}, {"22", "B"}, {"222", "C"},
        {"3", "D"}, {"33", "E"}, {"333", "F"},
        {"4", "G"}, {"44", "H"}, {"444", "I"},
        {"5", "J"}, {"55", "K"}, {"555", "L"},
        {"6", "M"}, {"66", "N"}, {"666", "O"},
        {"7", "P"}, {"77", "Q"}, {"777", "R"}, {"7777", "S"},
        {"8", "T"}, {"88", "U"}, {"888", "V"},
        {"9", "W"}, {"99", "X"}, {"999", "Y"}, {"9999", "Z"}
    };

    auto letter = phonePad.find(input);
    return (letter != phonePad.end()) ? letter->second : "";
}

string OldPhoneButton::DeleteLetter(string input) {
    string tem;

    int  position = input.find("*");
    tem = input.erase(position - 1, 1);

    return tem.replace(position - 1, 1, " ");
}

// breck number if there are empty space between input numbers
vector<string> OldPhoneButton::SeparateNumber(string input) {
    vector<string> result;
    string tem;

    for (const auto& numbers : input) {

        if (numbers == ' ') {
            result.push_back(tem);
            tem.clear();
        }
        else {
            tem += numbers;
        }
    }
    if (!tem.empty()) {
        result.push_back(tem);
    }

    return result;
}

string OldPhoneButton::CheckDuplicateNumber(string input) {
    string results;

    for (auto item = input.begin(); item != input.end(); item++) {

        if (item != input.end() - 1) {

            if (*item != *next(item) &&
                (item == input.end() - 1 || *item != *prev(item)))
            {
                results += *item;
                results += " ";
            }
            else if (*item == *next(item) &&
                (next(item) == input.end() - 1 || *next(item) != *next(next(item))))
            {
                results += *item;
                results += *next(item);
                results += " ";
                item = next(item);
            }
            else if (*item == *next(item) &&
                *next(item) == *next(next(item)) &&
                (next(next(item)) == input.end() - 1 || *next(next(item)) != *next(next(next(item)))))
            {
                results += *item;
                results += *next(item);
                results += *next(next(item));
                results += " ";
                item = next(next(item));
            }
            else if (*item == *next(item) &&
                *next(item) == *next(next(item)) &&
                *next(next(item)) == *next(next(next(item))) &&
                (next(next(next(item))) == input.end() - 1 || *next(next(next(item))) != *next(next(next(next(item))))))
            {
                results += *item;
                results += *next(item);
                results += *next(next(item));
                results += *next(next(next(item)));
                results += " ";
                item = next(next(next(item)));
            }
        }
        else {
            if (item == input.end() - 1 || *item != *prev(item))
            {
                results += *item;
            }
            else {
                results += input;
            }
        }
    }

    return results;
}

bool OldPhoneButton::containsAsterisk(const string& input) {
    return input.find('*') != string::npos;
}

string OldPhoneButton::DisplayLetter(string input) {
    string temLetter;
    string letterResults;
    if (containsAsterisk(input)) {
        temLetter = DeleteLetter(input);
    }
    else {
        temLetter = input;
    }

    // Big O^2
    for (const auto& item : SeparateNumber(temLetter)) {
        for (const auto& letter : SeparateNumber(CheckDuplicateNumber(item))) {
            letterResults += OldPhonePad(letter);
        }
    }
    return letterResults;
}