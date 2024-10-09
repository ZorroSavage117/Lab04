/***********************************************************************
* Header File :
*SPACE
* Author :
*<your name here>
* Summary :
*The space
************************************************************************/

#pragma once

#include "piece.h"

	class TestSpace;

/***************************************************
 * SPACES
 * A space is a trivial piece
 ***************************************************/
class Space : public Piece
{
	friend TestSpace;
public:
	Space() { position = 0xff; nMoves = 0; lastMove = 0; }
	Space(const Position& pos) : Piece(9, 9) { this->position = pos; }
	Space(int c, int r) : Piece(9, 9) { position = Position(c, r); }
	Space(const Piece& piece) { this->position = piece.getPosition(); this->nMoves = piece.getNMoves(); }
	~Space() { }
	const Piece& operator = (const Piece& rhs) { this->position = rhs.getPosition(); this->nMoves = rhs.getNMoves(); return *this; }
	int getNmoves() { return nMoves; }
	int getLastMove() { return lastMove; }
	PieceType getType()            const { return SPACE; }
	void display(ogstream* pgout)  const { assert(false); }
	bool operator == (PieceType pt) const { if (getType() == pt) return true;  else return false; }
	bool operator != (PieceType pt) const { if (getType() != pt) return true;  else return false; }
	bool isMoved() { if (nMoves > 0) return true; else return false; }
	bool justMoved(int currentMove) { if (currentMove - 1 == lastMove) return true; else return false; }
	void setLastMove(int currentMove) { lastMove = currentMove; nMoves += 1; }
};
