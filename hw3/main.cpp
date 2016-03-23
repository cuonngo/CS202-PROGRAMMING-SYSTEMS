#include "heap.h"
using namespace std;
void welcome();
int menu();

/*
Cuong Ngo, CS202, Asignment 3, 8/4/14
The main purpose of this assignment is to create a Tic-Tac-Toe games.
This game can be played with two players. In each game, the user can
store the games inside the heap data structure with the highest move priority.
When the game is finished, the game will be removed from the heap
*/

int main()
{
	welcome();
	int response = 0;
	heap newHeap;
	do
	{
		response = menu();	//display the menu
		newHeap.remove();	//remove any game that has -1 move
		if(response == 1)
			newHeap.createGame();	//create a new game and start the first move
		else if(response == 2)
			newHeap.continueGame();	//continue the game
		else if(response == 3)
			newHeap.display();	//display the entire games
	}while(response != 4); 		//exit if response is 4
	return 0;
}

void welcome()	//display the welcome messages
{
        cout << "Welcome to Tic Tac Toe!\n"
                << "Here's how to play:\n" 
                << "You must select a number from 0 to 8, which will represent\n"
                << "a space in the grid\n"
                << "Let me show you what number represents which square!\n\n"
                << " 0 | 3 | 6 \n"
                << "---+---+---\n"
                << " 1 | 4 | 7 \n"
                << "---+---+---\n"
                << " 2 | 5 | 8 \n";

}

int menu()	//display the menu and return it as an integer
{
	cout << "1. Create game\n"
		<<" 2. Continue game\n"
		<<" 3. Display All Game\n"
		<<" 4. Quit\n";
	int num;
	cin >> num;
	return num;	//return the num integer
}
