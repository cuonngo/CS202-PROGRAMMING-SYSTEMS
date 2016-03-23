#include "heap.h"
using namespace std;

/*
Cuong Ngo, CS202, Asignment 3, 8/4/14
The main purpose of this assignment is to create a Tic-Tac-Toe games.
This game can be played with two players. In each game, the user can
store the games inside the heap data structure with the highest move priority.
When the game is finished, the game will be removed from the heap
*/


node::node(game & obj):right(NULL), left(NULL), game(obj)	//default constructor
{

}

node::~node()	//destructor
{

}

node *& node::go_left()	//return a left pointer	by referece
{
        return left;
}

node *& node::go_right()	//return a right pointer by reference
{
        return right;
}

void node::connect_left(node * connection)	//take an node arguement and connect it to the left
{
        left = connection;
}

void node::connect_right(node * connection)	//take an node arguement and connect it to the right
{
        right = connection;
}

heap::heap():root(NULL)		//set root to NULL and start a game by creating a game
{
	createGame();
}

heap::~heap()		//destructor
{
	remove_all(root);	//call out the remove all function
}

int heap::insert(game & obj)	//a wrapper function of insert recursive
{
        return insert(root, obj);	//take the game object and call the function by passing the obj and root
}
int heap::insert(node * & root, game & obj)	//insert recursivly
{
        if(!root)	//if its null then create a new node
        {
                root = new node(obj);	//create a new node and loading the game obj
                root -> go_right() = NULL;	//set right and left to null
                root -> go_left() = NULL;
                return 1;
        }
        else if(count(root -> go_left()) == count(root -> go_right()))	//keep track of the subtree by counting
                insert(root -> go_left(), obj);				//by doing this, we can keep the tree balance
        else if(count(root -> go_left()) > count(root -> go_right()))	//by know where to traverse
                insert(root -> go_right(), obj);
        return 1;
}

int heap::count(node * root)	//count how many node recursively
{
        if(!root)	//if empty return 0
                return 0;
        return count(root -> go_left()) + count(root -> go_right()) + 1;	//count and traverse to the next node
}


int heap::createGame()	//create a game	and start the game
{
	game newGame;	//create an game object
        do
        {
                if(newGame.checkdraw())	//check to see if it's a draw
                        break;
                if(newGame.get_turn() == 'O')	//check to see whose turn
                        newGame.set_turn('X');
                else
                        newGame.set_turn('O');
                newGame.insert(newGame.get_turn());	//play the first game of tic tac toe
                newGame.display();	//display the board
		if(!again())	//ask if the user want to continue playing
			break;
        }while(!newGame.checkwinner());	//do while if there is a winner
	insert(newGame);	//insert the game into the heap structure
	traverse(root);		//traverse the root
	int num = root -> get_move();	//get the player's move
	cout << "Number: " << num << endl;	//print out the moves
}

int heap::continueGame()	//continue the game wrapper function
{
	int num = 0;
	cout << "How many moves? ";	//ask the user which game they want to continue
	cin >> num;	//read in the num
	node * temp = retrieve(root, num);	//retrieve the node that match the number of move
	if(temp != NULL)
		continueGame(temp);	//continue the game by passing the root
	return 1;
}
int heap::continueGame(node * & root)	//continue game recursively
{
        do                                                                                            
        {                                                                                             
                if(root -> checkdraw())  //check to see if it's a draw                                      
                        break;                                                                        
                if(root -> get_turn() == 'O')	//check whose turn                                
                        root -> set_turn('X');                                                        
                else                                                                                  
                        root -> set_turn('O');                                                     
                root -> insert(root -> get_turn());       //insert the player move into the board                                      
                root -> display();                        //display the board     
                if(!again())                              //ask user if they want to continue                                            
                        break;                                                
        }while(!root -> checkwinner());   		//if there is a winner, end the loop
	return 1;
}

node * heap::retrieve(node * root, int num)	//this function will retrieve the player by finding the match of the argument
{
	if(!root)
		return NULL;
	if(root -> get_move() == num)	//if there is a match of moves
		return root;	//return root
	if (retrieve(root -> go_left(), num) != NULL )	//traverse right and left if there is no match
		return retrieve(root -> go_left(), num);
	else	
		return retrieve(root -> go_right(), num);	
}
int heap::display()	//wrapper function of display all
{
	return display(root);	//call the display all function by passing in the root
}
int heap::display(node * root)	//display function recursively
{
	if(!root)
		return 0;
	cout << "Move: " << root -> get_move() << endl;	//print out the number of players' move
	root -> display();	//display the board
	display(root -> go_left());	//traverse left
	display(root -> go_right());	//traverse right
	return 1;
}

void heap::traverse(node * & root)	//traverse to all the node to call the heapify function
{
	if(!root)
		return;
	traverse(root -> go_left());	//traverse left
	heapify(root);			//heapify to have the highest move priority
	traverse(root -> go_right());
}
void heap::heapify(node * & root)	//heapify to keep the highest move priority
{
	node * tempL;
	node * tempR;
	node * maxN = root;
	int max = root -> get_move();
	if(root -> go_left() != NULL)	//this will find the maximum value out of the 3 (parent and child)
	{
		if(max < root -> go_left() -> get_move())
		{
			max = root -> go_left() -> get_move();	//get the max value of the move
			maxN = root -> go_left();	//set max pointer to the left if left is the highest
		}
	}
	if(root -> go_right() != NULL)
	{
		if(max < root -> go_right() -> get_move())
		{
			max = root -> go_right() -> get_move();	//get the max vaulue of the move
			maxN = root -> go_right();	//set max pointer to the right if right is the highest
		}
	}

	if(max == root -> get_move())
		return;		//if the parent is the highest, return 
	tempR = maxN -> go_right();
	tempL = maxN -> go_left();
	if(max == root -> go_left() -> get_move())	//swapping the node to keep the highest priority
		maxN ->connect_right(root->go_right());
	else
		maxN -> connect_right(root->go_left());
	root ->connect_right(tempR);	//connect to the right child
	root ->connect_left(tempL);	//conect to the left child
	maxN ->connect_left(root);	//connect the root
	root = maxN;	//change root to max
}

bool again()	//ask player if they want to continue the game
{
	char response;
	cout << "Do you want to continue? ";
	cin >> response;
	if(toupper(response) == 'Y')	//return true if player entered yes
		return true;
	return false;	//else false
}
int heap::remove()	//wrapper function of remove
{
	return remove(root);	//call the recursive remove by passing the root
}
int heap::remove(node * & root)	//removei recursively
{
	if(!root)
		return 0;
	remove(root -> go_left());	//go to the leaf of BST
	remove(root -> go_right());
	if(root -> get_move() == -1)	//if the move is -1 then remove that node
	{
		delete root;
		root = NULL;
	}
}

int heap::remove_all(node * & root)	//this recursive function will remove all of the node
{
	if(!root)
		return 0;
	remove_all(root -> go_left());	//traverse to the leaf
	remove_all(root -> go_right());
	delete root;	//delete and set it to NULL
	root = NULL;
}
