#include "table.h"
bool again();

/*
Cuong Ngo, CS202, Asignment 1, 7/11/14
The main purpose of this program is to create a game called "War". This program can only
support for two players for now. Each player will receive a deck of 26 cards.
This is the first phrase of the programs where most of the rules
have not been created in this program.
*/


int main()
{
	int value, value2, num; char type, type2;	//create a tempory values for cards
	deck newdeck;

	cout << "Enter the number of players: ";
	cin >> num;	cin.ignore(100,'\n');
	hand newhand(num);
	played newplayed(num);
	int cards = 54/num;

	for(int i = 0; i < cards; ++i)	//dealt 52 cards into 2 stack evenly
	{
		for(int j = 0; j < num; ++j)
		{
			newdeck.draw(value, type);
			newhand.insert_player(j, value, type);
		}
	}
	newhand.display_stack();
	card * ptr = new joker;
	ptr -> display();
	return 0;	
}

bool again()	//ask user if want to go to next round
{
	char response;
	cout << "Do you want to keep on playing? ";
	cin >> response;
	cin.ignore(100,'\n');
	if(toupper(response) == 'Y')
		return true;
	else
		return false;

}
