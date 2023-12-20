#pragma once

#include <iostream>
#include "OldPhoneButton.h"
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class OldPhoneButtonTest
{
public :
	void IsEqual(string expectResult, string result);

	void OldPhonePadTest();
	void DeleteLetterTest();
	void CheckDuplicateNumberTest();
	void containsAsteriskTest();
	void DisplayLetterTest();
	void SeparateNumberTest();
};

