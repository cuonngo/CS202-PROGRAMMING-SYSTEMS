#include "downstack.h"

/*
Cuong Ngo, CS202, Asignment 1, 7/11/14
The main purpose of this program is to create a game called "War". This program can only
support for two players for now. Each player will receive a deck of 26 cards.
This is the first phrase of the programs where most of the rules
have not been created in this program.
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
		void insert_played_card(int value, char type, int value2, char type2);	//take arguements and insert into array of linear linked list
		int compare_played(hand & obj, int value, char type, int value2, char type2);	//take arguemenst and compare the card
		void remove();	//remove the card
		void print();
	private:
		table ** played_card;	//array of pointers
		int table_size;	//set the table size
};
