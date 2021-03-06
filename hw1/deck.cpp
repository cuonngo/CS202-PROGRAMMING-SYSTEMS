#include "deck.h"
#include <cstdlib>
/*
Cuong Ngo, CS202, Asignment 1, 7/11/14
The main purpose of this program is to create a game called "War". This program can only
support for two players for now. Each player will receive a deck of 26 cards.
This is the first phrase of the programs where most of the rules
have not been created in this program.
*/

list::list():head(NULL)	//default constructure
{

}

list::list(const list & obj)	//copy constructure
{
	copy_node(obj.head, head);
}

list::~list()	//destructure calling the remove all function
{
	remove_all(head);	
}

void list::insert(int value, char type)	//insert the card into the list by taking the int and char arguement
{
	node * temp;
	if(value == 2)
		temp = new two(value, type);
	else if(value == 15)
		temp = new joker(value, type);	//create a new node which is a card
	else
		temp = new other(value, type);
	temp -> connect_next(head);	//connect it as a LLL
	head = temp;
	return;
}

void list::display()	//wrapper function of displaying
{
	return display(head);	//call the recursive function
}

void list::remove_all(node * head)	//remove all of the node inside the linear linked list
{
	if(!head)	//check to see if head is null
		return;
	remove_all(head -> go_next());	//traverse
	delete head;
	head = NULL;
	return;	
}

void list::copy_node(node * source, node * & destination)	//copy cards from a list to another list
{
	if(!source)
		destination = NULL;
	destination = new node(*source);
	copy_node(source -> go_next(), destination -> go_next());
}

void list::display(node * head)	//display all recursively
{
	if(!head)
		return;
	head -> display();
	display(head -> go_next());
}

void list::shuffle(int random)	//shuffle the deck by taking in the random int
{

	int i = 0;
	node * temp = head;
	node * previous = temp;
	while(i < random)	//while it is less than random number
	{
		previous = temp;
		temp = temp -> go_next();
		++i;
	}
	if(i == 0)	//if random is 0
		return;
	else
	{
		previous -> connect_next(temp -> go_next());	//remove the current node
		temp -> connect_next(head);	//insert it back to the head
		head = temp;
	}
}
deck::deck()	//default constructure
{
	create();	//create a deck
	shuffle();	//shuffle the deck
}

deck::~deck()	//destructure for deck
{
	
}

void deck::display()	//call out the display function from list class
{
	list::display();
}

void deck::shuffle()	//generate the random number and call the shuffle function
{
	srand(time(NULL));	//initalize time to null
	for(int i = 0; i < 100; ++i)
	{
		list::shuffle(rand()% 54);	//generate the random and put it in the arguement
	}

}

void deck::draw(int & value, char & type)	//draw a card from the deck and return it as a pass by reference of int and char
{
	value = head -> get_rank();	//get the int rank
	type = head -> get_suit();	//get the char suit
	node * temp = head -> go_next();
	delete head;
	head = temp;
}
void deck::create()	//create 52 cards with 4 suit
{
	for(int i = 2; i < 15; ++i)
	{
		insert(i, 'H');
		insert(i, 'D');
		insert(i, 'C');
		insert(i, 'S');
	}
	insert(15, 'R');
	insert(15, 'B');
}
