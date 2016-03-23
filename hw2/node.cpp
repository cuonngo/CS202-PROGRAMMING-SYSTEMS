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



card::card():rank(0), suit('\0')	//default constructure
{

}

card::card(const card & obj)	//copy constructure
{
	if(!obj.rank)	//check to see if its NULL
	{
		rank = 0;
		suit = '\0';
	}
	rank = obj.rank;	//deep copy
	suit = obj.suit;
}

card::card(int value, char type)	//qualifier constructure
{
	rank = value;
	suit = type;
}

card::~card()	//destructure
{

}

void card::display()	//display the current card with rank and suit
{
	
}

int card::get_rank()	//return an interger value of the card
{
	return rank;
}

char card::get_suit()	//return an character of the card
{
	return suit;
}

node::node():next(NULL)	//default constructure
{

}

node::node(const node & obj):card(obj), next(NULL)	//copy constructure
{

}

node::node(int value, char type): card(value, type), next(NULL)	//qualify constructure
{

}

node::~node()	//destructure
{

}

node *& node::go_next()	//return next, so it can be use for traversing
{
	return next;
}

void node::connect_next(node * connection)	//conect the current node with another node by taking the node arguement
{
	next = connection;
}

joker::joker():node()
{

}	

joker::joker(const joker & obj):node(obj)
{
	
}

joker::joker(int value, char type):node(value, type)
{
}
joker::~joker()
{

}

void joker::display()
{
	if(suit == 'R')
		cout << "Card: Joker R "<< endl;
	else
		cout << "Card: Joker B " << endl;
	return;
}

other::other():node()
{

}

other::other(const other & obj):node(obj)
{

}

other::other(int value, char type):node(value, type)
{
}

other::~other()
{

}                                                                                                     
                                                                                                      
void other::display()
{                      
	if(rank == 11)
		cout << "Card: Jack " << suit << endl;
	else if(rank == 12)
		cout << "Card: Queen " << suit << endl;
	else if(rank == 13)
		cout << "Card: King " << suit << endl;
	else if(rank == 14)
		cout << "Card: Ace " << suit << endl;
	else
		cout << "Card: " << rank << " " << suit << endl;
}               

two::two():node()
{

}

two::two(const two & obj):node(obj)
{

}

two::two(int value, char type):node(value, type)
{

}
two::~two()
{

}                                                                                                     
                                                                                                      
void two::display()                                                                                 
{
	cout << "Card: 2 " << suit << endl;                                                  
	return;
}


