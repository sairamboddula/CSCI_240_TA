/*************************************************************************************
CSCI 240                  Program 1                  Spring 2017

Programmer: Sai Ram Boddula

Section: CSCI 240 - 1 & 2

Date Due: Friday, January 27 11:59 PM

Purpose: This program performs simple arithmetic calculations and displays the results
*************************************************************************************/

//Header files for the program
#include <iostream>
#include <iomanip>

using namespace std;

///////// main() starts here ///////////////
int main()
{
    int firstNumber, secondNumber;          //variables to store the two integers
    
    cout << "Enter the first number: ";     //prompt to enter the first number
    cin >> firstNumber;                     //get the first number from the user through keyboard
    cout << "Enter the second number: ";    //prompt to enter the second number
    cin >> secondNumber;                    //get the second number from the user through keyboard
    
    cout << endl;                   //for readability
    
    /////// The output starts here ///////////
    
    //Displaying the sum of the two integers
    cout << firstNumber << " + " << secondNumber << " = " << (firstNumber + secondNumber) << endl;
    
    //Displaying the difference of the two integers
    cout << firstNumber << " - " << secondNumber << " = " << (firstNumber - secondNumber) << endl;
    
    //Displaying the product of the two integers
    cout << firstNumber << " * " << secondNumber << " = " << (firstNumber * secondNumber) << endl;
    
    //Displaying the result of the integer division
    cout << firstNumber << " / " << secondNumber << " = " << (firstNumber / secondNumber) << endl;
    
    //Displaying the result of the modulus operation
    cout << firstNumber << " % " << secondNumber << " = " << (firstNumber % secondNumber) << endl;
	
	cout << endl;                   //for readability
	
	////////////// EXTRA CREDIT ////////////////
    
    cout << secondNumber << " - " << firstNumber << " = " << (secondNumber - firstNumber) << endl;
    cout << secondNumber << " / " << firstNumber << " = " << (secondNumber / firstNumber) << endl;
    cout << secondNumber << " % " << firstNumber << " = " << (secondNumber % firstNumber) << endl;
	
    return 0;
}
