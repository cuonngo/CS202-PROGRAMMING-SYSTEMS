#include "table.h"
class intersection;


/*
Cuong Ngo, CS202, Asignment 2, 7/20/14
The main purpose of this program is to create a game called "War". This program can only
support multiple players up to 54. Preferly to play with 4 players.
The deck of 54 cards will divide evenly. If there are left over, the winner
of the first round will get those cards.
This is the second phrase of the programs where most of the rules
have been created in this program.
*/

class vertex	//create a vertex class
{
        public:
                vertex();	//constructure
                ~vertex();	//destructure
		vertex(const vertex & obj);	//copy constructure
		vertex(int num, char val);	//qualify constructure
        private:
                intersection * head;
                int score;
};


class intersection	//create an adjancecy table
{
        public:
                intersection();	//constructure
		intersection(const intersection & obj);	//copy constructure
                ~intersection();	//destructure

                intersection *& go_next();	//traverse next
                void connect_next(intersection * connection);	//connect up the table

        private:
                intersection * next;
                vertex * adjacent;	//has a vertex class


};

class graph	//create a graph which has a intersection class
{

        public:
                graph(int size);	//constructure
		graph(const graph & obj);	//copy constructure
                ~graph();	//destructure

        private:
                vertex ** adjacency_list;	//has a vertex class
                int graph_size;
};


