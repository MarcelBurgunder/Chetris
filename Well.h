#ifndef WELL_INCLUDED
#define WELL_INCLUDED

#include "Piece.h"
#include <queue>
using namespace std;

const int WELLDEPTH = 19;
const int WELLWIDTH = 12;

class Screen;

class Well
{
public:
	Well(Screen* screen);		// initialises an empty well and a queue of 3 random Pieces
    void display(int x, int y) const;	// displays all characters in two
														// dimensional char array
	void emptyWell();		// sets the two dimensional char array to an empty well
	void add(char add, int dp, int wd);		// adds char to well
	Piece queuefront();			// shows front of m_next
	Screen* screen() const;		// returns screen of wells game
	bool cyclequeue();		// dequeues front, and enqueues new random at back
	int countremove(int x) const;	// count how many rows have been filled (from x -> x-4
	void removerows(int toprow);	// removes rows (if any) and returns num of rows removed (from x -> x-4)
	bool rowfull(int row) const;		// checks whether row is full 
	bool rowempty(int row) const;		// checks whether row is empty
	void shiftallabove(int row);	// removes the row, and shifts everything down one row
	char wellspace(int dp, int wd) const;	// returns the character of m_well at that spot.


private:
	char m_well[WELLDEPTH][WELLWIDTH];	// two dimensional character array representing the well
	queue<Piece> m_next;	// A queue with random Pieces, to be used and displayed

	Piece I;		// a library of all different piece types contained in the well
	Piece L;
	Piece J;
	Piece T;
	Piece O;
	Piece S;
	Piece Z;
	Piece Vapor;
	Piece Foam;
	Piece Crazy;

	Screen* m_screen;	// this is a pointer to the wells games screen
};

#endif // WELL_INCLUDED
