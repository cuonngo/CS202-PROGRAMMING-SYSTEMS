#include "downstack.h"

/*
Cuong Ngo, CS202, Asignment 1, 7/11/14
The main purpose of this program is to create a game called "War". This program can only
support for two players for now. Each player will receive a deck of 26 cards.
This is the first phrase of the programs where most of the rules
have not been created in this program.
*/


array::array()	//default constructure
{
	cards = new card * [52];	//create 52 array of pointers and setting it to null
	for(int i = 0; i < 52; ++i)
	{
		cards[i] = NULL;
	}
}

array::array(const array & obj)	//copy constructure
{
	cards = new card * [52];	//create 52 array of pointers
	for(int i = 0; i < 52; ++i)
	{
		cards[i] = obj.cards[i];	//copy the 52 array to another 52 array
	}
}

array::~array()	//destructure
{
	for(int i = 0; i < 52; ++i)	//deleting all 52 cards
		delete cards[i];
	delete [] cards;
}

void array::add_card(int value, char type)	//insert card by taking the int and char
{
	int index = 0;
	while(cards[index] != NULL && index < 52)	//find an empty spot
		++index;
	if(value == 15)
		cards[index] = new joker(value, type);	//insert a card into array
	else if(value == 2)
		cards[index] = new two(value, type);
	else
		cards[index] = new other(value, type);
}

void array::remove_card(int & value, char & type)	//remove cards and return the int and char by reference
{
	value = cards[0] -> get_rank();	//get the card rank
	type = cards[0] -> get_suit();	//get the card type
	delete cards[0];	//delete the card
	cards[0] = NULL;
	for(int i = 0; i < 51; ++i)	//increment all of the array by one after removing the top array
	{
		if(cards[i+1] == NULL)
		{
			cards[i] = NULL;
			break;
		}
		cards[i] = cards[i + 1];
	}
}
CLL::CLL():next2(NULL)	//default structure
{
	
}

CLL::CLL(const CLL & obj):array(obj), next2(NULL)	//copy constructure
{
	
}

CLL::~CLL()	//destructure
{

}

CLL *& CLL::gonext()	//return the next pointer
{
	return next2;
}

void CLL::connectnext(CLL * connection)	//connect up the node
{
	next2 = connection;
}

void CLL::display_stack()	//dispaly all cards from the player's stack
{
	for(int index = 0; index < 52; ++index)
	{
		if(cards[index] != NULL)
			cards[index] -> display();
		else
			break;
	}
}

bool CLL::checkempty()	//check if their stack is empty
{	
	if(cards[0] = NULL)
		return true;
}
hand::hand(int size)	//default constructure
{
	players = size;
	rear = new CLL;
	rear -> connectnext(rear);
	for(int i = 1; i < size; ++i)
	{
		CLL * head = rear -> gonext();
		CLL * temp = new CLL;
		temp -> connectnext(head);
		rear -> connectnext(temp);
		rear = temp;
	}
}

hand::hand(const hand & obj)	//copy constructure
{
	copy(obj.rear, rear);	//called the copy function and pass in the arguments
}

hand::~hand()	//destructure
{
	CLL * current = rear -> gonext();
	rear -> connectnext(NULL);	//turn it into a LLL
	rear = current;	//set rear to head
	while(current)
	{
		current = current -> gonext();	//traverse current
		delete rear;	//delete node
		rear = current;
	}
}

void hand::copy(CLL * source, CLL *& destination)	//this function will copy the CLL into another CLL
{
	if(!source)	//if empty
	{
		destination = NULL;
		return;
	}
	destination = new CLL(*source);	//create a new node and copy it in
	copy(source -> gonext(), destination -> gonext());	//recursive call
}

void hand::display_stack()	//display all card from the players
{
	int i = 1;
	CLL * current = rear -> gonext();
	while(current -> gonext() != rear -> gonext())
	{
		cout << "\n\nPlayer " << i << endl;
		display_stack(current);
		current = current -> gonext();
		++i;
	}
        cout << "\n\nPlayer " << i << endl;
        display_stack(current);
        current = current -> gonext();
        ++i;

}

void hand::display_stack(CLL * rear)	//display cards from the Circular linear linked list
{
	rear -> display_stack();
}

void hand::remove_card(int index, int & value, char & type)
{
	int numPlayer = 0;
	CLL * temp = rear;
	while(numPlayer != index)
	{
		temp = temp -> gonext();
		++numPlayer;
	}
	temp -> remove_card(value, type);
	
}
/*void hand::remove_card(int & value, char & type, int & value2, char & type2)	//remove card and return the values as a reference
{
	remove_card(rear -> gonext(), value, type);
	remove_card(rear, value2, type2);
}
void hand::remove_card(CLL * rear, int & value, char & type)	//remove card and return it by reference
{
	rear -> remove_card(value, type);
}*/

void hand::insert_player(int index, int num, char type)
{
	int numPlayer = 0;
	CLL * temp = rear -> gonext();
	while(numPlayer != index)
	{
		temp = temp -> gonext();
		++numPlayer;
	}
	temp -> add_card(num, type);
}

bool hand::checkempty()	//check if card is empty
{
	if(rear -> checkempty() || rear -> gonext() -> checkempty())
	{
		cout << "Game Over! " << endl;
		return true;
	}
}
