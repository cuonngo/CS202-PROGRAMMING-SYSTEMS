#include "node.h"

/*
Cuong Ngo, CS202, Asignment 1, 7/11/14
The main purpose of this program is to create a game called "War". This program can only
support for two players for now. Each player will receive a deck of 26 cards.
This is the first phrase of the programs where most of the rules
have not been created in this program.
*/



class list	//a linear linked list class that will hold 52 cards in a deck
{
	public:
		list();	//default constructure
		list(const list & obj);	//copy destructure
		~list();	//destructure

		void insert(int value,char type);	//insert card into the linear linked list
		void display();	//wrapper function of displaying all of the cards
		void shuffle(int random);	//shuffle the card randomly
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
		~deck();

		void display();	//display all of the cards
		void shuffle();	//shuffle the cards
		void draw(int & value, char & type);	//remove the cards from the deck
	protected:
		void create();	//create 52 cards
};
