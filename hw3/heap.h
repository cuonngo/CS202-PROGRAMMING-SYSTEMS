#include "game.h"

/*
Cuong Ngo, CS202, Asignment 3, 8/4/14
The main purpose of this assignment is to create a Tic-Tac-Toe games.
This game can be played with two players. In each game, the user can
store the games inside the heap data structure with the highest move priority.
When the game is finished, the game will be removed from the heap
*/

class node: public game 	//derieve from the game class
{
        public:
                node(game & obj);	//constuctor
                ~node();	//destructor

                node *& go_left();	//return the left pointer by reference
                node *& go_right();	//return the right pointer by reference

                void connect_left(node * connection);	//connect node to the left
                void connect_right(node * connection);	//connect node to the right
        protected:
                node * left;	//left pointing to the node
                node * right;	//right pointing to the node

};


class heap	//this class will hold the games inside a node by creating a heap data structure
{
        public:
                heap();	//constructor
                ~heap();	//destructor
                int insert(game & obj);	//insert game by taking game's object
                int count(node * root);	//count how many node, so it can be use to keep the tree balance
                int startgame();	//manage the game
                int createGame();	//create a new game
		int continueGame();	//continue the existed game
		int display();		//display all game
		int remove();		//remove a game
        protected:
		int remove_all(node * & root);
		int remove(node * & root);	//remove the game
		void traverse(node * & root);	//traverse to find the game
		void heapify(node * & root);	//heapify to keep the highest move priority
		int continueGame(node * & root);	//continue the game
		int display(node * root);	//display the game
                int insert(node * & root, game & obj);	//insert the game into the heap structure
		node * retrieve(node * root, int num);	//find the node with the num argument matching
                node * root;	//has a node class

};

bool again();	//ask the player if they want to continue and return a true/false
