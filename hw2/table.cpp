#include "table.h"


/*
Cuong Ngo, CS202, Asignment 2, 7/20/14
The main purpose of this program is to create a game called "War". This program can only
support multiple players up to 54. Preferly to play with 4 players.
The deck of 54 cards will divide evenly. If there are left over, the winner
of the first round will get those cards.
This is the second phrase of the programs where most of the rules
have been created in this program.
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

int played::game(hand & obj, deck & obj2)	//this function  will start the game
{
	int value; char type;
	for(int i = 0; i < table_size; ++i)	//remove card from the deck
	{
		if(obj.remove_card(i, value, type))
		{
			played_card[i] -> insert_played_card(value, type);	//insert to played
			cout << "Player " << i+1 << ": ";
			played_card[i] -> display_card();
			cout << endl;					
		}
		else
		{
			cout << "Player " << i + 1<< " has an empty stack! " << endl;	//if empty
		}
	}
//	return compare_played(obj);
}

int played::war(int index, hand & obj, deck & obj2)	//call automic war which draw 4 cards
{
	for(int i = 0; i < 4; ++i)	//loops of 4 times
	{
		int value;
		char type;
		if(obj.remove_card(index,value,type))	//remove 4 cards
			played_card[index] -> insert_played_card(value, type);	//insert into table
/*		else
		{
			table * current = played_card[i];
			while(!current -> isempty())
			{
				int value = current -> get_value();
				char type = current -> get_type();
				obj2.insert(value, type);
				current -> remove();
			}
		}
*/	}
	return 1;
}

int played::one(int index, hand & obj)	//draw 1 card
{
	int value;
	char type;
	if(obj.remove_card(index, value, type))	//remove card from stack
		played_card[index] -> insert_played_card(value, type);	//insert into played
}


int played::compare(int tie[], hand & obj, deck & obj2)	//compare cards
{
	int max = highest();	//get highest
	int count = 0;
	int player;
	for(int i = 0; i < table_size; ++i)	//find if there are any ties
	{
		if(played_card[i] -> get_value() == max)
		{
			tie[count] = i;
			++count;
		}	
	}
	if(count == 1)	//if there are no tie
	{
		int win = tie[0];
		cout << "Player " << win + 1 << " win!" << endl;	//player with highest win
		remove_played(win, obj);
		player = tie[0];
	}
	else	//check to see if there are draw
	{
		max = 0;
		cout << "DRAW! draw 1 cards! " << endl;
		for(int i = 0; i < count; ++i)
		{
			int win = tie[i];	//get the tie player
			one(win, obj);
			if(!played_card[i] -> isempty())	//check if its empty
			{
				cout << "Player " << win + 1 << ": ";
				played_card[i] -> display_card();	//displaycard
			}
		}
		for(int i = 0; i < count; ++i)	//compare which player has the highest
		{
			int max = 0;
			int win = tie[i];
			if(played_card[win] -> get_value() > max)//find the max
			{
				max = played_card[win] -> get_value();
				player = win;
			}
		}
		cout << "Player " << player + 1 << " win! " << endl;
		remove_played(player, obj);	//remove cards from the player and insert into winner
	}
	return player;
}

int played::highest()	//find the highest card from the played table
{
	int max = 0;
	for(int i = 0; i < table_size; ++i)
	{
		if(played_card[i] -> get_value() > max)	//grab the max value
			max = played_card[i] -> get_value();
	}
	return max;	//return the highest card
}

int played::check_two(hand & obj, deck & obj2)	//check if there are two
{
	int check = 0;
	for(int i = 0; i < table_size; ++i)
	{
		if(played_card[i] != NULL)
		{
			if(played_card[i] -> get_value() == 2)	//if there are two
			{
				check = 1;
				cout << "Player " << i + 1 << " has a two. " << endl;
			}
		}
	}
	if(check == 1)	//start automatic war if there are 2
	{
		cout << "AUTOMATIC WAR! - each player draw 4 cards" << endl;
		for(int i = 0; i < table_size; ++i)
		{
			war(i, obj, obj2);	//call the war function
			cout << "Player " << i + 1 << ": ";
			played_card[i] -> display_card();	//display card
		}

	}
	return check;
}

void played::remove_to_deck(deck & obj)	//this function will remove cards from the deck and isnert into the winner stack
{
	table * current;
	for(int i = 0; i < table_size; ++i)
	{
		if(played_card[i] != NULL)	//check to see if itsempty
		{
			current = played_card[i];
			while(!current -> isempty())
			{
				int value = current -> get_value();	//get value
				char type = current -> get_type();
				obj.insert(value, type);	//insert into winner stack
				current -> remove();
			}
		}
	}
}
void played::remove_played(int player, hand & obj)	//removed cards from the played and insert into player
{
	table * current;
	for(int i = 0; i < table_size; ++i)
	{
		current = played_card[i];
		while(!current ->  isempty())	//check to see if its empty
		{
			char type = current -> get_type();
			int value = current -> get_value();
			obj.insert_player(player, value, type);	//insert into player stack
			current -> remove();
		}
	}
}
