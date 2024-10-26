/***********************************************************************
 * Header File:
 *    ROOK
 * Author:
*    Arlo Jolley & Daniel Carr
 * Summary:
 *    The ROOK class
 ************************************************************************/

#pragma once

#include "piece.h"
#include "uiDraw.h"

 /***************************************************
  * ROOK
  * The rook, aka the "Cardnal hat"
  ***************************************************/
class Rook : public Piece
{
public:
	Rook() { position = 0xff; fWhite = true; nMoves = 0; lastMove = 0; }
	Rook(const Position& pos, bool isWhite) : Piece(9, 9) { position = pos; fWhite = isWhite; nMoves = 0; lastMove = 0;}
	Rook(int c, int r, bool isWhite) : Piece(9, 9) {
		position.set(c, r); fWhite = isWhite; nMoves = 0; lastMove = 0;
	}
	Rook(const Piece& piece) { this->position = piece.getPosition(); this->fWhite = piece.isWhite(); this->nMoves = piece.getNMoves(); }
	~Rook() { }
	const Piece& operator = (const Piece& rhs) { this->position = rhs.getPosition(); this->fWhite = rhs.isWhite(); this->nMoves = rhs.getNMoves(); return *this; }
	bool isWhite() { return fWhite; }
	int getNmoves() { return nMoves; }
	int getLastMove() { return lastMove; }
	PieceType getType()            const { return ROOK; }
	void display(ogstream* pgout) const { pgout->drawRook(position, !fWhite); }
	bool operator == (PieceType pt) const { if (getType() == pt) return true;  else return false; }
	bool operator != (PieceType pt) const { if (getType() != pt) return true;  else return false; }
	bool isMoved() { if (nMoves > 0) return true; else return false; }
	bool justMoved(int currentMove) { if (currentMove - 1 == lastMove) return true; else return false; }
	void setLastMove(int currentMove) { lastMove = currentMove; nMoves += 1; }
	void getMoves(set <Move>& moves, const Board& board) const;
};