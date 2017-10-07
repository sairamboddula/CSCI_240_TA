/***************************************************************
CSCI 240         Program 6     Spring 2017

Programmer: Sai Ram Boddula

Section: Section 1 & 2

Date Due: Friday, March 10 by 11:59PM

Purpose: This program performs simple arithmetic calculations and
         displays the results.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

int addition( int value1, int value2 )
{
	return value1 + value2;
}

int subtraction( int value1, int value2 )
{
	return value1 - value2;
}

int multiplication( int value1, int value2 )
{
	return value1 * value2;
}

int quotient( int value1, int value2 )
{
	if(value2 == 0)
	{
		cout << "\nERROR: The denominator cannot be zero" << endl;
	}
	else
	{
		return value1 / value2 ;
	}
}

int remainder( int value1, int value2 )
{
	if(value2 == 0)
	{
		cout << "\nERROR: The denominator cannot be zero" << endl;
	}
	else
	{
		return value1 % value2 ;
	}
}

int power( int value1, int value2 )
{
	if(value2 == 0)
		return 1;
	else
	{
		int result = 1;	
		
		for(int i = 1; i <= value2; i++)
			result *= value1;
		
		return result;
	}
}

int factorial( int value )
{
	if (value == 0 || value == 1)
		return 1;
		
	else
	{
		int result = 1;
		
		for (int i = 2; i <= value; i++)
			result *= i;
			
		return result;
	}
}

int main()
{

char operation; 
int num1, num2, result, remain;


//Display the menu to the user and get their first choice

cout << "What operation would you like to perform:" << endl
     << "  + addition\n  - subtraction\n  * multiplication\n  / division\n  ^ number to power\n  ! factorial"
     << "\n  q quit"
	 << endl << endl << "Operation? ";

cin >> operation;


//While the user does not want to quit

while( operation != 'q' and operation != 'Q' )
  {
  
  switch(operation)
  {
  	case '+': {
  		
  				//Get two numbers from the user
    			cout << endl << "What is the first number to add? ";
    			cin >> num1;

    			cout << endl << "What is the second number to add? ";
    			cin >> num2;
    
    			//Add the numbers together
    			result = addition(num1, num2);
    
    			//Display the result of the addition
    			cout << endl << num1 << " + " << num2 << " = " << result;
    
				break;
	  		}
	
	case '-': {
		
				//Get two numbers from the user
    			cout << endl << "What is the first number to subtract? ";
    			cin >> num1;

    			cout << endl << "What is the second number to subtract? ";
    			cin >> num2;
    
    			//Subtract the second number from the first number
    			result = subtraction(num1, num2);
    
    			//Display the result of the subtraction
    			cout << endl << num1 << " - " << num2 << " = " << result;
		
				break;
			}
			
	case '*': {
		
				//Get two numbers from the user
			    cout << endl << "What is the first number to multiply? ";
			    cin >> num1;
			
			    cout << endl << "What is the second number to multiply? ";
			    cin >> num2;
			    
			    //Multiply the numbers together
			    result = multiplication(num1, num2);
			    
			    //Display the result of the multiplication
			    cout << endl << num1 << " * " << num2 << " = " << result;
		
				break;
			}
			
	case '/': {
		
				//Get two numbers from the user
			    cout << endl << "What is the dividend? ";
			    cin >> num1;
			
			    cout << endl << "What is the divisor? ";
			    cin >> num2;
			    
			    //Divide the first number by the second number, calculating both the quotient
			    //and the remainder
			    result = quotient(num1, num2);
			    remain = remainder(num1, num2);
			
			    //Display both results of the division
			    cout << endl << num1 << " / " << num2 << " = " << result
				     << endl << num1 << " % " << num2 << " = " << remain;
				     
				break;
			}
			
	case '^': {
				//Get two numbers from the user. The first number is the base value. The second
			    //number is the power.
			    cout << endl << "What is the base number? ";
			    cin >> num1;
			
			    cout << endl << "What is the power? ";
			    cin >> num2;
			
			    //Calculate the result of raising the first number (num1) to a power (the
				//second number)    
				
				result = power(num1, num2);
				
				//Display the result
    			cout << endl << num1 << "^" << num2 << " = " << result;
    			
				break;
			}
			
	case '!': {
				//Get the number to use in the calculation from the user
			    cout << endl << "What is the number? ";
			    cin >> num1;
			
			    //Calculate the result of multiplying 1 times each value through the number
			    //entered by the user.
			    result = factorial(num1);
			    
			    //Display the result
			    cout << endl << num1 << "! = " << result;
			    
				break;
			}
	  		
	default: cout << endl << "That is an invalid operation!";
  }

  cout << endl;
  
  //Display the menu to the user and get their next operation choice
  cout << endl << "What operation would you like to perform:" << endl
       << "  + addition\n  - subtraction\n  * multiplication\n  / division\n  ^ number to power\n  ! factorial"
       << "\n  q quit"
	   << endl << endl << "Next Operation? ";
  cin >> operation;
  }

return 0;
}
