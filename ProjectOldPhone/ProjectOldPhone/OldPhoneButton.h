#pragma once

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class OldPhoneButton {
public:
	string getListOfNumber();
	void welcomeWord();
	string OldPhonePad(string input);
	string DeleteLetter(string input);
	vector<string> SeparateNumber(string input);
	string CheckDuplicateNumber(string input);
	bool containsAsterisk(const string& input);
	string DisplayLetter(string input);
};