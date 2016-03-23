#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

/*
Cuong Ngo, CS202, Asignment 1, 7/11/14
The main purpose of this program is to create a game called "War". This program can only
support for two players for now. Each player will receive a deck of 26 cards.
This is the first phrase of the programs where most of the rules
have not been created in this program.
*/



class card	//this is a card class where each card have an interger and a character value.
{
	public:
		card();	//constructure
		card(const card & obj);	//copy constructure
		card(int value, char type);	//qualified constructure
		~card();	//destructure

		virtual void display();	//display the current card
		int get_rank();	//return the rank of the card
		char get_suit();	//return the suit of the card
	protected:
		int rank;
		char suit;
};

class node: public card
{
	public:
		node();
		node(const node & obj);
		node(int value, char type);
		~node();

		node *& go_next();
		void connect_next(node * connection);
	protected:
		node * next;
};

class joker: public node
{
	public:
		joker();
		joker(const joker & obj);
		joker(int value, char type);
		~joker();
	protected:
		void display();

};

class two: public node
{
	public:
		two();
		two(const two & obj);
		two(int value, char type);
		~two();

	protected:
		void display();
};

class other: public node
{
	public:
		other();
		other(const other & obj);
		other(int value, char type);
		~other();
	protected:
		void display();
};
