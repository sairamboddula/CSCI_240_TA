/*************************************************************************************
CSCI 240                  Program 2                  Spring 2017

Programmer: Sai Ram Boddula

Section: CSCI 240 - 1 & 2

Date Due: Friday, February 3 11:59 PM

Purpose: This program acts as a recommended tip calculator.
*************************************************************************************/

//Header files for the program
#include <iostream>
#include <iomanip>

using namespace std;

///////// main() starts here ///////////////
int main()
{
	double billAmount;			//variable to store the bill amount
	
	cout << "What is the amount of the bill?: ";	//prompt the user to enter the bill amount
	cin >> billAmount;								//get the input from the user through keyboard
	
	cout << fixed << setprecision(2) ;				//setting the precision of the decimal to 2
	
	cout << endl;									//for readability
	
	/////// The output starts here ///////////
	
	cout << "The recommended tip amounts are:" << endl;
	cout << "10% = $" << (billAmount * 10) / 100.0 << endl;		//displaying 10% tip amount of the bill
	cout << "15% = $" << (billAmount * 15) / 100.0 << endl;		//displaying 15% tip amount of the bill
	cout << "20% = $" << (billAmount * 20) / 100.0 << endl;		//displaying 20% tip amount of the bill
	cout << "25% = $" << (billAmount * 25) / 100.0 << endl;		//displaying 25% tip amount of the bill
	
	cout << endl << endl;							//for readability
	
	////////////// EXTRA CREDIT ////////////////
	
	cout << "The total bill with the recommended tips:" << endl;
	cout << "10% = $" << billAmount + ((billAmount * 10) / 100.0) << endl;	//displaying the total bill including the 10% tip
	cout << "15% = $" << billAmount + ((billAmount * 15) / 100.0) << endl;	//displaying the total bill including the 15% tip
	cout << "20% = $" << billAmount + ((billAmount * 20) / 100.0) << endl;	//displaying the total bill including the 20% tip
	cout << "25% = $" << billAmount + ((billAmount * 25) / 100.0) << endl;	//displaying the total bill including the 25% tip
	
	return 0;
}
