#include "deck.h"
#include <cstdlib>
/*
Cuong Ngo, CS202, Asignment 2, 7/20/14
The main purpose of this program is to create a game called "War". This program can only
support multiple players up to 54. Preferly to play with 4 players.
The deck of 54 cards will divide evenly. If there are left over, the winner
of the first round will get those cards.
This is the second phrase of the programs where most of the rules
have been created in this program.
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
	else if(value == 1)
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

void list::display_card()	//this function will display the card
{
	if(!head)	//check if its empty
		return;
	head -> display();
}
char list::get_type()	//return the suit
{
	if(!head)
		return '\0';
	return head -> get_suit();	//get suit
}
int list::get_value()	//return the rank
{
	if(!head)
		return 0;
	return head -> get_rank(); 	//get rank
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

void list::remove()	//remove card
{
	if(head == NULL)	//if empty
		return;
	node * current = head -> go_next();	//remove head card
	delete head;
	head = current;
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

int list::isempty()
{
	if(!head)
		return 1;
	else
		return 0;
}
deck::deck():list()	//default constructure
{
	create();	//create a deck
	shuffle();	//shuffle the deck
}

deck::deck(const deck & obj):list(obj)
{

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

bool deck::draw(int & value, char & type)	//draw a card from the deck and return it as a pass by reference of int and char
{
	if(head)
	{
		value = head -> get_rank();	//get the int rank
		type = head -> get_suit();	//get the char suit
		node * temp = head -> go_next();
		delete head;
		head = temp;
		return true;
	}
	return false;
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
	insert(1, 'R');	//create a joker with Red or Black suit
	insert(1, 'B');
}

