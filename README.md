## Old phone keypad C++ Coding Challenge

Old phone keypad is use for typing letters by pressing a button multiple times will cycle through the letters on it allowing each button to represent more than one letter. 

## Built With

* C++
* Visual Studio

## Components and How it works

After you access the folder ProjectOldPhone, you will find a folders calls ProjectOldPhone. In the project, there are 8 funcions that I used for solving this challenge. The following is the order of how they work:
Main -> welcomeWord -> getListOfNumber -> DisplayLetter -> DeleteLetter (if the input contain *) -> SeparateNumber -> CheckDuplicateNumber -> OldPhonePad
* Main: This method is where the program begins its execution.
* Welcome: This method is designed to display a welcome message, prompting the user to type numbers.
* getListOfNumber: This method is designed to get input value from user.
* MapInput: This method is used to return characters based on the given input string, following certain conditions and rules inside the method.
* DeleteNumber: This method is used to delete the letter located before * For example, 227* -> 22.
* CheckLastNumber: it is the method that is used for returning characters when processing the last character of the input.
* OldPhonePad: it is the method that is used for mapping sequences of numbers to corresponding characters based on an old phone keypad layout and return those characters and the end.

However, in this project, I have separated all functions, with each one located in the file OldPhoneFunctions.cpp, except for the main function, which is situated in OldPhoneFunctions.cpp.

Additionally, I have created unit test cases for this program, encompassing all the functions. The purpose is to test whether all methods behave as expected or not.

## License

[IRON](https://ironsoftware.com/)

## Contact

Tastai Khianjai - tastthai.654@gmail.com
