#include "node.h"


/*
Cuong Ngo, CS202, Asignment 2, 7/20/14
The main purpose of this program is to create a game called "War". This program can only
support multiple players up to 54. Preferly to play with 4 players.
The deck of 54 cards will divide evenly. If there are left over, the winner
of the first round will get those cards.
This is the second phrase of the programs where most of the rules
have been created in this program.
*/


class list	//a linear linked list class that will hold 52 cards in a deck
{
	public:
		list();	//default constructure
		list(const list & obj);	//copy destructure
		~list();	//destructure

		void insert(int value,char type);	//insert card into the linear linked list
		void display();	//wrapper function of displaying all of the cards
		void display_card();
		void shuffle(int random);	//shuffle the card randomly
		int isempty();
		void remove();
		int get_value();
		char get_type();
	protected:
		void remove_all(node * head);	//remove all of the card
		void copy_node(node * source, node * & destination);	//copy card from a linear linked list to another
		void display(node * head);	//display all of the cards recursively
		node * head;	//has a node pointer

};

class deck: public list	//the deck class will be use to create and shuffle which is a list class
{
	public:
		deck();
		deck(const deck & obj);
		~deck();

		void display();	//display all of the cards
		void shuffle();	//shuffle the cards
		bool draw(int & value, char & type);	//remove the cards from the deck
	protected:
		void create();	//create 52 cards
};
