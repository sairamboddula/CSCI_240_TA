/***************************************************************
CSCI 240         Program 9     Spring 2017

Programmer: Sai Ram Boddula

Section: Section 1 & 2

Date Due: Friday, April 21 by 11:59 PM

Purpose: This program implements and uses the methods of a class called 'Player'.
***************************************************************/
//Header files used in the program
#include <iostream>
#include <iomanip>
#include <cstring>				//for strcpy()

using namespace std;

/**********   The 'Player' class definition   **********/

class Player
{
public:
  Player();
  Player( const char [], int, int, int );
    
  void printPlayer();

  void setName( const char [] );
  void setNumber( int );
  
  void changeGoals( int );
  void changeAssists( int );

  int getNumber();
  int getGoals();
  int getAssists();

private:
  char name[50];
  int number;
  int goals;
  int assists;
};

/*********************************************************/

//main() starts here
int main()
{
	//Creating six player objects with the requirements in the program description
	Player playerOne = Player("Ram Boddula", 66, 1, 1);
	Player playerTwo = Player();
	Player playerThree = Player("Jonathan Toews", 19, 20, 35);
	Player playerFour = Player("Patrick Kane", 88, 33, 48);
	Player playerFive = Player("Artemi Panarin", 72, 24, 42);
	Player playerSix = Player("Ryan Hartman", 38, 18, 11);
	
	//printing the player one's information
	cout << "The first player object" << endl;
	playerOne.printPlayer();
	
	cout << endl << endl;							//for readabilty
	
	//printing the player two's information
	cout << "The second player object" << endl;
	playerTwo.printPlayer();
	
	playerTwo.setName("Duncan Keith");				//setting the player's name
	playerTwo.setNumber(2);							//setting the player's number
	playerTwo.changeGoals(6);						//assigning the player's goals scored
	playerTwo.changeAssists(44);					//assigning the player's assists earned
	
	cout << endl ;									//for readabilty
	
	playerTwo.printPlayer();						//printing the player information after updating
	
	cout << endl << endl;							//for readabilty
	
	//printing the player three's information
	cout << "The third player object" << endl;
	playerThree.printPlayer();
	
	cout << endl;									//for readabilty
	
	playerThree.changeGoals(-8);					//setting the goals to a negative number as a test case
	playerThree.changeAssists(-2);					//setting the assists to a negative number as a test case
	
	cout << endl;									//for readabilty
	
	playerThree.printPlayer();						//printing the player information after updating
	
	cout << endl << endl;							//for readabilty
	
	//printing the player four's information
	cout << "The fourth player object" << endl;
	playerFour.printPlayer();
	playerFour.changeAssists(4);
	
	cout << endl;									//for readabilty
	
	playerFour.printPlayer();						//printing the player information after updating
	
	cout << endl << endl;							//for readabilty
	
	//printing the player five's information
	cout << "The fifth player object" << endl << endl;
	
	//printing only the player number and the player's goals scored
	cout << "Player number " << playerFive.getNumber() << " has scored " << playerFive.getGoals() << " goals" << endl << endl;
	
	playerFive.printPlayer();						//printing the player information
	
	cout << endl << endl;							//for readabilty
	
	//printing the player six's information
	cout << "The sixth player object" << endl << endl;
	
	//printing only the player number and the player's assists earned
	cout << "Player number " << playerSix.getNumber() << " has earned " << playerSix.getAssists() << " assists" << endl << endl;
	
	playerSix.printPlayer();						//printing the player information after updating
	
	return 0;
	
} // end of main()

/************   All the method definitions starts here   ************/

///////////////////////////// Constructors ///////////////////////////

/***************************************************************
Constructor name: Player()

Type of constructor: default

Use: sets the player's name to null and other integer data members to zero.

Arguments: none
***************************************************************/
Player::Player()
{
	name[0] = '\0';							//assigning the name with a null character
	number = 0;								//assigning the rest of the data members to zero
	goals = 0;
	assists = 0;
}

/***************************************************************
Constructor name: Player(const char playerName[], int playerNumber, int playerGoals, int playerAssists)

Type of constructor: parameterised

Use: sets the player's data members to the information provided in the parameters

Arguments: player's name, player's number, player's goals scored and player's assists earned
***************************************************************/
Player::Player(const char playerName[], int playerNumber, int playerGoals, int playerAssists)
{
	setName(playerName);						//using the setters to assign the data members with the passed arguments
	setNumber(playerNumber);
	goals = playerGoals;
	assists = playerAssists;
}

////////////////////////// Member Functions ////////////////////////////

/***************************************************************
Function: printPlayer()

Use: displays the player's name & number including the goals, assists and points

Arguments: None

Returns: Nothing

Note: The points are calculated by adding the number of goals and number of assists
***************************************************************/
void Player::printPlayer()
{
	int points = goals + assists;					//calculating the points by adding goals and assists
	
	cout << name << "\t#" << number << endl;		//printing the name and the number
	
	//printing the stats
	cout << "Goals:\t" << goals << "  Assists:\t" << assists << "  Points:\t" << points << endl;
}

/***************************************************************
Function: setName(const char playerName[])

Use: sets the player's name with the character array/string passed in the arguments

Arguments: Player's name (character array/string)

Returns: Nothing

Note: using strcpy to copy the character array/string to the character string
***************************************************************/
void Player::setName(const char playerName[])
{
	strcpy(name, playerName);				//using strcpy to copy the name
}

/***************************************************************
Function: setNumber(int newNumber)

Use: sets the player's number with the integer passed in the arguments

Arguments: Player's number (integer)

Returns: Nothing
***************************************************************/
void Player::setNumber(int newNumber)
{
	number = newNumber;						//assigning the number data member with the passed argument
}

/***************************************************************
Function: changeGoals(int goalsScored)

Use: updates the player's goals with the integer passed in the arguments by 
		adding them to the current number of goals

Arguments: Number of goals scored (integer)

Returns: Nothing

Note: It checks if the passed argument is negative. If a negative number of
		goals are passed, the goals remain unchanged. Else, it updates the 
		number of goals by adding the passed argument.
***************************************************************/
void Player::changeGoals(int goalsScored)
{
	if(goalsScored < 0)					//checking if the passed argument is negative, if negative, display an error
	{
		cout << "Error in changeGoals. The # of goals scored cannot be negative" << endl;
	}
	else								//else add the new goals to the current goals
	{
		goals += goalsScored;
	}
}

/***************************************************************
Function: changeAssists(int assistsEarned)

Use: updates the player's assists with the integer passed in the arguments by 
		adding them to the current number of assists

Arguments: Number of assists earned (integer)

Returns: Nothing

Note: It checks if the passed argument is negative. If a negative number of
		assists are passed, the assists remain unchanged. Else, it updates the 
		number of assists by adding the passed argument.
***************************************************************/
void Player::changeAssists(int assistsEarned)
{
	if(assistsEarned < 0)				//checking if the passed argument is negative, if negative, display an error
	{
		cout << "Error in changeAssists. The # of assists earned cannot be negative" << endl;
	}
	else								//else add the new assists to the current assists
	{
		assists += assistsEarned;
	}
}

/***************************************************************
Function: getNumber()

Use: Returns the number of the player

Arguments: None

Returns: Number of the player
***************************************************************/
int Player::getNumber()
{
	return number;						//returns the player's number
}

/***************************************************************
Function: getGoals()

Use: Returns the number of goals scored by the player

Arguments: None

Returns: Goals scored by the player
***************************************************************/
int Player::getGoals()
{
	return goals;						//returns the player's goals scored
}

/***************************************************************
Function: getAssists()

Use: Returns the number of assists earned by the player

Arguments: None

Returns: Assists earned by the player
***************************************************************/
int Player::getAssists()
{
	return assists;						//returns the player's assists earned
}
