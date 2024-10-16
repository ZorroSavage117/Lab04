/***********************************************************************
 * Header File:
 *    KING
 * Author:
*    Daniel Carr
 * Summary:
 *    The KING class
 ************************************************************************/

#pragma once

#include "piece.h"
#include "uiDraw.h"

 /***************************************************
  * KING
  * The king, aka the "Cardnal hat"
  ***************************************************/
class King : public Piece
{
public:
	King() { position = 0xff; fWhite = true; nMoves = 0; lastMove = 0; }
	King(const Position& pos, bool isWhite) : Piece(9, 9) { position = pos; fWhite = isWhite; }
	King(int c, int r, bool isWhite) : Piece(9, 9) {
		position.set(c, r); fWhite = isWhite;
	}
	King(const Piece& piece) { this->position = piece.getPosition(); this->fWhite = piece.isWhite(); this->nMoves = piece.getNMoves(); }
	~King() { }
	const Piece& operator = (const Piece& rhs) { this->position = rhs.getPosition(); this->fWhite = rhs.isWhite(); this->nMoves = rhs.getNMoves(); return *this; }
	bool isWhite() { return fWhite; }
	int getNmoves() { return nMoves; }
	int getLastMove() { return lastMove; }
	PieceType getType()            const { return KING; }
	void display(ogstream* pgout) const { pgout->drawKing(position, fWhite); }
	bool operator == (PieceType pt) const { if (getType() == pt) return true;  else return false; }
	bool operator != (PieceType pt) const { if (getType() != pt) return true;  else return false; }
	bool isMoved() { if (nMoves > 0) return true; else return false; }
	bool justMoved(int currentMove) { if (currentMove - 1 == lastMove) return true; else return false; }
	void setLastMove(int currentMove) { lastMove = currentMove; nMoves += 1; }
	void getMoves(set <Move>& moves, const Board& board) const;
};