/***************************************************************
CSCI 240         Program 10     Spring 2017

Programmer: Sai Ram Boddula

Section: Section 1 & 2

Date Due: Thursday, May 4 by 11:59 PM

Purpose: This program is a modified/simplified version of the 
			game 'Twenty-One'. (Black Jack)
***************************************************************/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <sstream>					//for ostringstream and string
#include <cstring>					//for strcpy

using namespace std;

//Numeric constants used in the program
const int MIN_FACE_VAL = 1;					//constant to hold the minimum value assigned to the face value
const int MAX_FACE_VAL = 13;				//constant to hold the maximum value assigned to the face value
const int MIN_SUIT_VAL = 1;					//constant to hold the minimum value assigned to the suit
const int MAX_SUIT_VAL = 4;					//constant to hold the maximum value assigned to the suit
const int DEF_FACE_VAL = 1;					//constant to hold the default value assigned to the face value if no valid face value is specified
const char DEF_SUIT_CHAR = 'H';				//constant to hold the default character assigned to the suit if no valid suit is specified
const int noOfPlayers = 2;					//constant to hold the number of players playing the game
const int winningNumber = 21;				//constant to hold the winning number of the game
const int cardsAllowedToDraw = 3;			//constant to hold the number of cards the players are allowed to draw during a game
const int playerOne = 1;					//constant to hold the player one's number
const int playerTwo = 2;					//constant to hold the player two's number
const int sumToAddifAceCard = 11;			//constant to hold the sum to be added to sum of cards if an Ace card is drawn
const int sumToAddifFaceCard = 10;			//constant to hold the sum to be added to sum of cards if a face card(Jack, Queen & King) is drawn
const int faceValueOfAceCard = 1;			//constant to hold the face value of the Ace card
const int faceValueOfTopNumberCard = 10;	//constant to hold the face value of the top number card's face value which is 10
const int pointsWonIfTwentyOne = 15;		//constant to hold the points won if the players get a Black Jack
const int pointsWonIfInside	= 10;			//constant to hold the points won if the players stays inside twenty one

/**********   Put the Card class definition between these lines   **********/

class Card
{
public:
  Card();
  
  void setCard( int, char );
  
  int getFace();
  char getSuit();
  
  void displayCard();

private:
  int faceValue;
  char suit;
};

/***************************************************************************/


//Definition for a class that represents a deck of cards

class DeckOfCards
{
public:
  DeckOfCards();

  Card draw();
  void shuffle();
  bool isEmpty();

private:
  static const int MAX_CARDS = 52;       //Maximum number of cards in a deck
  static const int NUM_SUITS = 4;        //Number of card suits
  static const int CARDS_PER_SUIT = 13;  //Number of cards of each suit

  Card deck[MAX_CARDS];     //The deck of cards
  int topCard;              //The subscript of the card on the top of the deck

};


int main()
{
	//variables to store player one's score, player two's score, sum of the cards drawn and the player number
	int playerOneScore = 0, playerTwoScore = 0, sumOfCards, playerNumber = 1;	
	
	//character arrays to store names of the two player and the current player
	char playerOneName[20], playerTwoName[20], currentPlayerName[20];
	
	srand(0);											//seeding the srand with seed value '0'
	
	DeckOfCards deck;									//creating an object for deck of cards
	
	Card cardDrawn;										//creating an object to store the drawn card
	
	cout << "Player 1, what is your name? ";			//Prompt to ask for the player one name
	cin >> playerOneName;								//get the player one name and store it
	
	cout << "Player 2, what is your name? ";			//Prompt to ask for the player two name
	cin >> playerTwoName;								//get the player two name and store it
	
	cout << endl << endl;								//for readability
	
	while(!deck.isEmpty())								//loop to run until the deck is not empty
	{
		sumOfCards = 0;									//initialise the sum of cards to zero
		
		int numberOfCardsDrawn = 0;						//a counter to keep track of the number of cards drawn
		
		if(playerNumber % noOfPlayers == playerOne)						//checking if player one is playing the game
		{
			strcpy(currentPlayerName, playerOneName);					//make the current player's name as player one's name
		}
		else 															
		{
			strcpy(currentPlayerName, playerTwoName);					//else make the current player's name as player two's name
		}
		
		cout << currentPlayerName << ":" << endl;						//Print the current player's name
		
		//see if the number of cards doesn't exceed the max limit and sum of cards is less the twenty one
		while(numberOfCardsDrawn != cardsAllowedToDraw && sumOfCards < winningNumber)
		{
			cardDrawn = deck.draw();									//draw a card from the deck
			
			numberOfCardsDrawn++;										//increment the counter by one
			
			cardDrawn.displayCard();									//display the drawn card
			
			if(cardDrawn.getFace() == faceValueOfAceCard)				//if an ace card is drawn
			{
				sumOfCards += sumToAddifAceCard;						//add 11 to the sum of the cards
			}
			else if(cardDrawn.getFace() > faceValueOfTopNumberCard)		//if a face card is drawn
			{
				sumOfCards += sumToAddifFaceCard;						//add 10 to the sum of the cards
			}
			else
				sumOfCards += cardDrawn.getFace();						//for all the number cards, add the face value of the number card to the sum of cards
					
			cout <<"\t\t"<< setw(9) << left << "Total: " << sumOfCards << endl;		//print out the sum of cards as total
		}
			
		if(sumOfCards == winningNumber)									//if the total is 21(Black Jack)
		{
			//print a congratulatory message
			cout << "\nCongratulations " << currentPlayerName << "! You've won 15 points!" << endl;
			
			//if the current player is player one, add the points to player one's score
			if(playerNumber % noOfPlayers == playerOne)
				playerOneScore += pointsWonIfTwentyOne;
				
			//else add the points to player two's score
			else
				playerTwoScore += pointsWonIfTwentyOne;
		}
		else if(sumOfCards < winningNumber)								//else if, the total is inside 21
		{
			//print a congratulatory message
			cout << "\nCongratulations "<< currentPlayerName << "! You've won 10 points!" << endl;
			
			//if the current player is player one, add the points to player one's score
			if(playerNumber % noOfPlayers == playerOne)
				playerOneScore += pointsWonIfInside;
				
			//else add the points to player two's score
			else
				playerTwoScore += pointsWonIfInside;
		}
		else															//else, if the total exceeds 21													
		{
			//print a message saying that the player is busted
			cout << "\nSorry "<< currentPlayerName << " -- you're busted!" << endl;
		}
		
		cout << "--------------------------------" << endl << endl;
		
		playerNumber++;													//toggle the player
	}
	
	cout << endl << endl;												//for readability
	
	cout << playerOneName << "'s Score: " << playerOneScore << endl;		//print out the player one's score
	
	cout << playerTwoName << "'s Score: " << playerTwoScore << endl;		//print out the player two's score
	
	cout << endl << endl;												//for reability
	
	if(playerOneScore > playerTwoScore)									//if the player one's score is greater than the player two's score
	{
		cout << playerOneName << " won!" << endl;						//print out that the player one has won
	}
	else if(playerOneScore == playerTwoScore)
	{
		cout << "It's a draw" << endl;									//if it's a draw, print that it's a draw
	}
	else
	{
		cout << playerTwoName << " won!" << endl;						//else, print out that the player one has won
	}

	return 0;
}


/**********   Code the Card class methods between these lines   **********/

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
	
	cout << right << setw(5) << faceStr << setw(4) << " of " << left << setw(8) << suitStr;					//output the joined string
}

/*************************************************************************/



/***************************************************************
Constructor

Use: This creates a DeckOfCards object and then shuffles the
     cards

Arguments: none

Note: -1 is used to signal that no cards have been removed from
      the deck
***************************************************************/

DeckOfCards::DeckOfCards()
{
//An array of the 4 possible values for the card suit
char suitVals[NUM_SUITS] = { 'C', 'D', 'H', 'S' };

int cardSub = 0;    //subscript to process the deck of cards

//Go through all 52 spots in the array of Cards and put a card
//at the location

for( int suitSub = 0; suitSub < NUM_SUITS; suitSub++ )
  {
  //For each of the suits, put in all of the cards for the suit
  for( int faceVal = 1; faceVal <= CARDS_PER_SUIT; faceVal++ )
    {
    //Put the card into the deck
    deck[ cardSub ].setCard( faceVal, suitVals[suitSub] );

    //Move to the next card in the deck
    cardSub++;
    }
  }

//shuffle the playing cards
shuffle();

//Set the top card location to -1 to indicate the deck is brand new
topCard = -1;
}



/***************************************************************
Method:  Card draw()

Use: This method draws a card from the top of the deck

Arguments: none

Returns: a Card object (the card on the top of the deck)
***************************************************************/

Card DeckOfCards::draw()
{
//Increment to get the subscript of the current top card
topCard++;

//return the card that is currently on the top of the deck
return deck[topCard];
}



/***************************************************************
Method:  void shuffle()

Use: This method shuffles the deck of cards

Arguments: none

Returns: nothing

Note: this method uses the random_shuffle function that is part
      of the algorithm library to shuffle the 52 cards
***************************************************************/

void DeckOfCards::shuffle()
{
//Shuffle all 52 cards that are in the deck

random_shuffle(deck, deck+MAX_CARDS);
}


/***************************************************************
Method:  bool isEmpty()

Use: This method determines if the deck of cards is empty( have
     all of the cards been drawn)

Arguments: none

Returns: boolean value: true if all of the cards have been drawn
                        false if there are still cards in the deck
***************************************************************/

bool DeckOfCards::isEmpty()
{
return topCard + 1 >= MAX_CARDS;
}

