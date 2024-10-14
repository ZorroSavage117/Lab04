/***********************************************************************
 * Header File:
 *    KNIGHT
 * Author:
*    Arlo Jolley & Daniel Carr
 * Summary:
 *    The KNIGHT class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * KNIGHT
  * The knight, aka the "Horse"
  ***************************************************/
class Knight : public Piece
{
public:
    /*Knight(const Position& pos, bool isWhite) : Piece(10,10,true) { }
    Knight(int c, int r, bool isWhite) : Piece(10, 10, true) { }
    ~Knight() {                }
    PieceType getType()            const { return KNIGHT; }
    void getMoves(set <Move>& moves, const Board& board) const;
    void display(ogstream* pgout)  const;*/

	Knight() { position = 0xff; fWhite = true; nMoves = 0; lastMove = 0; }
	Knight(const Position& pos, bool isWhite) : Piece(9, 9) { this->position = pos; if (isWhite) { this->fWhite = true; } else { fWhite = false; } }
	Knight(int c, int r, bool isWhite) : Piece(9, 9) { this->position.set(c, r); /*Col(c); this->position.setRow(r);*/ if (isWhite) { this->fWhite = true; } else { fWhite = false; } }
	Knight(const Piece& piece) { this->position = piece.getPosition(); this->fWhite = piece.isWhite(); this->nMoves = piece.getNMoves(); }
	~Knight() { }
	const Piece& operator = (const Piece& rhs) { this->position = rhs.getPosition(); this->fWhite = rhs.isWhite(); this->nMoves = rhs.getNMoves(); return *this; }
	bool isWhite() { return fWhite; }
	int getNmoves() { return nMoves; }
	int getLastMove() { return lastMove; }
	PieceType getType()            const { return KNIGHT; }
	void display(ogstream* pgout) const;// {}
	bool operator == (PieceType pt) const { if (getType() == pt) return true;  else return false; }
	bool operator != (PieceType pt) const { if (getType() != pt) return true;  else return false; }
	bool isMoved() { if (nMoves > 0) return true; else return false; }
	bool justMoved(int currentMove) { if (currentMove - 1 == lastMove) return true; else return false; }
	void setLastMove(int currentMove) { lastMove = currentMove; nMoves += 1; }
   void getMoves(set <Move>& moves, const Board& board) const;
};