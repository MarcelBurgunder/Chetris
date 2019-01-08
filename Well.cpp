#include "Well.h"
#include "UserInterface.h"

Well::Well(Screen* screen)
	: m_screen(screen), I(PIECE_I, this), L(PIECE_L, this), J(PIECE_J, this), T(PIECE_T, this),
		O(PIECE_O, this), S(PIECE_S, this), Z(PIECE_Z, this), Vapor(PIECE_VAPOR, this),
		Foam(PIECE_FOAM, this), Crazy(PIECE_CRAZY, this)
{
	emptyWell();

	for (int k = 0; k != 5; k++)
		switch (chooseRandomPieceType())
		{
		case PIECE_I:		m_next.push(I);		break;
		case PIECE_L:		m_next.push(L);		break;
		case PIECE_J:		m_next.push(J);		break;
		case PIECE_T:		m_next.push(T);		break;
		case PIECE_O:		m_next.push(O);		break;
		case PIECE_S:		m_next.push(S);		break;
		case PIECE_Z:		m_next.push(Z);		break;
		case PIECE_VAPOR:	m_next.push(Vapor);	break;
		case PIECE_FOAM:	m_next.push(Foam);	break;
		case PIECE_CRAZY:	m_next.push(Crazy); break;
		}
		
}

void Well::emptyWell()
{
	for (int k = 0; k != WELLDEPTH - 1; k++)
		for (int j = 1; j != WELLWIDTH - 1; j++)
			m_well[k][j] = ' ';
	for (int j = 0; j != WELLWIDTH; j++)
		m_well[WELLDEPTH - 1][j] = '@';
	for (int k = 0; k != WELLDEPTH - 1; k++)
	{
		m_well[k][0] = '@';
		m_well[k][WELLWIDTH - 1] = '@';
	}
	return;
}

void Well::add(char c, int dw, int ww)
{
	m_well[dw][ww] = c;
}

void Well::display(int x, int y) const
{
	for (int k = y; k != 19; k++)
		for (int j = x; j != 12; j++)
		{
			m_screen->gotoXY(j, k);
			m_screen->printChar(m_well[k][j]);
		}
		
	return;
}

Piece Well::queuefront()
{
	return m_next.front();
}

Screen* Well::screen() const
{
	return m_screen;
}

bool Well::cyclequeue()
{
	if (m_next.empty())
		return false;

	m_next.pop();
	switch (chooseRandomPieceType())
	{
	case PIECE_I:		m_next.push(I);		break;
	case PIECE_L:		m_next.push(L);		break;
	case PIECE_J:		m_next.push(J);		break;
	case PIECE_T:		m_next.push(T);		break;
	case PIECE_O:		m_next.push(O);		break;
	case PIECE_S:		m_next.push(S);		break;
	case PIECE_Z:		m_next.push(Z);		break;
	case PIECE_VAPOR:	m_next.push(Vapor);	break;
	case PIECE_FOAM:	m_next.push(Foam);	break;
	case PIECE_CRAZY:	m_next.push(Crazy); break;
	}

	return true;
}

void Well::removerows(int toprow)	// checks if filled, if it is, it moves everything down by one to there
{
	if (toprow == 0)	// necessary so we don't access the row above the well
						// in case it spawns at the top of well
		toprow++;

	for (int k = -1; k != 4; k++)	// necessary to make it -1, since we gotta check the row above the 4x4
									// bounding box in case that the foam piece fills a row above it's 4x4
									// bounding box
	{
		if (toprow + k >= WELLDEPTH - 1)
			return;
		if (rowfull(toprow + k))
			shiftallabove(toprow + k);
	}
}

char Well::wellspace(int dp, int dw) const
{
	return m_well[dp][dw];
}

bool Well::rowfull(int row) const
{
	for (int k = 0; k != WELLWIDTH; k++)
		if (m_well[row][k] == ' ')
			return false;
	return true;
}

bool Well::rowempty(int row) const
{
	for (int k = 0; k != WELLWIDTH; k++)
		if (m_well[row][k] != ' ' && m_well[row][k] != '@')
			return false;
	return true;
}

void Well::shiftallabove(int row)	
{
	if (!rowempty(row - 1))
	{
		for (int k = 1; k != WELLWIDTH - 1; k++)
			m_well[row][k] = m_well[row - 1][k];
		shiftallabove(row - 1);
	}
	else
	{
		for (int k = 1; k != WELLWIDTH - 1; k++)
			m_well[row][k] = ' ';
	}
	return;
}

int Well::countremove(int x) const
{
	if (x == 0)	// want to make sure the row above the 4x4 piece array isn't checked when the row = 0
		x++;

	int j = 0;
	for (int k = -1; k != 4 && x+k < WELLDEPTH-1; k++)	// k must be -1, since we must check the row
													// above the 4x4 bounding box when a foam tile is used
		if (rowfull(x + k))
			j++;
	return j;
}