#include "Piece.h"
#include "UserInterface.h"
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include "Well.h"

Piece::Piece(int type, Well* well)
	: m_or(0), m_col(3), m_row(0), m_type(type), m_well(well)
{
	switch (type)
	{
	case PIECE_I:	// Piece I

		piece0[0][0] = ' '; piece0[0][1] = ' '; piece0[0][2] = ' '; piece0[0][3] = ' ';
		piece0[1][0] = '#'; piece0[1][1] = '#'; piece0[1][2] = '#'; piece0[1][3] = '#';
		piece0[2][0] = ' '; piece0[2][1] = ' '; piece0[2][2] = ' '; piece0[2][3] = ' ';
		piece0[3][0] = ' '; piece0[3][1] = ' '; piece0[3][2] = ' '; piece0[3][3] = ' ';

		piece1[0][0] = ' '; piece1[0][1] = '#'; piece1[0][2] = ' '; piece1[0][3] = ' ';
		piece1[1][0] = ' '; piece1[1][1] = '#'; piece1[1][2] = ' '; piece1[1][3] = ' ';
		piece1[2][0] = ' '; piece1[2][1] = '#'; piece1[2][2] = ' '; piece1[2][3] = ' ';
		piece1[3][0] = ' '; piece1[3][1] = '#'; piece1[3][2] = ' '; piece1[3][3] = ' ';

		break;

	case PIECE_L:	// Piece L

		piece0[0][0] = ' '; piece0[0][1] = ' '; piece0[0][2] = ' '; piece0[0][3] = ' ';
		piece0[1][0] = '#'; piece0[1][1] = '#'; piece0[1][2] = '#'; piece0[1][3] = ' ';
		piece0[2][0] = '#'; piece0[2][1] = ' '; piece0[2][2] = ' '; piece0[2][3] = ' ';
		piece0[3][0] = ' '; piece0[3][1] = ' '; piece0[3][2] = ' '; piece0[3][3] = ' ';

		piece1[0][0] = ' '; piece1[0][1] = '#'; piece1[0][2] = '#'; piece1[0][3] = ' ';
		piece1[1][0] = ' '; piece1[1][1] = ' '; piece1[1][2] = '#'; piece1[1][3] = ' ';
		piece1[2][0] = ' '; piece1[2][1] = ' '; piece1[2][2] = '#'; piece1[2][3] = ' ';
		piece1[3][0] = ' '; piece1[3][1] = ' '; piece1[3][2] = ' '; piece1[3][3] = ' ';

		piece2[0][0] = ' '; piece2[0][1] = ' '; piece2[0][2] = ' '; piece2[0][3] = ' ';
		piece2[1][0] = ' '; piece2[1][1] = ' '; piece2[1][2] = '#'; piece2[1][3] = ' ';
		piece2[2][0] = '#'; piece2[2][1] = '#'; piece2[2][2] = '#'; piece2[2][3] = ' ';
		piece2[3][0] = ' '; piece2[3][1] = ' '; piece2[3][2] = ' '; piece2[3][3] = ' ';

		piece3[0][0] = ' '; piece3[0][1] = ' '; piece3[0][2] = ' '; piece3[0][3] = ' ';
		piece3[1][0] = ' '; piece3[1][1] = '#'; piece3[1][2] = ' '; piece3[1][3] = ' ';
		piece3[2][0] = ' '; piece3[2][1] = '#'; piece3[2][2] = ' '; piece3[2][3] = ' ';
		piece3[3][0] = ' '; piece3[3][1] = '#'; piece3[3][2] = '#'; piece3[3][3] = ' ';

		break;

	case PIECE_J:	// Piece J

		piece0[0][0] = ' '; piece0[0][1] = ' '; piece0[0][2] = ' '; piece0[0][3] = ' ';
		piece0[1][0] = ' '; piece0[1][1] = '#'; piece0[1][2] = '#'; piece0[1][3] = '#';
		piece0[2][0] = ' '; piece0[2][1] = ' '; piece0[2][2] = ' '; piece0[2][3] = '#';
		piece0[3][0] = ' '; piece0[3][1] = ' '; piece0[3][2] = ' '; piece0[3][3] = ' ';

		piece1[0][0] = ' '; piece1[0][1] = ' '; piece1[0][2] = ' '; piece1[0][3] = ' ';
		piece1[1][0] = ' '; piece1[1][1] = ' '; piece1[1][2] = '#'; piece1[1][3] = ' ';
		piece1[2][0] = ' '; piece1[2][1] = ' '; piece1[2][2] = '#'; piece1[2][3] = ' ';
		piece1[3][0] = ' '; piece1[3][1] = '#'; piece1[3][2] = '#'; piece1[3][3] = ' ';

		piece2[0][0] = ' '; piece2[0][1] = ' '; piece2[0][2] = ' '; piece2[0][3] = ' ';
		piece2[1][0] = ' '; piece2[1][1] = '#'; piece2[1][2] = ' '; piece2[1][3] = ' ';
		piece2[2][0] = ' '; piece2[2][1] = '#'; piece2[2][2] = '#'; piece2[2][3] = '#';
		piece2[3][0] = ' '; piece2[3][1] = ' '; piece2[3][2] = ' '; piece2[3][3] = ' ';

		piece3[0][0] = ' '; piece3[0][1] = '#'; piece3[0][2] = '#'; piece3[0][3] = ' ';
		piece3[1][0] = ' '; piece3[1][1] = '#'; piece3[1][2] = ' '; piece3[1][3] = ' ';
		piece3[2][0] = ' '; piece3[2][1] = '#'; piece3[2][2] = ' '; piece3[2][3] = ' ';
		piece3[3][0] = ' '; piece3[3][1] = ' '; piece3[3][2] = ' '; piece3[3][3] = ' ';

		break;

	case PIECE_T:	// Piece T

		piece0[0][0] = ' '; piece0[0][1] = '#'; piece0[0][2] = ' '; piece0[0][3] = ' ';
		piece0[1][0] = '#'; piece0[1][1] = '#'; piece0[1][2] = '#'; piece0[1][3] = ' ';
		piece0[2][0] = ' '; piece0[2][1] = ' '; piece0[2][2] = ' '; piece0[2][3] = ' ';
		piece0[3][0] = ' '; piece0[3][1] = ' '; piece0[3][2] = ' '; piece0[3][3] = ' ';

		piece1[0][0] = ' '; piece1[0][1] = '#'; piece1[0][2] = ' '; piece1[0][3] = ' ';
		piece1[1][0] = ' '; piece1[1][1] = '#'; piece1[1][2] = '#'; piece1[1][3] = ' ';
		piece1[2][0] = ' '; piece1[2][1] = '#'; piece1[2][2] = ' '; piece1[2][3] = ' ';
		piece1[3][0] = ' '; piece1[3][1] = ' '; piece1[3][2] = ' '; piece1[3][3] = ' ';

		piece2[0][0] = ' '; piece2[0][1] = ' '; piece2[0][2] = ' '; piece2[0][3] = ' ';
		piece2[1][0] = '#'; piece2[1][1] = '#'; piece2[1][2] = '#'; piece2[1][3] = ' ';
		piece2[2][0] = ' '; piece2[2][1] = '#'; piece2[2][2] = ' '; piece2[2][3] = ' ';
		piece2[3][0] = ' '; piece2[3][1] = ' '; piece2[3][2] = ' '; piece2[3][3] = ' ';

		piece3[0][0] = ' '; piece3[0][1] = '#'; piece3[0][2] = ' '; piece3[0][3] = ' ';
		piece3[1][0] = '#'; piece3[1][1] = '#'; piece3[1][2] = ' '; piece3[1][3] = ' ';
		piece3[2][0] = ' '; piece3[2][1] = '#'; piece3[2][2] = ' '; piece3[2][3] = ' ';
		piece3[3][0] = ' '; piece3[3][1] = ' '; piece3[3][2] = ' '; piece3[3][3] = ' ';

		break;

	case PIECE_O:	// Piece O

		piece0[0][0] = '#'; piece0[0][1] = '#'; piece0[0][2] = ' '; piece0[0][3] = ' ';
		piece0[1][0] = '#'; piece0[1][1] = '#'; piece0[1][2] = ' '; piece0[1][3] = ' ';
		piece0[2][0] = ' '; piece0[2][1] = ' '; piece0[2][2] = ' '; piece0[2][3] = ' ';
		piece0[3][0] = ' '; piece0[3][1] = ' '; piece0[3][2] = ' '; piece0[3][3] = ' ';

		break;

	case PIECE_S:	// Piece S

		piece0[0][0] = ' '; piece0[0][1] = ' '; piece0[0][2] = ' '; piece0[0][3] = ' ';
		piece0[1][0] = ' '; piece0[1][1] = '#'; piece0[1][2] = '#'; piece0[1][3] = ' ';
		piece0[2][0] = '#'; piece0[2][1] = '#'; piece0[2][2] = ' '; piece0[2][3] = ' ';
		piece0[3][0] = ' '; piece0[3][1] = ' '; piece0[3][2] = ' '; piece0[3][3] = ' ';

		piece1[0][0] = ' '; piece1[0][1] = '#'; piece1[0][2] = ' '; piece1[0][3] = ' ';
		piece1[1][0] = ' '; piece1[1][1] = '#'; piece1[1][2] = '#'; piece1[1][3] = ' ';
		piece1[2][0] = ' '; piece1[2][1] = ' '; piece1[2][2] = '#'; piece1[2][3] = ' ';
		piece1[3][0] = ' '; piece1[3][1] = ' '; piece1[3][2] = ' '; piece1[3][3] = ' ';

		break;

	case PIECE_Z:	// Piece Z

		piece0[0][0] = ' '; piece0[0][1] = ' '; piece0[0][2] = ' '; piece0[0][3] = ' ';
		piece0[1][0] = '#'; piece0[1][1] = '#'; piece0[1][2] = ' '; piece0[1][3] = ' ';
		piece0[2][0] = ' '; piece0[2][1] = '#'; piece0[2][2] = '#'; piece0[2][3] = ' ';
		piece0[3][0] = ' '; piece0[3][1] = ' '; piece0[3][2] = ' '; piece0[3][3] = ' ';

		piece1[0][0] = ' '; piece1[0][1] = ' '; piece1[0][2] = '#'; piece1[0][3] = ' ';
		piece1[1][0] = ' '; piece1[1][1] = '#'; piece1[1][2] = '#'; piece1[1][3] = ' ';
		piece1[2][0] = ' '; piece1[2][1] = '#'; piece1[2][2] = ' '; piece1[2][3] = ' ';
		piece1[3][0] = ' '; piece1[3][1] = ' '; piece1[3][2] = ' '; piece1[3][3] = ' ';

		break;

	case PIECE_VAPOR:	// Piece Vapor

		piece0[0][0] = ' '; piece0[0][1] = '#'; piece0[0][2] = '#'; piece0[0][3] = ' ';
		piece0[1][0] = ' '; piece0[1][1] = ' '; piece0[1][2] = ' '; piece0[1][3] = ' ';
		piece0[2][0] = ' '; piece0[2][1] = ' '; piece0[2][2] = ' '; piece0[2][3] = ' ';
		piece0[3][0] = ' '; piece0[3][1] = ' '; piece0[3][2] = ' '; piece0[3][3] = ' ';

		break;

	case PIECE_FOAM:	// Piece Foam

		piece0[0][0] = ' '; piece0[0][1] = ' '; piece0[0][2] = ' '; piece0[0][3] = ' ';
		piece0[1][0] = ' '; piece0[1][1] = '#'; piece0[1][2] = ' '; piece0[1][3] = ' ';
		piece0[2][0] = ' '; piece0[2][1] = ' '; piece0[2][2] = ' '; piece0[2][3] = ' ';
		piece0[3][0] = ' '; piece0[3][1] = ' '; piece0[3][2] = ' '; piece0[3][3] = ' ';

		break;

	case PIECE_CRAZY:	// Piece Crazy

		piece0[0][0] = '#'; piece0[0][1] = ' '; piece0[0][2] = ' '; piece0[0][3] = '#';
		piece0[1][0] = ' '; piece0[1][1] = '#'; piece0[1][2] = '#'; piece0[1][3] = ' ';
		piece0[2][0] = ' '; piece0[2][1] = ' '; piece0[2][2] = ' '; piece0[2][3] = ' ';
		piece0[3][0] = ' '; piece0[3][1] = ' '; piece0[3][2] = ' '; piece0[3][3] = ' ';

		piece1[0][0] = ' '; piece1[0][1] = ' '; piece1[0][2] = ' '; piece1[0][3] = '#';
		piece1[1][0] = ' '; piece1[1][1] = ' '; piece1[1][2] = '#'; piece1[1][3] = ' ';
		piece1[2][0] = ' '; piece1[2][1] = ' '; piece1[2][2] = '#'; piece1[2][3] = ' ';
		piece1[3][0] = ' '; piece1[3][1] = ' '; piece1[3][2] = ' '; piece1[3][3] = '#';

		piece2[0][0] = ' '; piece2[0][1] = ' '; piece2[0][2] = ' '; piece2[0][3] = ' ';
		piece2[1][0] = ' '; piece2[1][1] = ' '; piece2[1][2] = ' '; piece2[1][3] = ' ';
		piece2[2][0] = ' '; piece2[2][1] = '#'; piece2[2][2] = '#'; piece2[2][3] = ' ';
		piece2[3][0] = '#'; piece2[3][1] = ' '; piece2[3][2] = ' '; piece2[3][3] = '#';

		piece3[0][0] = '#'; piece3[0][1] = ' '; piece3[0][2] = ' '; piece3[0][3] = ' ';
		piece3[1][0] = ' '; piece3[1][1] = '#'; piece3[1][2] = ' '; piece3[1][3] = ' ';
		piece3[2][0] = ' '; piece3[2][1] = '#'; piece3[2][2] = ' '; piece3[2][3] = ' ';
		piece3[3][0] = '#'; piece3[3][1] = ' '; piece3[3][2] = ' '; piece3[3][3] = ' ';

		break;

	default:
		cerr << "Piece construction failure" << endl;
		exit(1);
	}
}

void Piece::special() const
{
	switch (m_type)
	{
	case PIECE_VAPOR:
		for (int k = row() - 2; k != row() + 3 && k < WELLDEPTH - 1; k++)
			if (k >= 0)
			{
				m_well->add(' ', k, col() + 1);
				m_well->add(' ', k, col() + 2);
			}
		return;

	case PIECE_FOAM:
		foamexpand(m_row + 1, m_col + 1, m_row + 1, m_col + 1);
		return;

	default:
		return;
	}
}

void Piece::printpiece(Screen& screen, int x, int y) const
{
	switch (m_or)
	{
	case 0:
		for (int k = 0; k != 4; k++)
			for (int j = 0; j != 4; j++)
			{
					screen.gotoXY(x + j, y + k);
					screen.printChar(piece0[k][j]);
			}
			break;
		case 1:
			for (int k = 0; k != 4; k++)
				for (int j = 0; j != 4; j++)
				{
					screen.gotoXY(x + j, y + k);
					screen.printChar(piece1[k][j]);
				}
			break;
		case 2:
			for (int k = 0; k != 4; k++)
				for (int j = 0; j != 4; j++)
				{
					screen.gotoXY(x + j, y + k);
					screen.printChar(piece2[k][j]);
				}
			break;
		case 3:
			for (int k = 0; k != 4; k++)
				for (int j = 0; j != 4; j++)
				{
					screen.gotoXY(x + j, y + k);
					screen.printChar(piece3[k][j]);
				}
			break;
	}
}

bool Piece::rotate()
{
	if (m_type == PIECE_O || m_type == PIECE_FOAM || m_type == PIECE_VAPOR)
		return true;

	if (!nooverlap(rot))
		return false;

	if (m_type == PIECE_S || m_type == PIECE_Z || m_type == PIECE_I)
	{
		if (m_or)
			m_or = 0;
		else
			m_or = 1;
		printaftermove();
		return true;
	}
	
	else
	{
		m_or++;
		if (m_or == 4)
			m_or = 0;
		printaftermove();
		return true;
	}
}

bool Piece::movedown(bool print)
{
	if (!nooverlap(down))
	{
		solidify();
		return false;
	}

	m_row++;
	if (print)
		printaftermove();
	return true;
}

void Piece::solidify() const
{
	switch (m_or)
	{
	case 0:
		for (int k = 0; k != 4; k++)
			for (int j = 0; j != 4; j++)
				if (piece0[k][j] == '#')
					m_well->add('$', m_row + k, m_col + j);
		break;
	case 1:
		for (int k = 0; k != 4; k++)
			for (int j = 0; j != 4; j++)
				if (piece1[k][j] == '#')
					m_well->add('$', m_row + k, m_col + j);
		break;
	case 2:
		for (int k = 0; k != 4; k++)
			for (int j = 0; j != 4; j++)
				if (piece2[k][j] == '#')
					m_well->add('$', m_row + k, m_col + j);
		break;
	case 3:
		for (int k = 0; k != 4; k++)
			for (int j = 0; j != 4; j++)
				if (piece3[k][j] == '#')
					m_well->add('$', m_row + k, m_col + j);
		break;
	}
			
}

bool Piece::moveside(int direction)
{
	if (m_type == PIECE_CRAZY)	// makes sure to switch direction if crazy piece is drawn
		if (direction == lefty)
			direction = righty;
		else
			direction = lefty;

	if (direction == lefty)
	{
		if (!nooverlap(lefty))
			return false;
		m_col--;
		printaftermove();
		return true;
	}

	if (direction == righty)
	{
		if (!nooverlap(righty))
			return false;
		m_col++;
		printaftermove();
		return true;
	}

	cerr << "invalid side movement direction" << endl;
	return false;
}

bool Piece::instantdown()
{
	for (int dw = m_row; dw != m_row; dw++)		// clears piece print before instantdown moves the piece
		for (int ww = m_col; ww != m_col; ww++)
			if (m_well->wellspace(dw, ww) == ' ')
			{
				m_well->screen()->gotoXY(ww, dw);
				m_well->screen()->printChar(' ');
			}

	while (movedown(false))
		;

	return false;
}

bool Piece::nooverlap(int action) const
{
	int col = m_col;
	int row = m_row;
	int o = m_or;

	switch (action)		// adjusts parameters of orientation and position depending on the action
	{
	case 0:
		break;
	case 1:
		col--;
		break;
	case 2:
		col++;
		break;
	case 3:
		row++;
		break;
	case 4:
		if (m_type == PIECE_O || m_type == PIECE_FOAM || m_type == PIECE_VAPOR)
			break;
		if (m_type == PIECE_S || m_type == PIECE_Z || m_type == PIECE_I)
		{
			if (o)
				o = 0;
			else
				o = 1;
			break;
		}
		else
		{
			o++;
			if (o == 4)
				o = 0;
			break;
		}
	default:
		cerr << "Invalid action" << endl;
		break;
	}
	
	switch (o)	// checks for given orientation
	{
	case 0:
		for (int kp = 0, kw = row; kp != 4; kp++, kw++)
			for (int jp = 0, jw = col; jp != 4; jp++, jw++)
				if (m_well->wellspace(kw, jw) != ' ' && piece0[kp][jp] == '#')
					return false;
		break;
	case 1:
		for (int kp = 0, kw = row; kp != 4; kp++, kw++)
			for (int jp = 0, jw = col; jp != 4; jp++, jw++)
				if (m_well->wellspace(kw, jw) != ' ' && piece1[kp][jp] == '#')
					return false;
		break;
	case 2:
		for (int kp = 0, kw = row; kp != 4; kp++, kw++)
			for (int jp = 0, jw = col; jp != 4; jp++, jw++)
				if (m_well->wellspace(kw, jw) != ' ' && piece2[kp][jp] == '#')
					return false;
		break;
	case 3:
		for (int kp = 0, kw = row; kp != 4; kp++, kw++)
			for (int jp = 0, jw = col; jp != 4; jp++, jw++)
				if (m_well->wellspace(kw, jw) != ' ' && piece3[kp][jp] == '#')
					return false;
		break;
	default:
		cerr << "Invalid orientation error" << endl;
		break;
	}

	return true;
}

int Piece::row() const
{
	return m_row;
}

int Piece::col() const
{
	return m_col;
}

Well* Piece::well() const
{
	return m_well;
}

void Piece::printaftermove(bool spawn)
{
	if (!spawn)			// if the piece is not spawning for the first time
	{
		for (int dw = m_row - 1; dw != m_row + 4; dw++)		// first clears where the piece was printed
			for (int ww = m_col - 1; ww != m_col + 5; ww++)
				if (m_well->wellspace(dw, ww) == ' ')
				{
					m_well->screen()->gotoXY(ww, dw);
					m_well->screen()->printChar(' ');
				}
	}

	switch (m_or)		// this reprints the piece after it has moved
	{
	case 0:
		for (int k = 0; k != 4; k++)
			for (int j = 0; j != 4; j++)
				if (piece0[k][j] == '#')
				{
					m_well->screen()->gotoXY(m_col + j, m_row + k);
					m_well->screen()->printChar('#');
				}
		break;
	case 1:
		for (int k = 0; k != 4; k++)
			for (int j = 0; j != 4; j++)
				if (piece1[k][j] == '#')
				{
					m_well->screen()->gotoXY(m_col + j, m_row + k);
					m_well->screen()->printChar('#');
				}
		break;
	case 2:
		for (int k = 0; k != 4; k++)
			for (int j = 0; j != 4; j++)
				if (piece2[k][j] == '#')
				{
					m_well->screen()->gotoXY(m_col + j, m_row + k);
					m_well->screen()->printChar('#');
				}
		break;
	case 3:
		for (int k = 0; k != 4; k++)
			for (int j = 0; j != 4; j++)
				if (piece3[k][j] == '#')
				{
					m_well->screen()->gotoXY(m_col + j, m_row + k);
					m_well->screen()->printChar('#');
				}
		break;
	default:
		cerr << "Invalid orientation error" << endl;
		break;
	}

	m_well->screen()->gotoXY(78, 23);		// same values as const away_x & away_y, but for the sake of
											// one instance it's more efficient to just input the values
											// rather than deal with importing the values from Game.cpp
	return;
}

void Piece::foamexpand(int sr, int sc, int cr, int cc) const
{
	well()->add('*', cr, cc);
	if (well()->wellspace(cr + 1, cc) == ' ' && cr + 1 <= sr + 2)
		foamexpand(sr, sc, cr + 1, cc);
	if (well()->wellspace(cr - 1, cc) == ' ' && cr - 1 >= sr - 2)
		foamexpand(sr, sc, cr - 1, cc);
	if (well()->wellspace(cr, cc + 1) == ' ' && cc + 1 <= sc + 2)
		foamexpand(sr, sc, cr, cc + 1);
	if (well()->wellspace(cr, cc - 1) == ' ' && cc - 1 >= sc - 2)
		foamexpand(sr, sc, cr, cc - 1);
	return;
}