#include <iostream>
#include <cstring>
#include <cctype>

/*
Cuong Ngo, CS202, Asignment 3, 8/4/14
The main purpose of this assignment is to create a Tic-Tac-Toe games. 
This game can be played with two players. In each game, the user can
store the games inside the heap data structure with the highest move priority.
When the game is finished, the game will be removed from the heap
*/


class space //this class represent each space inside the tic-tac-toe table
{
	public:
		space();	//constructor
		space(char mv);	//qualify constructor
		space(const space & obj);	//copy constructor
		~space();	//destructor

		int display();	//display either 'X', 'O', or ' '
		space & operator = (const char type);	//operator for storing the 
		bool operator == (const char type);	//space object inside the
		bool operator != (const char type);	//table. Also use the '==' 
	protected:					//and '!=' to check for the winner
		char move;	//hold the symbol
};

class board	//this class' job is to create a table and insert the space object
{
	public:
		board();	//constructor
		board(const board & obj);	//copy constructor
		~board();	//destructor

		int display();	//display the whole tic-tac-toe
		int insert(char type);	//insert the space data member
		bool checkwinner();	//check to see who win
		bool checkdraw();	//check to see if there's a draw
		int get_move();		//get the players' move
		void set_move();	//set the players' move
	protected:
		int moves;	//keep track of players' move
		int score[8];	//keep track of score to see who win
		space ** mySpace;	//create an matrix table for tic-tac-toe
};


class game: public board	//this class' job is to manage the game
{
	public:
		game();	//constructor
		game(const game & obj);	//copy constructor
		~game();	//destructor
		char get_turn();	//return the symbol of player
		void set_turn(char turn);	//set turn
	protected:
		char playerTurn;	//keep track of the player's turn
};


