/***************************************************************
CSCI 240         Program 7     Spring 2017

Programmer: Sai Ram Boddula

Section: Section 1 & 2

Date Due: Friday, March 24 by 11:59PM

Purpose: This program will process a data set of random numeric information.
***************************************************************/
//Header files for the program
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

//Numeric constants used in the program
#define LOWER_BND 0.0						//constant to hold the lower bound of the random number generation
#define UPPER_BND 100.0						//constant to hold the upper bound of the random number generation
#define MAX_VALUES 100						//constant to hold the maximum number of values the array can hold
#define MIN_VALUES 20						//constant to hold the minimum number of values the array can hold
#define MAX_PER_LINE 7						//constant to hold the maximum number of values to output per line

//Function prototypes
double randDouble();						
int buildArray(double[]);
void printArray(double[], int);
void sortArray(double[], int);
double average(double[], int);
double standardDeviation(double[], int);
void swap(double, double);

//////////////////// main() starts here /////////////////////
int main()
{	
	int numberOfVals;						//variable to hold the size of the double array
	double doubleArray[MAX_VALUES];			//a double array to process the double values
	
	srand(0);								//initialsing the random number generator with the seed value
	
	numberOfVals = buildArray(doubleArray);		//building the array with random floating numbers and storing it's size
	
	cout << "Number of values: " << numberOfVals << endl;		//printing the size of the array
	
	cout << "\nUnsorted Numbers" << endl;						//printing the unsorted array
	printArray(doubleArray, numberOfVals);
	
	sortArray(doubleArray, numberOfVals);						//sorting the array (selection sort)
	
	cout << endl << endl;										//for readability
	
	cout << "\nSorted Numbers" << endl;							//printing the sorted array
	printArray(doubleArray, numberOfVals);
	
	cout << fixed << setprecision (4) << endl << endl;			//setting the precision to 4 digits
	
	//Stats are printed here
	cout << "Smallest Value:" << right << setw(15) << doubleArray[0] << endl;
	cout << "Largest Value:" << right << setw(16) << doubleArray[numberOfVals - 1] << endl;
	cout << "Average:" << right << setw(22) << average(doubleArray, numberOfVals) << endl;
	cout << "Standard Deviation:" << right << setw(11) << standardDeviation(doubleArray, numberOfVals) << endl;
	
	return 0;
}
/***************************************************************
Function: randDouble();

Use: Generates a random floating number

Arguments: none

Returns: A random floating number within the range
***************************************************************/
double randDouble()
{
	double randNum;					//variable to hold the random floating number
	
	//generating a random floating number within the range of lower bound and upper bound
	randNum = LOWER_BND + ( (double) rand() / (double) (RAND_MAX / (UPPER_BND - LOWER_BND)));
	
	return randNum;					//returns the random floating number
}
/***************************************************************
Function: buildArray(double doubleArr[]);

Use: Builds an array with random floating number values

Arguments: a double array

Returns: Size of the array
***************************************************************/
int buildArray(double doubleArr[])
{
	int numOfVals;					//variable to store the size of the array
	
	//generating a random size for the array
	numOfVals = MIN_VALUES + (rand() % (MAX_VALUES - MIN_VALUES + 1));
	
	//loop to fill the array with random floating numbers of the size
	for (int i = 0 ; i < numOfVals ; i++)
		doubleArr[i] = randDouble();

	return numOfVals;				//return the size of the array
}
/***************************************************************
Function: printArray(double doubleArr[], int numOfVals);

Use: Printing an array

Arguments: an array and the size of the array

Returns: Nothing.

Note: It prints the values of the array not exceeding 7 values per line
***************************************************************/
void printArray(double doubleArr[], int numOfVals)
{
	int cnt;			//count variable to store the number of values outputted per line
	
	cout << fixed << setprecision(4);		//setting the precision to 4
	
	//Loop to print the values not exceeding seven values per line
	for (int i = 0; i < numOfVals; i++)
	{
		cout << right << setw(9) << doubleArr[i] << ' ';
		cnt++;
		
		//condition to see the values doesn't exceed seven per line
		if(cnt == MAX_PER_LINE)
		{
			cout << endl;
			cnt = 0;
		}
	}
}
/***************************************************************
Function: sortArray(double doubleArr[], int numOfVals);

Use: Sorting an array in ascending order

Arguments: an array and the size of the array

Returns: Nothing.

Note: It sorts the using the sorting technique of selection sort.
***************************************************************/
void sortArray(double doubleArr[], int numOfVals)
{
	double temp;							//a temp double variable for swapping
	
	//using selection sort technique
	for(int i = 0; i < numOfVals; i++)
	{
		for(int j = i + 1; j < numOfVals; j++)
		{
			if(doubleArr[j] < doubleArr[i])
			{
				temp = doubleArr[i];
				doubleArr[i] = doubleArr[j];
				doubleArr[j] = temp;
			}
				
		}
	}
}
/***************************************************************
Function: average(double doubleArr[], int numOfVals);

Use: Gives the average of the values in an array

Arguments: an array and the size of the array

Returns: Average of the values in an array
***************************************************************/
double average(double doubleArr[], int numOfVals)
{
	double sum = 0, avg;
	
	//Loop to get the sum of all the values in the array
	for (int i = 0; i < numOfVals; i++)
	{
		sum += doubleArr[i];
	}
	
	//Calculating the average of the values
	avg = sum / (double) numOfVals;
	
	return avg;				//returns the average of the values
}
/***************************************************************
Function: standardDeviation(double doubleArr[], int numOfVals);

Use: Gives the standard deviation of the values in an array

Arguments: an array and the size of the array

Returns: Returns the standard deviation of the values in the array
***************************************************************/
double standardDeviation(double doubleArr[], int numOfVals)
{
	double sum = 0.0, sumOfSqrs = 0.0, stdev;
	
	//Loop to calculate the sum and sum of squares of the values in the array
	for(int i = 0; i < numOfVals; i++)
	{
		sum += doubleArr[i];
		sumOfSqrs += doubleArr[i] * doubleArr[i];
	}
	
	//Calculating the standard deviation of the values in the array
	stdev = sqrt( (sumOfSqrs - ( (sum * sum) / (double) numOfVals) ) / (double) (numOfVals - 1) );
	
	return stdev;			//return the standard deviation
}
