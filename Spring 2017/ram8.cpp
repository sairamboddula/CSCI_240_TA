/***************************************************************
CSCI 240         Program 8     Spring 2017

Programmer: Sai Ram Boddula

Section: Section 1 & 2

Date Due: Friday, April 7 by 11:59 PM

Purpose: This program implements the methods of a class called
			'Card' (simulation of a playing card).
***************************************************************/
//Header files used in the program
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <sstream>							//for ostringstream and string

using namespace std;

//Numeric constants used in the program
const int MIN_FACE_VAL = 1;					//constant to hold the minimum value assigned to the face value
const int MAX_FACE_VAL = 13;				//constant to hold the maximum value assigned to the face value
const int MIN_SUIT_VAL = 1;					//constant to hold the minimum value assigned to the suit
const int MAX_SUIT_VAL = 4;					//constant to hold the maximum value assigned to the suit
const int DEF_FACE_VAL = 1;					//constant to hold the default value assigned to the face value if no valid face value is specified
const char DEF_SUIT_CHAR = 'H';				//constant to hold the default character assigned to the suit if no valid suit is specified

/**********   Put the Card class definition between these lines   **********/

class Card
{
	public:
  		Card();						//default constructor
  
  		void setCard( int, char );	//setter for the data members
  
  		int getFace();				//getter for the data member 'faceValue'
  		char getSuit();				//getter for the data member 'suit'
  
  		void displayCard();			//member function to display the card

	private:
		
  		int faceValue;				//data member to store the face value of the card
  		char suit;					//data member to store the suit of the card
};

/***************************************************************************/

int main()
{
//Set the seed value for the random number generator
srand(240);

//Test 1: Constructor and displayCard method

//Create 5 Card objects

Card firstCard;
Card secondCard;
Card thirdCard;
Card fourthCard;
Card fifthCard;

//Display the 5 objects

cout << "Test 1: Constructor and displayCard method" << endl << endl
     << "  The first card should be the 4 of Diamonds. It is the ";
firstCard.displayCard();

cout << "." << endl << endl << "  The second card should be the 3 of Clubs. It is the ";
secondCard.displayCard();

cout << "." << endl << endl << "  The third card should be the King of Clubs. It is the ";
thirdCard.displayCard();

cout << "." << endl << endl << "  The fourth card should be the King of Spades. It is the ";
fourthCard.displayCard();

cout << "." << endl << endl << "  The fifth card should be the Jack of Clubs. It is the ";
fifthCard.displayCard();


//Test 2: setCard method on four of the objects


cout << "." << endl << endl << "Test 2: setCard method" << endl << endl;

//Change the first card to the 9 of Clubs

firstCard.setCard( 9, 'C' );

cout << "  The first card should be the 9 of Clubs. It is now the ";
firstCard.displayCard();

//Change the second card with invalid value for the face

secondCard.setCard( 15, 'D' );

cout << "." << endl << endl << "  The second card should be the Ace of Diamonds. It is now the ";
secondCard.displayCard();

//Change the third card with invalid value for the suit

thirdCard.setCard( 7, 'G' );

cout << "." << endl << endl << "  The third card should be the 7 of Hearts. It is now the ";
thirdCard.displayCard();

//Change the fourth card with invalid value for both the face and the suit

fourthCard.setCard( -5, 'R' );

cout << "." << endl << endl << "  The fourth card should be the Ace of Hearts. It is now the ";
fourthCard.displayCard();


//Test 3: getFace and getSuit methods on the fourth and fifth objects

cout << "." << endl << endl << "Test 3: getFace and getSuit methods" << endl << endl;

cout << "  The fourth card should have a face value of 1. It is "
     << fourthCard.getFace() << "." << endl
     << "  The suit value should be H. It is " << fourthCard.getSuit() << ".";

cout << endl << endl << "  The fifth card should have a face value of 11. It is "
     << fifthCard.getFace() << "." << endl
     << "  The suit value should be C. It is " << fifthCard.getSuit() << endl;

return 0;
}

/************   Code the Card class methods AFTER this line   ************/

///////////////////////////// Default constructor ///////////////////////////

/***************************************************************
Constructor name: Card()

Type of constructor: default

Use: sets a random number to both data members

Arguments: none
***************************************************************/

Card::Card()
{
	int randFace, randSuit;			//variables to store the random values for face value and the suit
	char randSuitChar;				//variable to store the character to set for the suit of the card
	
	//generating a random number between 1 and 13 to assign for the face value 
	randFace = MIN_FACE_VAL + (rand() % (MAX_FACE_VAL - MIN_FACE_VAL + 1));
	
	//generating a random number between 1 and 4 to assign for the suit
	randSuit = MIN_SUIT_VAL + (rand() % (MAX_SUIT_VAL - MIN_SUIT_VAL + 1));
	
	switch(randSuit)
	{
		case 1: randSuitChar = 'C';			//if the randomly generated number is 1, assign 'C' as the suit for the card
				break;
				
		case 2: randSuitChar = 'D';			//if the randomly generated number is 2, assign 'D' as the suit for the card
				break;
				
		case 3: randSuitChar = 'H';			//if the randomly generated number is 3, assign 'H' as the suit for the card
				break;
				
		case 4: randSuitChar = 'S';			//if the randomly generated number is 4, assign 'S' as the suit for the card
				break;
	}
	
	setCard(randFace, randSuitChar);		//sets the card with the randomly generated face value and randomly generated suit
}

////////////////////////// Member Functions ////////////////////////////

/***************************************************************
Function: setCard(int newFace, char newSuit);

Use: sets the face value and suit to the card object

Arguments: an integer(face value to be set) and char (the suit to be set) 

Returns: Nothing

Note: It check for valid values. If valid values are not provided, 
		it sets the default values for both the data members
***************************************************************/
void Card::setCard(int newFace, char newSuit)
{
	if(newFace < MIN_FACE_VAL || newFace > MAX_FACE_VAL)	//if the face value is not in the valid range, assign the default face value
	{
		faceValue = DEF_FACE_VAL;	
	}
	else
	{
		faceValue = newFace;								//else assign the specified face value
	}
	
	//if the suit is a valid character, assign the default suit
	if(newSuit != 'C' && newSuit != 'D' && newSuit != 'H' && newSuit != 'S' )
	{
		suit = DEF_SUIT_CHAR;
	}
	else													//else assign the specified suit
	{
		suit = newSuit;	
	}
}

/***************************************************************
Function: getFace();

Use: Returns the face value of the card object

Arguments: none

Returns: An integer which is the face value of the card.
***************************************************************/
int Card::getFace()
{
	return faceValue;										//return the face value of the card
}

/***************************************************************
Function: getSuit();

Use: Returns the suit of the card object

Arguments: none

Returns: A character which is the suit of the card.
***************************************************************/
char Card::getSuit()
{
	return suit;											//return the suit of the card
}

/***************************************************************
Function: displayCard();

Use: Displays the card in the specified format

Arguments: none

Returns: Nothing.
***************************************************************/
void Card::displayCard()
{
	string faceStr, suitStr;								//variables to store the string equivalents of the data members
	ostringstream oss;										// an output string stream object to convert an integer to string
	
	switch(faceValue)
	{
		case 1: faceStr = "Ace";							//if the face value is 1, assign Ace as the string
				break;
				
		case 11: faceStr = "Jack";							//if the face value is 11, assign Jack as the string
				break;
		
		case 12: faceStr = "Queen";							//if the face value is 12, assign Queen as the string
				break;
				
		case 13: faceStr = "King";							//if the face value is 13, assign King as the string
				break;
				
		default: oss << faceValue;							//for everthing other name, just convert them to a string and assign them
				faceStr = oss.str();
	}
	
	switch(suit)
	{
		case 'C': suitStr = "Clubs";						//if the suit is 'C', assign Clubs as the string version of the suit
				break;
		
		case 'D': suitStr = "Diamonds";						//if the suit is 'D', assign Diamonds as the string version of the suit
				break;
				
		case 'H': suitStr = "Hearts";						//if the suit is 'H', assign Hearts as the string version of the suit
				break;
		
		case 'S': suitStr = "Spades";						//if the suit is 'S', assign Spades as the string version of the suit
				break;
	}
	
	cout << faceStr << " of " << suitStr;					//output the joined string
}
