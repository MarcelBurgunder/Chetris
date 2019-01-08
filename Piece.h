#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED

// empty char array to intialise the pieces

#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
#include <time.h>

class Well;
class Screen;

// These are all different types of actions/directions for various functions such as moveside & nooverlap

enum action { spawn, lefty, righty, down, rot };

class Piece 
{
public:
	Piece(int type, Well* well);	// takes in the type, and the well it points to
	void special() const;			// various special actions called when piece hits brock bottom!
	void printpiece(Screen& screen, int x, int y) const;	// prints the piece
	bool rotate();	// rotates it (if it can), return whether it rotated
	bool movedown(bool print = true);	// moves the piece down (if it can), else calls solidify.
	void solidify() const;
	bool moveside(int direction);	// moves piece to the <direction>, if it can
	bool instantdown();					// repeatedly calls movedown until it returns false and solidifies
	bool nooverlap(int action) const;	// checks whether well didn't overlap with piece (before piece
											// is moved
	int row() const;				// returns m_row
	int col() const;				// return m_col
	Well* well() const;				// return well pointer
	void printaftermove(bool spawn = false);	// this function prints a piece after it 
												// has moved respectively
	void foamexpand(int sr, int sc, int cr, int cc) const;	// this recursive functions expands the foam
															// for the foam piece when it stops

private:
	char piece0[4][4];
	char piece1[4][4];
	char piece2[4][4];
	char piece3[4][4];
	int m_or;
	int m_row;
	int m_col;
	int m_type;
	Well* m_well;
};

enum PieceType {
    PIECE_I, PIECE_L, PIECE_J, PIECE_T, PIECE_O, PIECE_S, PIECE_Z,
    PIECE_VAPOR, PIECE_FOAM, PIECE_CRAZY, NUM_PIECE_TYPES
};

PieceType chooseRandomPieceType();

#endif // PIECE_INCLUDED
