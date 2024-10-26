/***********************************************************************
 * Header File:
 *    PAWN
 * Author:
*    Daniel Carr
 * Summary:
 *    The PAWN class
 ************************************************************************/

#pragma once

#include "piece.h"
#include "uiDraw.h"

 /***************************************************
  * PAWN
  * The pawn, aka the "Foot Solider"
  ***************************************************/
class Pawn : public Piece
{
public:
	Pawn() { position = 0xff; fWhite = true; nMoves = 0; lastMove = 0; }
	Pawn(const Position& pos, bool isWhite) : Piece(9, 9) { this->position = pos; fWhite = isWhite; nMoves = 0; lastMove = 0; }
	Pawn(int c, int r, bool isWhite) : Piece(9, 9) { this->position.set(c, r); fWhite = isWhite; nMoves = 0; lastMove = 0; }
	Pawn(const Piece& piece) { this->position = piece.getPosition(); this->fWhite = piece.isWhite(); this->nMoves = piece.getNMoves(); }
	~Pawn() { }
	const Piece& operator = (const Piece& rhs) { this->position = rhs.getPosition(); this->fWhite = rhs.isWhite(); this->nMoves = rhs.getNMoves(); return *this; }
	bool isWhite() { return fWhite; }
	int getNmoves() { return nMoves; }
	void setNMoves(int n) { nMoves = n; }
	int getLastMove() { return lastMove; }
	PieceType getType()            const { return PAWN; }
	void display(ogstream* pgout) const { pgout->drawPawn(position, !fWhite); }
	bool operator == (PieceType pt) const { if (getType() == pt) return true;  else return false; }
	bool operator != (PieceType pt) const { if (getType() != pt) return true;  else return false; }
	bool isMoved() { if (nMoves > 0) return true; else return false; }
	bool justMoved(int currentMove) { if (currentMove - 1 == lastMove) return true; else return false; }
	void setLastMove(int currentMove) { lastMove = currentMove; nMoves += 1; }
	void getMoves(set <Move>& moves, const Board& board) const;
};