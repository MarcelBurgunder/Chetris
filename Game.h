#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <iostream>
using namespace std;
#include "Well.h"
#include "UserInterface.h"
#include <string>


class Game
{
  public:
    Game(int width, int height);
    void play();
    bool playOneLevel();
    void displayPrompt(std::string s);
    void displayStatus();
	void updatesr();	// updates score and rows
	void updatelevel();	// updates level
	void updatepiece();	// updates piece
	bool dealdrop(Piece x);	// the most important function, deals with the piece dropping into well
	void count_score_update(Piece x);
	string rjn(int x) const;		// this function converts an integer to a right justified string 7 spaces wide
									// for the purposes of displaying score, rows left and level.

  private:
    Well    m_well;
    Screen  m_screen;
    int     m_level;
	int		m_score;
	int		m_rowsleft;
	int		m_T;		// this is the timer bound, which establishes the gravity (the higher this value
							// the lower the gravity.
};

#endif // GAME_INCLUDED
