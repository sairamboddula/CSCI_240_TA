/*************************************************************************************
CSCI 240                  Program 3                  Spring 2017

Programmer: Sai Ram Boddula

Section: CSCI 240 - 1 & 2

Date Due: Friday, February 10 11:59 PM

Purpose: This program calculates a single customer's cell phone monthly bill.
*************************************************************************************/

//Header files for the program
#include <iostream>
#include <iomanip>

using namespace std;

///////// main() starts here ///////////////
int main()
{
	//////////             Constants              //////////////
	const double monthlyCostA = 39.99 , monthlyCostB = 59.99, monthlyCostC = 69.99;			//Monthly costs of the subscription packages
	const double extraCostA = 0.45, extraCostB = 0.4;										//Extra cost per minute for each subscription package
	const int freeMinsA = 450, freeMinsB = 900;												//Avaiable free minutes for each subscription package
	
	char subPackage;										//character variable to store which package the customer chose
	int callMinutes;										//integer variable to store the call minutes used in the current month
	
	// Prompting the user to enter the subscription package and getting the input
	cout << "Which package do you have (A, B, or C)? ";
	cin >> subPackage;
	
	// Prompting the user to enter the minutes used in a month and getting the input
	cout << "How many minutes were used this month? ";
	cin >> callMinutes;
	
	cout << fixed << setprecision(2);								//setting the precision of the decimal to 2
	
	cout << endl;													//for readability
	
	if(subPackage == 'A' || subPackage == 'a')						//if the customer is enrolled in the subscription package 'A'
	{
		if (callMinutes <= freeMinsA)								//if the customer used less minutes than the available free minutes
		{
			cout << "The bill is $" << monthlyCostA << endl;		//print the bill accordingly
		}
		
		else														//if the customer used more minutes than the available free minutes
		{
			int extraMinutes = callMinutes - freeMinsA;				//calculate the extra minutes used than the available free minutes
			
			double extraCost = extraMinutes * extraCostA ;			//calculate the extra cost for the extra minutes used
			
			double totalBill = monthlyCostA + extraCost ;			//calculate the total bill including the extra cost
			
			cout << "The bill is $" << (extraCost + monthlyCostA) << endl;		//print the bill accordingly
			
			if(totalBill > monthlyCostB)							//if the customer has spent too much on his current subscription package
			{
				cout << endl;
				
				//Print the following recommendations that would have saved his pockets by choosing other available options
				cout << "Package B would have cost $" << monthlyCostB << " and saved you $" << (totalBill - monthlyCostB) << endl;
				cout << "Package C would have cost $" << monthlyCostC << " and saved you $" << (totalBill - monthlyCostC) << endl;
			}
		}
	}
	
	else if(subPackage == 'B' || subPackage == 'b')										//if the customer is enrolled in the subscription package 'B'
	{
		if (callMinutes <= freeMinsB)								//if the customer used less minutes than the available free minutes
		{
			cout << "The bill is $" << monthlyCostB << endl;		//print the bill accordingly
		}
		else														//if the customer used more minutes than the available free minutes
		{
			int extraMinutes = callMinutes - freeMinsB;				//calculate the extra minutes used than the available free minutes
			
			double extraCost = extraMinutes * extraCostB ;			//calculate the extra cost for the extra minutes used
			
			double totalBill = monthlyCostB + extraCost ;			//calculate the total bill including the extra cost
			
			cout << "The bill is $" << (extraCost + monthlyCostB) << endl;	//print the bill accordingly
			
			if(totalBill > monthlyCostC)							//if the customer has spent too much on his current subscription package
			{
				cout << endl;
				
				//Print the following recommendations that would have saved his pockets by choosing other available options
				cout << "Package C would have cost $" << monthlyCostC << " and saved you $" << (totalBill - monthlyCostC) << endl;
			}
		}
	}
	
	else if(subPackage == 'C' || subPackage == 'c')					//if the customer is enrolled in the subscription package 'C'
	{
		//This subscription package has infinite call minutes so the customers would be charged just the monthly cost of the package
		cout << "The bill is $" << monthlyCostC << endl;
	}
	
	return 0;
}
