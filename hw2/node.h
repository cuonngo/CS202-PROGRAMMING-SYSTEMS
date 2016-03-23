#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


/*
Cuong Ngo, CS202, Asignment 2, 7/20/14
The main purpose of this program is to create a game called "War". This program can only
support multiple players up to 54. Preferly to play with 4 players.
The deck of 54 cards will divide evenly. If there are left over, the winner
of the first round will get those cards.
This is the second phrase of the programs where most of the rules
have been created in this program.
*/



class card      //this is a card class where each card have an interger and a character value.
{
        public:
                card(); //constructure
                card(const card & obj); //copy constructure
                card(int value, char type);     //qualified constructure
                virtual ~card();        //destructure

                virtual void display(); //pure virtual function which display the current card
                int get_rank(); //return the rank of the card
                char get_suit();        //return the suit of the card
        protected:
                int rank;
                char suit;
};

class node: public card	//node derived from a classcard	
{
        public:
                node();	//constructure
                node(const node & obj);	//copy constructure
                node(int value, char type);	//qualify constructure
                ~node();

                node *& go_next();	//traverse next
                void connect_next(node * connection);	//connect up the node
        protected:
                node * next;
};

class joker: public node	//create Joker card class
{
        public:
                joker();	//constructure
                joker(const joker & obj);	//copy constructure
                joker(int value, char type);	//qualified constructure
                ~joker();	//destructure
        protected:
                void display();	//virutal display function

};

class two: public node	//create Twos card class
{
        public:
                two();	//constructure
                two(const two & obj);	//copy constructure
                two(int value, char type);	//qualify constructure
                ~two();	//destructure

        protected:
                void display();	//virtual display
};

class other: public node	//create other cards class
{
        public:
                other();	//constructure
                other(const other & obj);	//copy constructure
                other(int value, char type);	//qualify constructure
                ~other();	//destructure
        protected:
                void display();	//virtual display function;
};

