/*************************************************************************************
CSCI 240                  Program 5                  Spring 2017

Programmer: Sai Ram Boddula

Section: CSCI 240 - 1 & 2

Date Due: Friday, March 3 11:59 PM

Purpose: This program will simulate a game of Roulette.
*************************************************************************************/

//Header files for this program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

///////// main() starts here ///////////////
int main()
{
	const int MIN_GRP_SZ = 0, MAX_GRP_SZ = 36;		//constants for maximum and minimum group sizes
	const int MIN_BET = 5;							//constant to hold the minimum bet
	const int ODDS_SINGLE = 35;						//constant to hold the odds for the bet
	const int ODDS_OTHERS = 1;
	
	char bettingOption, choiceOfRerun;				//variables to store the betting option and choice of a re-run
	int bettingNumber, wagerAmount;					//variables to store the bettingNumber and the wagerAmount
	
	srand(1);										//initialising the random number generator with seed '1'
	
	//using a do while loop to let the game run atleast once and later checks the user to confirm a re-run
	do
	{
		//if it's a re-run, add space for more readablity
		if(choiceOfRerun == 'Y' || choiceOfRerun == 'y')
		{
			cout << endl << endl;	
		}
		
		//Prompting the user to enter the type of the bet
		cout << "\nWhat type of the bet would you like" << endl << "\t(S = Single number, R = Red, B = Black, E = Even, O = Odd)? ";
		cin >> bettingOption;
		
		//Validating the input to be one of the valid options, if not the user will be asked to re-enter the option
		while (bettingOption != 'S' && bettingOption != 'R' && bettingOption != 'B' && bettingOption != 'E' && bettingOption != 'O' &&
				bettingOption != 's' && bettingOption != 'r' && bettingOption != 'b' && bettingOption != 'e' && bettingOption != 'o')
		{
			cout << "\nInvalid choice! Please re-enter your choice (S, R, B, E, O): ";
			cin >> bettingOption;
		}
		
		//Prompting the user to enter the wager amount
		cout << "\nHow much would you like to wager ($5 minimum bet)? ";
		cin >> wagerAmount;
		
		//Validating the bet amount to be greater than or equal to $5 
		while (wagerAmount < 5)
		{
			cout << "You cannot wager less than $5. Please re-enter your bet: ";
			cin >> wagerAmount;
		}
		
		//if the user chose 'Single'
		if(bettingOption == 'S' || bettingOption == 's')
		{
			//Prompt the user to enter a number that he would like to bet on
			cout << "\nWhat number would you like bet on (0 - 36)? ";
			cin >> bettingNumber;
			
			//Validating the number should be within the range
			while(bettingNumber < 0 && bettingNumber > 36)
			{
				cout << "\nInvalid number! Please re-enter the number you would like bet on (0 - 36): ";
				cin >> bettingNumber;
			}
			
			//generate a random number simulating a spin
			int pocketNumber = MIN_GRP_SZ + (rand() % (MAX_GRP_SZ - MIN_GRP_SZ + 1));
			
			//Prints out the random number
			cout << "\nThe wheel is spinning....and landed on " << pocketNumber << endl;
			
			//if the number the user chose and the ball pocketed is the same number, the user wins the bet
			if(bettingNumber == pocketNumber)
				cout << "\nYou won $" << wagerAmount + (wagerAmount * ODDS_SINGLE) << "!" << endl;
			//else the user loses the bet
			else
				cout << "\nYou lost!" << endl;
		}
		
		//If the user chose the 'Red' option
		else if(bettingOption == 'R' || bettingOption == 'r')
		{
			//generate a random number simulating a spin
			int pocketNumber = MIN_GRP_SZ + (rand() % (MAX_GRP_SZ - MIN_GRP_SZ + 1));
			
			//If the balls lands on 0, then its green and the user loses the bet
			if(pocketNumber == 0)
			{
				cout << "\nThe wheel is spinning....and landed on GREEN (" << pocketNumber << ")" << endl;
				cout << "\nYou lost!" << endl;	
			}
			
			//if the users pockets any number that is red he wins the bet, else he loses the bet
			else if((pocketNumber >= 1 && pocketNumber <= 10) || (pocketNumber >= 19 && pocketNumber <=28))
			{
				if(pocketNumber % 2 == 0)
				{
					cout << "\nThe wheel is spinning....and landed on BLACK (" << pocketNumber << ")" << endl;
					cout << "\nYou lost!" << endl;
				}
				else
				{
					cout << "\nThe wheel is spinning....and landed on RED (" << pocketNumber << ")" << endl;
					cout << "\nYou won $" << wagerAmount + (wagerAmount * ODDS_OTHERS) << "!" << endl;
				}
			}
			
			else if((pocketNumber >= 11 && pocketNumber <= 18) || (pocketNumber >= 29 && pocketNumber <=36))
			{
				if(pocketNumber % 2 == 1)
				{
					cout << "\nThe wheel is spinning....and landed on BLACK (" << pocketNumber << ")" << endl;
					cout << "\nYou lose!" << endl;
				}
				else
				{
					cout << "\nThe wheel is spinning....and landed on RED (" << pocketNumber << ")" << endl;
					cout << "\nYou won!" << endl;
				}
			}
		}
		
		//if the user chose 'Black'
		else if(bettingOption == 'B' || bettingOption == 'b')
		{
			//generate a random number simulating a spin
			int pocketNumber = MIN_GRP_SZ + (rand() % (MAX_GRP_SZ - MIN_GRP_SZ + 1));
			
			//If the balls lands on 0, then its green and the user loses the bet
			if(pocketNumber == 0)
			{
				cout << "\nThe wheel is spinning....and landed on GREEN (" << pocketNumber << ")" << endl;
				cout << "\nYou lose!" << endl;	
			}
			
			//if the users pockets any number that is red he wins the bet, else he loses the bet
			else if((pocketNumber >= 1 && pocketNumber <= 10) || (pocketNumber >= 19 && pocketNumber <=28))
			{
				if(pocketNumber % 2 == 0)
				{
					cout << "\nThe wheel is spinning....and landed on BLACK (" << pocketNumber << ")" << endl;
					cout << "\nYou won $" << wagerAmount + (wagerAmount * ODDS_OTHERS) << "!" << endl;
				}
				else
				{
					cout << "\nThe wheel is spinning....and landed on RED (" << pocketNumber << ")" << endl;
					cout << "\nYou lose!" << endl;
				}
			}
			
			else if((pocketNumber >= 11 && pocketNumber <= 18) || (pocketNumber >= 29 && pocketNumber <=36))
			{
				if(pocketNumber % 2 == 1)
				{
					cout << "\nThe wheel is spinning....and landed on BLACK (" << pocketNumber << ")" << endl;
					cout << "\nYou won $" << wagerAmount + (wagerAmount * ODDS_OTHERS) << "!" << endl;
				}
				else
				{
					cout << "\nThe wheel is spinning....and landed on RED (" << pocketNumber << ")" << endl;
					cout << "\nYou lose!" << endl;
				}
			}
		}
		
		//if the user chose 'Even'
		else if(bettingOption == 'E' || bettingOption == 'e')
		{
			//generate a random number simulating a spin
			int pocketNumber = MIN_GRP_SZ + (rand() % (MAX_GRP_SZ - MIN_GRP_SZ + 1));
			
			//if the ball lands on 00 or 0, the user will lose the bet
			if(pocketNumber == 0)
			{
				cout << "\nThe wheel is spinning....and landed on 00" << endl;
				cout << "\nYou lose!" << endl;
			}
			//if the ball lands on an even number, the user will win the bet
			else if(pocketNumber % 2 == 0)
			{
				cout << "\nThe wheel is spinning....and landed on EVEN (" << pocketNumber << ")" << endl;
				cout << "\nYou won $" << wagerAmount + (wagerAmount * ODDS_OTHERS) << "!" << endl;
			}
			//if the ball lands on an odd number, the user will lose the bet
			else
			{
				cout << "\nThe wheel is spinning....and landed on ODD (" << pocketNumber << ")" << endl;
				cout << "\nYou lose!" << endl;
			}
		}
		
		else if(bettingOption == 'O' || bettingOption == 'o')
		{
			//generate a random number simulating a spin
			int pocketNumber = MIN_GRP_SZ + (rand() % (MAX_GRP_SZ - MIN_GRP_SZ + 1));
			
			//if the ball lands on 00 or 0, the user will lose the bet
			if(pocketNumber == 0)
			{
				cout << "\nThe wheel is spinning....and landed on 00" << endl;
				cout << "\nYou lose!" << endl;
			}
			//if the ball lands on an odd number, the user will win the bet
			else if(pocketNumber % 2 == 1)
			{
				cout << "\nThe wheel is spinning....and landed on ODD (" << pocketNumber << ")" << endl;
				cout << "\nYou won $" << wagerAmount + (wagerAmount * ODDS_OTHERS) << "!" << endl;
			}
			//if the ball lands on an even number, the user will lose the bet
			else
			{
				cout << "\nThe wheel is spinning....and landed on EVEN (" << pocketNumber << ")" << endl;
				cout << "\nYou lose!" << endl;
			}
		}
		
		//Prompting the user for a re-run
		cout << "\nWould you like to play again (Y for yes)? ";
		cin >> choiceOfRerun;
		
	} while(choiceOfRerun == 'Y' || choiceOfRerun == 'y');	//if the user enters Y/y, let the user to play another game
		
	return 0;
}
