#include "deck.h"
/*
Cuong Ngo, CS202, Asignment 1, 7/11/14
The main purpose of this program is to create a game called "War". This program can only
support for two players for now. Each player will receive a deck of 26 cards.
This is the first phrase of the programs where most of the rules
have not been created in this program.
*/


class array	//a array class that has a card classs
{
	public:
		array();	//default constructure
		array(const array & obj);	//copy constructure
		~array();	//destructure
		void add_card(int value, char type);	//insert card into the array
		void remove_card(int & value, char & type);	//remove card and return by reference
	protected:
		card ** cards;	//create a cards of array pointers


};

class CLL: public array	//a circle linked list class is a array class
{
	public:
		CLL();	//default constructure
		CLL(const CLL & obj);	//copy constructure
		~CLL();	//destructure

		CLL *& gonext();	//return a next pointer
		void connectnext(CLL * connection);	//connect the node
		void display_stack();	//display the cards from the circle linked list of array
		bool checkempty();	//check if its empty
	protected:
		CLL * next2;	//create a next pointer

};

class hand	//a hand class that has a circle linear linked list
{
	public:
		hand(int size);	//default constructure
		hand(const hand & obj);	//copy constructure
		~hand();	//destructure 

		void display_stack();	//display all cards in the stack
//		void remove_card(int & value, char & type, int & value2, char & type2);	//remove the top cards from the stack
		bool checkempty();	//check if its empty
		void insert_player(int index, int num, char type);
		void remove_card(int index, int & value, char & type);
	protected:
		void copy(CLL * source, CLL * & destination);	//copy the CLL into another CLL
		void display_stack(CLL * rear);	//display all card from the stack
//		void remove_card(CLL * rear, int & value, char & type);	//remove cards from the stack
		CLL * rear;	//has a rear pointer from CLL class
		int players;
};
