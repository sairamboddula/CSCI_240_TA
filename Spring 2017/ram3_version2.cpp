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
	char subPackage;
	int callMinutes;
	const double monthlyCostA = 39.99 , monthlyCostB = 59.99, monthlyCostC = 69.99;
	const double extraCostA = 0.45, extraCostB = 0.4;
	const int freeMinsA = 450, freeMinsB = 900;
	
	cout << "Which package do you have (A, B, or C)? ";
	cin >> subPackage;
	
	cout << "How many minutes were used this month? ";
	cin >> callMinutes;
	
	cout << fixed << setprecision(2);
	
	cout << endl;
	
	if(subPackage == 'A')
	{
		if (callMinutes <= freeMinsA)
		{
			cout << "The bill is $" << monthlyCostA << endl;
		}
		else
		{
			int extraMinutes = callMinutes - freeMinsA;
			
			double extraCost = extraMinutes * extraCostA ;
			
			double totalBill = monthlyCostA + extraCost ;
			
			cout << "The bill is $" << (extraCost + monthlyCostA) << endl;
			
			if(totalBill > monthlyCostB)
			{
				cout << endl;
				
				cout << "Package B would have cost $" << monthlyCostB << " and saved you $" << (totalBill - monthlyCostB) << endl;
				cout << "Package C would have cost $" << monthlyCostC << " and saved you $" << (totalBill - monthlyCostC) << endl;
			}
		}
	}
	
	else if(subPackage == 'B')
	{
		if (callMinutes <= freeMinsB)
		{
			cout << "The bill is $" << monthlyCostB << endl;
			
			if(callMinutes <= freeMinsA)
			{
			    cout << endl;
			    
			    cout << "Package A would have cost $" << monthlyCostA << " and saved you $" << (monthlyCostB - monthlyCostA) << endl;
			}
		}
		else
		{
			int extraMinutes = callMinutes - freeMinsB;
			
			double extraCost = extraMinutes * extraCostB ;
			
			double totalBill = monthlyCostB + extraCost ;
			
			cout << "The bill is $" << (extraCost + monthlyCostB) << endl;
			
			if(totalBill > monthlyCostC)
			{
				cout << endl;
				
				cout << "Package C would have cost $" << monthlyCostC << " and saved you $" << (totalBill - monthlyCostC) << endl;
			}
		}
	}
	
	else
	{
	    cout << "The bill is $" << monthlyCostC << endl;
	    
	    if(callMinutes <= freeMinsA)
	    {
	        cout << endl;
	        
	        cout << "Package A would have cost $" << monthlyCostA << " and saved you $" << (monthlyCostC - monthlyCostA) << endl;
	        cout << "Package B would have cost $" << monthlyCostB << " and saved you $" << (monthlyCostC - monthlyCostB) << endl;
	    }
	    else if(callMinutes > freeMinsA && callMinutes <= freeMinsB)
	    {
	        cout << endl;
	        
	        cout << "Package B would have cost $" << monthlyCostB << " and saved you $" << (monthlyCostC - monthlyCostB) << endl;
	    }
	}
	
	return 0;
}