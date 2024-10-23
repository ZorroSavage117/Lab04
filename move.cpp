/***********************************************************************
 * Source File:
 *    MOVE
 * Author:
 *    Arlo Jolley
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move()
{
	source = INVALID;
	dest = INVALID;
	promote = SPACE;
	capture = SPACE;
	moveType = MOVE_ERROR;
	isWhite = true;
	text = "";
}

/***************************************************
 * MOVE : NON-DEFAULT CONSTRUCTOR
 * Takes a string in Smith notation and a color
 ***************************************************/
Move::Move(string smith, bool white)
{
	source = smith.substr(0, 2);
	dest = smith.substr(2, 2);
	if (smith.length() > 4)
	{
		if (smith.length() == 5) // promote or capture
		{
			char action = smith[4];
			switch (action)
			{
			case 'p':
				promote = SPACE;
				capture = PAWN;
				moveType = MOVE;
				break;
			case 'n':
				promote = SPACE;
				capture = KNIGHT;
				moveType = MOVE;
				break;
			case 'b':
				promote = SPACE;
				capture = BISHOP;
				moveType = MOVE;
				break;
			case 'r':
				promote = SPACE;
				capture = ROOK;
				moveType = MOVE;
				break;
			case 'q':
				promote = SPACE;
				capture = QUEEN;
				moveType = MOVE;
				break;
			case 'k':  // place holder and end game condition
				promote = SPACE;
				capture = KING;
				moveType = MOVE;
				break;
			case 'c':
				promote = SPACE;
				capture = SPACE;
				moveType = CASTLE_KING;
				break;
			case 'C':
				promote = SPACE;
				capture = SPACE;
				moveType = CASTLE_QUEEN;
				break;
			case 'E':
				promote = SPACE;
				capture = PAWN;
				moveType = ENPASSANT;
				break;
			case 'N':
				promote = KNIGHT;
				capture = SPACE;
				moveType = MOVE;
				break;
			case 'B':
				promote = BISHOP;
				capture = SPACE;
				moveType = MOVE;
				break;
			case 'R':
				promote = ROOK;
				capture = SPACE;
				moveType = MOVE;
				break;
			case 'Q':
				promote = QUEEN;
				capture = SPACE;
				moveType = MOVE;
				break;
			default:
				promote = SPACE;
				capture = SPACE;
				moveType = MOVE_ERROR;
			}
		}
		else // capture and promote
		{
			string action = smith.substr(4, 2);
			if (action == "pQ" || action == "Qp")
			{
				promote = QUEEN;
				capture = PAWN;
				moveType = MOVE;
			}
			else if (action == "nQ" || action == "Qn")
			{
				promote = QUEEN;
				capture = KNIGHT;
				moveType = MOVE;
			}
			else if (action == "bQ" || action == "Qb")
			{
				promote = QUEEN;
				capture = BISHOP;
				moveType = MOVE;
			}
			else if (action == "rQ" || action == "Qr")
			{
				promote = QUEEN;
				capture = ROOK;
				moveType = MOVE;
			}
			else if (action == "qQ" || action == "Qq")
			{
				promote = QUEEN;
				capture = QUEEN;
				moveType = MOVE;
			}
		}
	}
	else // no promote or capture
	{
		promote = SPACE;
		capture = SPACE;
		moveType = MOVE;
	}
	isWhite = white;
	text = smith;
}

/***************************************************
 * MOVE : Getters and Setters
 ***************************************************/

 /**************************************************
 * Move::getSource
 * Returns the source position of the move
 * **************************************************/
Position Move::getSource()
{
	return source;
}

/**************************************************
* Move::setSource
* Sets the source position of the move
***************************************************/
void Move::setSource(Position s)
{
	source = s;
}

/**************************************************
* Move::getDest
* Returns the destination position of the move
* **************************************************/
Position Move::getDest()
{
	return dest;
}

/**************************************************
* Move::setDest
* Sets the destination position of the move
* **************************************************/
void Move::setDest(Position d)
{
	dest = d;
	//text += d;
}

/**************************************************
* Move::getPromote
* Returns the piece type to promote to
* **************************************************/
PieceType Move::getPromote()
{
	return promote;
}

/**************************************************
* Move::setPromote
* Sets the piece type to promote to
* **************************************************/
void Move::setPromote(PieceType pro)
{
	promote = pro;
}

/**************************************************
* Move::getCapture
* Returns the piece type to capture
* **************************************************/
PieceType Move::getCapture()
{
	return capture;
}

/**************************************************
* Move::setCapture
* Sets the piece type to capture
* **************************************************/
void Move::setCapture(PieceType cap)
{
	capture = cap;
}

/**************************************************
* Move::getMoveType
* Returns the type of move
* **************************************************/
Move::MoveType Move::getMoveType()
{
	return moveType;
}

/**************************************************
* Move::setMoveType
* Sets the type of move
* **************************************************/
void Move::setMoveType(MoveType m)
{
	moveType = m;
}

/**************************************************
* Move::getIsWhite
* Returns the color of the piece making the move
* **************************************************/
bool Move::getIsWhite()
{
	return isWhite;
}

/**************************************************
* Move::setIsWhite
* Sets the color of the piece making the move
* **************************************************/
void Move::setIsWhite(bool w)
{
	isWhite = w;
}

/**************************************************
* Move::getSmith
* Returns the move in Smith notation
* **************************************************/
string Move::getSmith() const
{
	return text;
}

/**************************************************
* Move::conv
* Converts a column number to a letter
* **************************************************/
char Move::conv(int col)
{
	switch (col + 1)
	{
	case 1:
		return 'a';
		break;
	case 2:
		return 'b';
		break;
	case 3:
		return 'c';
		break;
	case 4:
		return 'd';
		break;
	case 5:
		return 'e';
		break;
	case 6:
		return 'f';
		break;
	case 7:
		return 'g';
		break;
	case 8:
		return 'h';
		break;
	}
}

/**************************************************
* Move::getText
* Returns the move in Smith notation
* **************************************************/
string Move::getText(Position sour, Position des, MoveType type, PieceType cap, PieceType pro)
{
	string s;
	string d;
	string t;

	int sc = sour.getCol();
	int sr = sour.getRow();
	int dc = des.getCol();
	int dr = des.getRow();

	s = conv(sc) + to_string(sr + 1);
	d = conv(dc) + to_string(dr + 1);
	if (type == MOVE)
	{
		if (cap != SPACE && pro == SPACE)
		{
			switch (cap)
			{
			case PAWN:
				t = 'p';
				break;
			case KNIGHT:
				t = 'n';
				break;
			case BISHOP:
				t = 'b';
				break;
			case ROOK:
				t = 'r';
				break;
			case QUEEN:
				t = 'q';
				break;
			case KING:    //not posible
				t = 'k';
				break;
			}
		}
		else if (pro != SPACE)
		{
			switch (cap)
			{
			case PAWN:
				t = "pQ";
				break;
			case KNIGHT:
				t = "nQ";
				break;
			case BISHOP:
				t = "bQ";
				break;
			case ROOK:
				t = "rQ";
				break;
			case QUEEN:
				t = "qQ";
				break;
			case KING:    //not posible
				t = "kQ";
				break;
			case SPACE:
				t = 'Q';
				break;
			}
		}
	}
	else if (type == ENPASSANT)
	{
		t = 'E';
	}
	else if (type == CASTLE_KING)
	{
		t = 'c';
	}
	else if (type == CASTLE_QUEEN)
	{
		t = 'C';
	}


	text = s + d + t;
	//std::cout << "getText return:" << text << std::endl;  // debugging
	return text;
}

/**************************************************
* Move::setText
* Sets the move in Smith notation
* **************************************************/
void Move::setText(string smith)
{
	text = smith;
	source = smith.substr(0, 2);
	dest = smith.substr(2, 2);
	if (smith.length() > 4)
	{
		if (smith.length() == 5) // promote or capture
		{
			char action = smith[4];
			switch (action)
			{
			case 'p':
				promote = SPACE;
				capture = PAWN;
				moveType = MOVE;
				break;
			case 'n':
				promote = SPACE;
				capture = KNIGHT;
				moveType = MOVE;
				break;
			case 'b':
				promote = SPACE;
				capture = BISHOP;
				moveType = MOVE;
				break;
			case 'r':
				promote = SPACE;
				capture = ROOK;
				moveType = MOVE;
				break;
			case 'q':
				promote = SPACE;
				capture = QUEEN;
				moveType = MOVE;
				break;
			case 'k':  // place holder and end game condition
				promote = SPACE;
				capture = KING;
				moveType = MOVE;
				break;
			case 'c':
				promote = SPACE;
				capture = SPACE;
				moveType = CASTLE_KING;
				break;
			case 'C':
				promote = SPACE;
				capture = SPACE;
				moveType = CASTLE_QUEEN;
				break;
			case 'E':
				promote = SPACE;
				capture = PAWN;
				moveType = ENPASSANT;
				break;
			case 'N':
				promote = KNIGHT;
				capture = SPACE;
				moveType = MOVE;
				break;
			case 'B':
				promote = BISHOP;
				capture = SPACE;
				moveType = MOVE;
				break;
			case 'R':
				promote = ROOK;
				capture = SPACE;
				moveType = MOVE;
				break;
			case 'Q':
				promote = QUEEN;
				capture = SPACE;
				moveType = MOVE;
				break;
			default:
				promote = SPACE;
				capture = SPACE;
				moveType = MOVE_ERROR;
			}
		}
		else // capture and promote
		{
			string action = smith.substr(4, 2);
			if (action == "pQ" || action == "Qp")
			{
				promote = QUEEN;
				capture = PAWN;
				moveType = MOVE;
			}
			else if (action == "nQ" || action == "Qn")
			{
				promote = QUEEN;
				capture = KNIGHT;
				moveType = MOVE;
			}
			else if (action == "bQ" || action == "Qb")
			{
				promote = QUEEN;
				capture = BISHOP;
				moveType = MOVE;
			}
			else if (action == "rQ" || action == "Qr")
			{
				promote = QUEEN;
				capture = ROOK;
				moveType = MOVE;
			}
			else if (action == "qQ" || action == "Qq")
			{
				promote = QUEEN;
				capture = QUEEN;
				moveType = MOVE;
			}
		}
	}
	else // no promote or capture
	{
		promote = SPACE;
		capture = SPACE;
		moveType = MOVE;
	}
}

/**************************************************
* Move::letterFromPieceType
* Returns the letter representation of a piece type
* **************************************************/
char Move::letterFromPieceType(PieceType pt) const
{
	switch (pt) {
	case PAWN:    return 'p';
	case KNIGHT:  return 'n';
	case BISHOP:  return 'b';
	case ROOK:    return 'r';
	case QUEEN:   return 'q';
	case KING:    return 'k';
	default:      return ' ';
	}
}

/**************************************************
* Move::pieceTypeFromLetter
* Returns the piece type from a letter representation
* **************************************************/
PieceType Move::pieceTypeFromLetter(char letter) const
{
	switch (letter) {
	case 'p': return PAWN;
	case 'n': return KNIGHT;
	case 'b': return BISHOP;
	case 'r': return ROOK;
	case 'q': return QUEEN;
	case 'k': return KING;
	default:  return SPACE;
	}
}

/***************************************************
 * MOVE : Operators
 ***************************************************/

 /**************************************************
 * Move::operator==
 * compares the numbers of location known as start and dest
 * **************************************************/
bool Move::operator==(const Move& rhs) const // compares the numbers of location known as start and dest
{
	Position sor1;
	Position sor2;
	Position des1;
	Position des2;

	sor1 = source;
	des1 = dest;
	sor2 = rhs.source;
	des2 = rhs.dest;

	int sor1c = sor1.getCol();
	int sor1r = sor1.getRow();
	int sor2c = sor2.getCol();
	int sor2r = sor2.getRow();
	int des1c = des1.getCol();
	int des1r = des1.getRow();
	int des2c = des2.getCol();
	int des2r = des2.getRow();

	int sor1p = (sor1r * 8) + sor1c;
	int sor2p = (sor2r * 8) + sor2c;
	int des1p = (des1r * 8) + des1c;
	int des2p = (des2r * 8) + des2c;

	if (sor1p == sor2p && des1p == des2p)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**************************************************
* Move::operator<
* compares the numbers of location known as start and dest
* **************************************************/
bool Move::operator<(const Move& rhs) const
{
	Position sor1;
	Position sor2;
	Position des1;
	Position des2;

	sor1 = source;
	des1 = dest;
	sor2 = rhs.source;
	des2 = rhs.dest;

	int sor1c = sor1.getCol();
	int sor1r = sor1.getRow();
	int sor2c = sor2.getCol();
	int sor2r = sor2.getRow();
	int des1c = des1.getCol();
	int des1r = des1.getRow();
	int des2c = des2.getCol();
	int des2r = des2.getRow();

	int sor1p = (sor1r * 8) + sor1c;
	int sor2p = (sor2r * 8) + sor2c;
	int des1p = (des1r * 8) + des1c;
	int des2p = (des2r * 8) + des2c;

	if (sor1p < sor2p || des1p < des2p)
	{
		return true;
	}
	else
	{
		return false;
	}
}
