#include "table.h"

/*
Cuong Ngo, CS202, Asignment 1, 7/11/14
The main purpose of this program is to create a game called "War". This program can only
support for two players for now. Each player will receive a deck of 26 cards.
This is the first phrase of the programs where most of the rules
have not been created in this program.
*/


table::table():list()	//default constructure
{
	
}

table::table(const table & obj):list(obj)	//copy constructure
{

}

table::~table()	//destructure
{

}

void table::insert_played_card(int value, char type)	//insert card by taking the int and char value
{
	list::insert(value, type);	//call the insert function from the list class
}

played::played(int size)	//constructure to create the array of linear linked list
{
	table_size = size;
	played_card = new table * [size];	//create array of pointers
	for(int i = 0; i < size; ++i)
		played_card[i] = new table;	//set each pointer to table
}

played::played(const played & obj)	//copy constructure
{
	table_size = obj.table_size;	//copy the table size
	played_card = new table * [table_size];	//create a array of linear linked list
	for(int i = 0; i < table_size; ++i)
		played_card[i] = new table(*obj.played_card[i]);	//copy each node

}

played::~played()	//destructure
{
	for(int i = 0; i < table_size; ++i)	//going through all array
		delete played_card[i];	//delete the node pointer
	delete [] played_card;	//delete the array
}

void played::insert_played_card(int value, char type, int value2, char type2)	//insert card by taking int and char values
{
	
/*	played_card[0] -> insert_played_card(value, type);	//insert into first array
	played_card[1] -> insert_played_card(value2, type2);	//insert into the second array
*/
}

int played::compare_played(hand & obj, int value, char type, int value2, char type2)	//take int and char values and compare
{/*
	if(value > value2)	//compare to see who's the winner
	{
		cout << "Player 1 Win!" << endl;
		obj.first_stack(value, type);	//insert into the winner's stack
		obj.first_stack(value2, type2);
		return 1;
	}
	else if(value == value2)
	{
		cout << "Draw!" << endl;
		obj.first_stack(value, type);	//put the cards back into the player's stack if its a draw
		obj.second_stack(value2, type2);
		return 0;
	}
	else
	{
		cout << "Player 2 Win!" << endl;
		obj.second_stack(value, type);
		obj.second_stack(value2, type2);
		return -1;
	}
*/}

