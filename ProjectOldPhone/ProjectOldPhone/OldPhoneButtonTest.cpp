#include "OldPhoneButtonTest.h"


void OldPhoneButtonTest::IsEqual(string expectResult, string result) {

    if (expectResult == result) {
        cout << "Expect is equal result";
    }
    else {
        cout << "Expect is not equal result";
    }
}

void OldPhoneButtonTest::OldPhonePadTest() {
    string input;
    string expectResult;
    string result;
    OldPhoneButton oldPhone;

    cout << "Testing OldPhonePad" << endl << "Input your test value: ";
    cin >> input;
    cout << "Type expect result: ";
    cin >> expectResult;
    result += oldPhone.OldPhonePad(input);
    IsEqual(expectResult, result);
    cout << endl << endl;
}

void OldPhoneButtonTest::DeleteLetterTest() {
    string input;
    string expectResult;
    string result;
    OldPhoneButton oldPhone;

    cout << "Testing DeleteLetter" << endl << "Input your test value: ";
    cin >> input;
    cout << "Type expect result: ";
    cin >> expectResult;
    result += oldPhone.DeleteLetter(input);
    expectResult += " "; // it was added a space bar because the function return with a space bar at the end.
    IsEqual(expectResult, result);
    cout << endl << endl;
}

void OldPhoneButtonTest::CheckDuplicateNumberTest() {
    string input;
    string expectResult;
    string result;
    OldPhoneButton oldPhone;

    cout << "Testing CheckDuplicateNumber" << endl << "Input your test value: ";
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Type expect result: ";
    getline(cin, expectResult);
    result += oldPhone.CheckDuplicateNumber(input);
    expectResult += " "; // it was added a space bar because the function return with a space bar at the end.
    IsEqual(expectResult, result);
    cout << endl << endl;
}

void OldPhoneButtonTest::containsAsteriskTest() {
    OldPhoneButton oldPhone;
    cout << "Testing containsAsterisk" << endl;
    if (oldPhone.containsAsterisk("11*") == true) {
        cout << "Test containsAsterisk case pass.";
    }
}

void OldPhoneButtonTest::DisplayLetterTest() {
    string input;
    string expectResult;
    string result;
    OldPhoneButton oldPhone;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Testing DisplayLetter" << endl << "Input your test value: ";
    getline(cin, input);

    cout << "Type expect result: ";
    cin >> expectResult;
    result += oldPhone.DisplayLetter(input);
    IsEqual(expectResult, result);
}

void OldPhoneButtonTest::SeparateNumberTest() {
    OldPhoneButton oldPhone;
    string input;
    string expectResult;
    string result;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Testing SeparateNumber" << endl;
    cout << "Assume user input: 123 456 789" << endl;

    auto result1 = oldPhone.SeparateNumber("123 456 789");

    if (result1 == vector<string>{"123", "456", "789"}) {
        cout << "Expect is equal result";
    }
    else {
        cout << "Expect is not equal result";
    }
}