#include <iostream>
#include "OldPhoneButton.h"


using namespace std;


int main()
{
    string listNumber;
    OldPhoneButton oldPhone;
    oldPhone.welcomeWord();
    listNumber = oldPhone.getListOfNumber();
    if (listNumber == "Invaiid input") {
        cout << listNumber;
    }
    else {
        cout << oldPhone.DisplayLetter(listNumber);
    }

    cout << endl;
    return 0;
}