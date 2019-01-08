#include <iostream>
using namespace std;
#include "Game.h"
#include "Well.h"
#include "UserInterface.h"
#include <time.h>
#include <string>
#include <stdio.h>
#include <stack>

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

const int WELL_X = 0;
const int WELL_Y = 0;

const int PROMPT_Y = 20;
const int PROMPT_X = 0;

const int SCORE_X = 16;
const int SCORE_FIELD_X = 27;
const int SCORE_Y = 8;

const int ROWS_LEFT_X = 16;
const int ROWS_LEFT_FIELD_X = 27;
const int ROWS_LEFT_Y = 9;

const int LEVEL_X = 16;
const int LEVEL_FIELD_X = 27;
const int LEVEL_Y = 10;

const int NEXT_PIECE_TITLE_X = 16;
const int NEXT_PIECE_TITLE_Y = 3;

const int NEXT_PIECE_X = 16;
const int NEXT_PIECE_Y = 4;

const int PIECE_SPAWN_X = 3;
const int PIECE_SPAWN_Y = 0;

const int AWAY_X = 78;
const int AWAY_Y = 23;

Game::Game(int width, int height)
 : m_screen(SCREEN_WIDTH, SCREEN_HEIGHT), m_well(&m_screen), m_level(1), m_rowsleft(5), m_score(0), m_T(1000)
{
	srand(NULL);
}

void Game::play()
{
    m_well.display(WELL_X, WELL_Y);
    displayStatus();  //  score, rows left, level
    displayPrompt("Press the Enter key to begin playing Chetyris!");
    waitForEnter();  // [in UserInterface.h]

    for(;;)
    {
        if ( ! playOneLevel())
            break;
        displayPrompt("Good job!  Press the Enter key to start next level!");
        waitForEnter();

        m_level++;					// increment level
		m_rowsleft = 5 * m_level;	// set rows

		if (m_level < 10)			// adjust the gravity for next level
			m_T = 1000 - (100 * (m_level - 1));
		else
			m_T = 100;

		m_well.emptyWell();			// empmty the well
		m_well.display(WELL_X, WELL_Y);	// display the empty well for new use
    }
    displayPrompt("Game Over!  Press the Enter key to exit!");
    waitForEnter();
}

void Game::displayPrompt(std::string s)     
{
    m_screen.gotoXY(PROMPT_X, PROMPT_Y);
    m_screen.printStringClearLine(s);   // overwrites previous text
    m_screen.refresh();
	m_screen.gotoXY(AWAY_X, AWAY_Y);
}

void Game::displayStatus()
{
	m_screen.gotoXY(SCORE_X, SCORE_Y);
	m_screen.printString("Score:     ");
	m_screen.gotoXY(ROWS_LEFT_X, ROWS_LEFT_Y);
	m_screen.printString("Rows left: ");
	m_screen.gotoXY(LEVEL_X, LEVEL_Y);
	m_screen.printString("Level:     ");
	updatesr();
	updatelevel();

	return;
    // [Replace this with code to display the status.]
}

bool Game::playOneLevel()
{
	m_screen.gotoXY(NEXT_PIECE_TITLE_X, NEXT_PIECE_TITLE_Y);
	m_screen.printString("Next piece:");
	updatelevel();
	updatesr();

	if (dealdrop(m_well.queuefront()))
		return true;
	else
		return false;
}

void Game::updatesr()
{
	m_screen.gotoXY(SCORE_FIELD_X, SCORE_Y);
	m_screen.printStringClearLine(rjn(m_score));
	m_screen.gotoXY(ROWS_LEFT_FIELD_X, ROWS_LEFT_Y);
	m_screen.printStringClearLine(rjn(m_rowsleft));
	m_screen.gotoXY(AWAY_X, AWAY_Y);
}

void Game::updatelevel()
{
	m_screen.gotoXY(LEVEL_FIELD_X, LEVEL_Y);
	m_screen.printStringClearLine(rjn(m_level));
	m_screen.gotoXY(AWAY_X, AWAY_Y);
}

void Game::updatepiece()
{
	m_well.queuefront().printpiece(m_screen, NEXT_PIECE_TITLE_X, NEXT_PIECE_TITLE_Y+1);
	m_screen.gotoXY(AWAY_X, AWAY_Y);
}

bool Game::dealdrop(Piece x)	// Recrusive, it ultimately return true if win, false if not
{
	m_well.cyclequeue();	// cycles the random piece queue and updates the next piece
	updatepiece();
	char command = '\0';
	x.printaftermove(true);	// prints piece at top of well (spawn is true, because it is spawning)
	m_screen.gotoXY(AWAY_X, AWAY_Y);

	if (!x.nooverlap(spawn))	// checks whether the piece was printed over a part of the well
		return false;

	while (true)
	{
		Timer t;
		while (t.elapsed() < m_T)
			if (getCharIfAny(command))
				switch (command)
				{
				case 'a':
				case ARROW_LEFT:
					x.moveside(lefty);
					break;
				case 'd':
				case ARROW_RIGHT:
					x.moveside(righty);
					break;
				case 's':
				case ARROW_DOWN:
					if (!x.movedown())
						goto ass;
					t.start();
					break;
				case 'w':
				case ARROW_UP:
					x.rotate();
					break;
				case ' ':
					if (!x.instantdown())
						goto ass;
					break;
				case 'q':
				case 'Q':
					return false;
				default:
					break;
				}
		if (!x.movedown())	// if movedown fails, it means it's been added to well;
		{
			ass:;
			x.special();		// special action
			count_score_update(x);	// update the numbers
			m_well.display(WELL_X, WELL_Y);	// display well
			if (m_rowsleft < 1)		// if we've finished the level, we return true before removing the rows
				return true;
			m_well.removerows(x.row());		// remove rows and re-display the well
			m_well.display(WELL_X, WELL_Y);
			break;
		}
	}

	return dealdrop(m_well.queuefront());
}

void Game::count_score_update(Piece x)
{
	int gonnaremove = m_well.countremove(x.row());
	m_rowsleft -= gonnaremove;	// update the rowsleft
	if (m_rowsleft < 0)			// if negative make it equal 0
		m_rowsleft = 0;
	switch (gonnaremove)		// switch statement to properly award points
	{
	case 1: m_score += 100; break;
	case 2: m_score += 200; break;
	case 3: m_score += 400; break;
	case 4: m_score += 800; break;
	case 5: m_score += 1600; break;
	case 6: m_score += 3200; break; // although it shouldn't be possible, I just put in case
	}

	updatesr();
	return;
}

string Game::rjn(int x) const		// simply convert an int to a 7 space right justified string for printing
									// purposes
{
	if (x == 0)
		return "       0";

	char digits[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	stack<char> number;

	while (x != 0)
	{
		number.push(digits[x % 10]);
		x /= 10;
	}

	while (number.size() < 8)
		number.push(' ');

	string RJN;
	while (!number.empty())
	{
		RJN += number.top();
		number.pop();
	}

	return RJN;
}
