#include "table.h"
bool again();


/*
Cuong Ngo, CS202, Asignment 2, 7/20/14
The main purpose of this program is to create a game called "War". This program can only
support multiple players up to 54. Preferly to play with 4 players.
The deck of 54 cards will divide evenly. If there are left over, the winner
of the first round will get those cards.
This is the second phrase of the programs where most of the rules
have been created in this program.
*/


int main()
{
	int num, tie[4];	//tie variable will hold the player number whose card are tie with the other
	deck newdeck;	//create a deck
	cout << "Welcome to the War Game! \nHow many players: " << endl;
	cin >> num;	cin.ignore(100,'\n');
	hand newhand(num);	//create players' stacks with the numbers of players
	played newplayed(num);	//create the array of table with the size of players
	newhand.passing(newdeck, num);	//passing cards from the hand to players stack
	do
	{
		newplayed.game(newhand, newdeck);	//start the game
		newplayed.check_two(newhand, newdeck);	//check to see if there are two. if so, start automatic war
		num = newplayed.compare(tie, newhand, newdeck);	//check too see if there are a tie
		newhand.winner(newdeck, num);	//insert cards into the winner decks
	}while(again());	//ask the user if he/she wants to keep on playing.
	return 0;
}

bool again()	//ask user if want to go to next round
{
	char response;
	cout << "\n\n\nDo you want to keep on playing? ";
	cin >> response;
	cin.ignore(100,'\n');
	if(toupper(response) == 'Y')
		return true;	//return true if user want to keep on playing
	else
		return false;	//otherwise, return false.

}
