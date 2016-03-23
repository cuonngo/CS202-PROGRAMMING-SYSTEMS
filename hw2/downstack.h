#include "deck.h"

/*
Cuong Ngo, CS202, Asignment 2, 7/20/14
The main purpose of this program is to create a game called "War". This program can only
support multiple players up to 54. Preferly to play with 4 players.
The deck of 54 cards will divide evenly. If there are left over, the winner
of the first round will get those cards.
This is the second phrase of the programs where most of the rules
have been created in this program.
*/


class array	//a array class that has a card classs
{
	public:
		array();	//default constructure
		array(const array & obj);	//copy constructure
		~array();	//destructure
		void add_card(int value, char type);	//insert card into the array
		void remove_card(int & value, char & type);	//remove card and return by reference
		bool isempty();
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
		void passing(deck & obj, int num);
		void insert_player(int index, int num, char type);
		bool remove_card(int index, int & value, char & type);
		void winner(deck & obj, int num);
	protected:
		void copy(CLL * source, CLL * & destination);	//copy the CLL into another CLL
		void display_stack(CLL * rear);	//display all card from the stack
//		void remove_card(CLL * rear, int & value, char & type);	//remove cards from the stack
		CLL * rear;	//has a rear pointer from CLL class
		int players;
};
