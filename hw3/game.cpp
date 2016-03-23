#include "game.h"
using namespace std;


/*
Cuong Ngo, CS202, Asignment 3, 8/4/14
The main purpose of this assignment is to create a Tic-Tac-Toe games.
This game can be played with two players. In each game, the user can
store the games inside the heap data structure with the highest move priority.
When the game is finished, the game will be removed from the heap
*/

space::space():move(' ')	//constructor
{				//this will set the data member to an empty space
				//by default
}

space::space(char mv)	//qualify constructor
{
	move = mv;	//take an argument and copy the data member
}

space::space(const space & obj)	//copy constructor
{
	move = obj.move;	//copy the char from an class' object
}

space::~space()	//destructor
{

}

int space::display()	//this function will display an char of the space class
{
	if(move == '\0')	//check to see if it's null
		return 0;
	cout << move;	//print out the char
	return 1;
}

space & space::operator = (const char type)	//this operator set the data member to
{						// the argument
	if(move == type)	//check if it's already equal
		return *this;
	move = type;	//set it equal to
	return *this;
}

bool space::operator == (const char type)	//this operator check to see if its equal
{
	if(move == type)
		return true;	//return true if its equale
	return false;		//else false
}

bool space::operator != (const char type)	//this operator check to see if its not equal
{
	if(move != type)
		return true;	//return true if it's not
	return false;		//else false
}


board::board()	//constructor
{
	moves = 0;	//set move to 0
	for(int i = 0; i < 8; ++i)
		score[i] = 0;	//set the scores to 0
	mySpace = new space * [3];
	for(int i = 0; i < 3; ++i)	//create an empty board for the tic tac toe game
		mySpace[i] = new space[3];	
}

board::board(const board & obj)	//copy constructor
{
	moves = obj.moves;	//copy player's move
	for(int i = 0; i < 8; ++i)
		score[i] = obj.score[i];	//set the score to 0
	mySpace = new space * [3];	//allocate the space class object
	for(int i = 0; i < 3; ++i)
		mySpace[i] = new space[3];	//create an empty board with the space object

	for(int i = 0; i < 3; ++i)	//this will create a board of tic tac toe and copy the game from another board object
	{
		for(int j = 0; j < 3; ++j)
			mySpace[i][j] = obj.mySpace[i][j];
	}
}

board::~board()	//destructor
{
	for(int i = 0; i < 3; ++i)	//deallocate the space object of array pointer
		delete [] mySpace[i];
	delete [] mySpace;

}

int board::display()	//display the board tic-tac-toe 
{
        for(int j = 0; j < 3; ++j)
        {
                for(int i = 0; i < 3; ++i)
                {
                        mySpace[i][j].display();	//display the data memember of the space object
                        if(i < 2)
                                cout << " | ";	//create lines
                }
                if(j < 2)
                        cout << "\n--+---+---" << endl;	//create lines
        }
        cout << endl;
}

int board::get_move()	//this funcction will return the number of players' move
{
	return moves;
}

int board::insert(char type)	//this function will take a char argument and insert it into the board
{
        int location;
        int num;
        do
        {
                cout << "Where Do you Want to go? " << endl;
                cin >> location;	//get the integer location value
        }while(mySpace[location/3][location%3] != ' ');	//check if the location is open
        mySpace[location/3][location%3] = type;	//go to the location and set the argument data member
        if(type == 'X')	//this will keep track of which player's turn
                num = 1;
        else
                num = -1;
        if(location == 0)	//keep track of points
        {			//if player enter the location 0 then the array will get points
                score[0] += num;//by doing this, we can keep track who is the winner
                score[3] += num;//when the player reaches to 3
                score[6] += num;//then the player with the symbol 'X' will win the game
        }			//else if the point reaches to -3
        else if(location == 1)	//Then the player with the symbol 'O' will win the game
        {
                score[0] += num;
                score[4] += num;
        }
        else if(location == 2)	//everytime a player make a move, the point will be add either 1 or -1
        {			//depending on the player's turn
                score[0] += num;
                score[5] += num;
                score[7] += num;
        }

        else if(location == 3)
        {
                score[1] += num;
                score[3] += num;
        }

        else if(location == 4)
        {
                score[1] += num;
                score[4] += num;
                score[6] += num;
                score[7] += num;
        }

        else if(location == 5)
        {
                score[1] += num;
                score[5] += num;
        }
        else if(location == 6)
        {
                score[2] += num;
                score[3] += num;
                score[7] += num;
        }
        else if(location == 7)
        {
                score[2] += num;
                score[4] += num;
        }
        else if(location == 8)
        {
                score[2] += num;
                score[5] += num;
                score[6] += num;
        }
        ++moves;	//keep track of the move by incrementing one everytime player makes a move
}

bool board::checkwinner()	//keep track of the winner by checking player's point
{
        for(int i = 0; i < 8; ++i)
        {
                if(score[i] == 3)	//if player reaches to 3
                {
                        cout << "Player 1 Win!" << endl;	//player 1 with 'X' win
			set_move();
                        return true;
                }
                if(score[i] == -3)	//else player 2 win with -3 points
                {
                        cout << "Player 2 win!" << endl;
			set_move();
                        return true;
                }
        }
        return false;	//return false if no one win
}

bool board::checkdraw()	//check to see if its a draw
{
        if(moves == 9)	//if move = 9 then that's mean all of the spaces are taken
        {
                cout << "Its a Draw!" << endl;
		set_move();
                return true;	//return true if players draw
        }
        return false;
}

void board::set_move()	//this function will change the move of the game to -1
{
	moves = -1;
}
game::game():board()	//constructor
{
	playerTurn = 'O';	//this will be use to keep track of player's turn
}

game::game(const game & obj):board(obj)	//copy constructor
{
	playerTurn = obj.playerTurn;	//copy in the player's turn
}

game::~game()	//destructor
{

}

char game::get_turn()	//return the player turn char member
{
	return playerTurn;
}

void game::set_turn(char turn)	//set the player turn
{
	playerTurn = turn;

}







