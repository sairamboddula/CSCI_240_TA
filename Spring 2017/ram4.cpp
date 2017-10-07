/*************************************************************************************
CSCI 240                  Program 4                  Spring 2017

Programmer: Sai Ram Boddula

Section: CSCI 240 - 1 & 2

Date Due: Friday, February 17 11:59 PM

Purpose: This program calculates a set of statistics for a small group of random numbers.
*************************************************************************************/

//Header files for the program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

///////// main() starts here ///////////////
int main()
{
					///////// Symbolic Constants ////////////
	const int MIN_GRP_SZ = 2;			//Symbolic constant for minimum group size
	const int MAX_GRP_SZ = 10;			//Symbolic constant for maximum group size
	const int MIN_VAL = 10;				//Symbolic constant for minimum value to be generated
	const int MAX_VAL = 50;				//Symbolic constant for maximum value to be generated
	
						///////// Variables ////////////				
	char choice;						//variable to hold the choice of the rerun
	int totalNumOfElements = 0,			//variable to hold the total number of elements in all the runs.
		smallestOfAllRuns = MAX_VAL,	//variable to hold the smallest element of the all the runs
		largestOfAllRuns = MIN_VAL,		//variable to hold the largeest element of the all the runs
		sumOfAllRuns = 0,				//variable to hold the sum of the elements of the all the runs
		sumOfSquaresOfAllRuns = 0;		//variable to hold the sum of the squares of all elements in all runs
	double avgOfAllRuns,				//variable to hold the average of all the elements in all the runs
		stdDevOfAllRuns;				//variable to hold the standard deviation of all the elements in all the runs.
	
	srand(0);							//Initialising the random number generator with seed '0'
	
	do
	{
		int numOfVals;					//variable to hold the number of values generated in the current run.
		int smallestNum = MAX_VAL,		//variable to hold the smallest element of the current run
			largestNum = MIN_VAL,		//variable to hold the largest element of the current run
			sum = 0,					//variable to hold the sum of the elements generated in the current run
			sumOfSquares = 0;			//variable to hold the sum of the squares of the elements generated in the current run
		double avg = 0.0,				//variable to hold the average of the elements generated in the current run
				stdDev = 0.0;			//variable to hold the standard deviation of the elements generated in the current run
				
		if (choice == 'Y' || choice =='y')
		{
			cout << endl << endl;				//ading extra space between each run for readability
		}
		
		//generating a random number between the size 2 and 10
		numOfVals = MIN_GRP_SZ + (rand() % (MAX_GRP_SZ - MIN_GRP_SZ + 1));
		
		//Displaying the number of elements generated in the current run
		cout << "\nThe program will generate " << numOfVals << " numbers." << endl;
		cout << "\nThe numbers are";
		
		//Loop starts
		for(int i = 0; i < numOfVals; i++)
		{
			int randNum;				//variable to hold the current random number in the group
			
			//generating a random number between the size 10 and 50
			randNum = MIN_VAL + (rand() % (MAX_VAL - MIN_VAL + 1));
		
			cout << "   " << randNum << "   ";		//displaying the random number that is generated
			
			sum += randNum;							//updating the sum by adding the current generated random number
			
			sumOfSquares += randNum * randNum;		//updating the sum of the squares by adding the square of the current random number
			
			if(randNum < smallestNum)				//checking if the current number is less than the smallest number
				smallestNum = randNum;				//if yes, update the smallest number
			
			if(randNum > largestNum)				//checking if the current number is greater than the smallest number
				largestNum = randNum;				//if yes, update the largest number
		}
		
		//calculating the average and standard deviations of all the elements generated in the current run
		avg = (double)sum / numOfVals;
		stdDev = sqrt( (sumOfSquares - ((sum * sum) / (double)numOfVals)) / (numOfVals - 1) );
		
		cout << fixed << setprecision(3) << endl;	//setting the precision of the decimals to 3 and also adding a new line for readability
	
		//////////// Printing the stats of the current run ///////////////
		cout << "  Smallest: " << setw(21) << right <<  smallestNum << endl;
		cout << "  Largest: " << setw(22) << right <<  largestNum << endl;
		cout << "  Sum: " << setw(26) << right <<  sum << endl;
		cout << "  Average: " << setw(22) << right <<  avg << endl;
		cout << "  Standard Deviation: " << setw(11) << right <<  stdDev << endl;
		
		//Prompting the user to enter the choice of a re-run
		cout << "\nWould you like to process another set of numbers ('Y/y' for yes)? ";
		cin >> choice;								//getting the input from the user through standard input
		
		totalNumOfElements += numOfVals; 			//updating the total number of elements in all runs
		sumOfAllRuns += sum ;						//updating the sum of the elements in all runs
		sumOfSquaresOfAllRuns += sumOfSquares;		//updating the sum of the squares of elements in all runs
		
		if(smallestNum < smallestOfAllRuns)			//checking if the current smallest number is less than the smallest number till the previous run
			smallestOfAllRuns = smallestNum;		//if yes, update the smallest number of all runs.
		
		if(largestNum > largestOfAllRuns)			//checking if the current largeest number is greater than the largest number till the previous run
			largestOfAllRuns = largestNum;			//if yes, update the largest number of all runs.
				
	}while (choice == 'Y' || choice == 'y');		//using a do while loop to run at least once and rest of the runs depending on the user's choice
	
	cout << endl << endl;							//adding two lines for readablilty
	
	//calculating the average and standard deviation of all the elements generated in all the runs
	avgOfAllRuns = (double)sumOfAllRuns / totalNumOfElements;
	stdDevOfAllRuns = sqrt( (sumOfSquaresOfAllRuns - (sumOfAllRuns * sumOfAllRuns / (double)totalNumOfElements)) / (totalNumOfElements - 1) );

	//////////// Printing the final stats of all the runs ///////////////
	cout << "\nFinal Results:" << endl;
	cout << "  Smallest: " << setw(21) << right <<  smallestOfAllRuns << endl;
	cout << "  Largest: " << setw(22) << right <<  largestOfAllRuns << endl;
	cout << "  Sum: " << setw(26) << right <<  sumOfAllRuns << endl;
	cout << "  Average: " << setw(22) << right <<  avgOfAllRuns << endl;
	cout << "  Standard Deviation: " << setw(11) << right <<  stdDevOfAllRuns << endl;
	
	return(0);
}
