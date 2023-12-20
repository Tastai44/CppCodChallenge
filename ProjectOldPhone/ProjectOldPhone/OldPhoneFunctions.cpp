#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include "OldPhoneButton.h"

using namespace std;

// Function for get a list of numbers from user input.
string OldPhoneButton::getListOfNumber() {
    string numberArray;
    getline(cin, numberArray); // Read the entire line from 
    
    // check whether  input is end with # or not
    // returning a substring of the input excluding the '#' character if not.
    if (!numberArray.empty() && numberArray.back() != '#') {
        return "Invaiid input";
    }
    else {
        int  position = numberArray.find("#");
        return numberArray.substr(0, (position));
    }
}

// Function to display welcome messages.
void OldPhoneButton::welcomeWord() {
    cout << "Welcome to old phone..." << endl << "Type list of number: ";
}

// Function to convert numberic input to corresponding letters.
string OldPhoneButton::OldPhonePad(string input) {

    // Maping numberic to letter.
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
    return (letter != phonePad.end()) ? letter->second : ""; // Return the corresponding letter or an empty string if not found
}

// Function to delete a number from input base on the position before "*".
string OldPhoneButton::DeleteLetter(string input) {
    string tem;

    int  position = input.find("*");
    tem = input.erase(position - 1, 1);

    return tem.replace(position - 1, 1, " ");
}

// Function to breck number if there are empty space between input numbers
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

// Function to separate different numbers from each other by having " " between those number.
// For example, "112233" becomes "1 22 333"
string OldPhoneButton::CheckDuplicateNumber(string input) {
    string results;

    for (auto item = input.begin(); item != input.end(); item++) {

        // // Check if the current character is not the last one in the input string.
        if (item != input.end() - 1) { 

            // Check if the current character is different from the next one,
            // and also check if it's not equal to the previous character.
            if (*item != *next(item) &&
                (item == input.end() - 1 || *item != *prev(item))) 
            {
                results += *item;
                results += " ";
            }
            // check if the current character is the same as the next one.
            else if (*item == *next(item) &&
                (next(item) == input.end() - 1 || *next(item) != *next(next(item))))
            {
                results += *item;
                results += *next(item);
                results += " ";
                item = next(item);
            }
            // Similar logic for three consecutive equal characters.
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
            // Similar logic for four consecutive equal characters.
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
        // logic that use for handle the last character in the input string.
        else {
            // Check if the last character is different from the previous one.
            if (item == input.end() - 1 || *item != *prev(item))
            {
                results += *item;
            }
            // logic that use for handle other cases.
            else {
                results += input;
            }
        }
    }

    return results;
}

// Function to check if the input contains an asterisk (*)
bool OldPhoneButton::containsAsterisk(const string& input) {
    return input.find('*') != string::npos;
}

// Function to display letters correspoding to numberic input
string OldPhoneButton::DisplayLetter(string input) {
    string temLetter; // variable for store temporary data.
    string letterResults; // variable for store final result.

    if (containsAsterisk(input)) {
        temLetter = DeleteLetter(input);
    }
    else {
        temLetter = input;
    }

    // Performance Big O^2
    for (const auto& item : SeparateNumber(temLetter)) {
        for (const auto& letter : SeparateNumber(CheckDuplicateNumber(item))) {
            letterResults += OldPhonePad(letter);
        }
    }
    return letterResults;
}