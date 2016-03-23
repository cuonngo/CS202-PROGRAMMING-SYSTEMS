#include "graph.h"

/*
Cuong Ngo, CS202, Asignment 2, 7/20/14
The main purpose of this program is to create a game called "War". This program can only
support multiple players up to 54. Preferly to play with 4 players.
The deck of 54 cards will divide evenly. If there are left over, the winner
of the first round will get those cards.
This is the second phrase of the programs where most of the rules
have been created in this program.
*/


vertex::vertex():head(NULL)	//constructure
{

}

vertex::vertex(const vertex & obj)	//copy constructure
{

}
vertex::~vertex()	//destructure
{

}

intersection::intersection():next(NULL), adjacent(NULL)	//constructure
{

}

intersection::~intersection()	//destructure
{

}


intersection *& intersection::go_next()	//go next
{
        return next;
}


void intersection::connect_next(intersection * connection)	//connect the node
{
        next = connection;
}


graph::graph(int size)	//create an ajacency table which will be use for graph
{
        adjacency_list = new vertex * [size];
        graph_size = size;
        for(int i = 0; i < graph_size; ++i)
                adjacency_list[i] = NULL;

}

graph::~graph()	//destructure
{

}


