#include <iostream>
#include "OldPhoneButton.h"
#include "OldPhoneButtonTest.h"
#include <string>
#include <vector>
#include <cassert>

using namespace std;


int main()
{
    string listNumber;
    OldPhoneButton oldPhone;
    OldPhoneButtonTest oldPhoneTest;
    string askForTest;
    oldPhone.welcomeWord();
    listNumber = oldPhone.getListOfNumber();
    if (listNumber == "Invaiid input") {
        cout << listNumber;
    }
    else {
        cout << oldPhone.DisplayLetter(listNumber) << endl << endl;
    }

    //Unit test sections
    cout << "Do you want to run unit test?" << endl << "Please type Yes or No" << endl;
    cin >> askForTest;
    if (askForTest == "Yes" || askForTest == "yes") {
        oldPhoneTest.OldPhonePadTest();
        oldPhoneTest.DeleteLetterTest();
        oldPhoneTest.CheckDuplicateNumberTest();
        oldPhoneTest.containsAsteriskTest();
        oldPhoneTest.DisplayLetterTest();
        oldPhoneTest.SeparateNumberTest();
    }
    else {
        cout << "Thank you, see you.";
    }

    cout << endl;
    return 0;
}