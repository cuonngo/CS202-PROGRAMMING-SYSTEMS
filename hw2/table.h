#include "downstack.h"


/*
Cuong Ngo, CS202, Asignment 2, 7/20/14
The main purpose of this program is to create a game called "War". This program can only
support multiple players up to 54. Preferly to play with 4 players.
The deck of 54 cards will divide evenly. If there are left over, the winner
of the first round will get those cards.
This is the second phrase of the programs where most of the rules
have been created in this program.
*/

class table: public list	//create a table class which is a list class
{
	public:
		table();	//constructure
		table(const table & obj);	//copy constructure
		~table();	//destructure
		void insert_played_card(int value, char type);	//insert played card into the array of linear linked list
	protected:
};

class played	//create a played class which has a table class
{
	public:
		played(int size);	//create 2 array with dynamic linear linked list
		played(const played & obj);	//copy constructure
		~played();	//destructure
		int game(hand & obj, deck & obj2);	//start the game
		void remove_played(int player, hand & obj);	//insert to winner
		void remove_to_deck(deck & obj);	//remove the deck
		int check_two(hand & obj, deck & obj2);	//check if there are 2
		int compare(int tie[], hand & obj, deck & obj2);	//compare cards
		int war(int index, hand & obj, deck & obj2);	//start automatic war
		int highest();	//find highest
		int one(int index, hand & obj);	//draw one card
	private:
		table ** played_card;	//array of pointers
		int table_size;	//set the table size
};
