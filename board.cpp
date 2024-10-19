/***********************************************************************
 * Source File:
 *    BOARD
 * Author:
 *    <your name here>
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/

#include "board.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include "pieceRook.h"
#include "pieceBishop.h"
#include "pieceQueen.h"
#include "pieceKing.h"
#include "piecePawn.h"
#include <cassert>
using namespace std;

/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8   R N B Q K B N R   8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1   r n b q k b n r   1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
	// free everything
	for (int r = 0; r < 8; r++)
		for (int c = 0; c < 8; c++)
			board[c][r] = nullptr;
	board[1][7] = new Knight(Position(1, 7), true);
	board[6][7] = new Knight(Position(6, 7), true);
	board[0][7] = new Rook(Position(0, 7), true);
	board[7][7] = new Rook(Position(7, 7), true);
	board[2][7] = new Bishop(Position(2, 7), true);
	board[5][7] = new Bishop(Position(5, 7), true);
	board[3][7] = new Queen(Position(3, 7), true);
	board[4][7] = new King(Position(4, 7), true);
	board[0][6] = new Pawn(Position(0, 6), true);
	board[1][6] = new Pawn(Position(1, 6), true);
	board[2][6] = new Pawn(Position(2, 6), true);
	board[3][6] = new Pawn(Position(3, 6), true);
	board[4][6] = new Pawn(Position(4, 6), true);
	board[5][6] = new Pawn(Position(5, 6), true);
	board[6][6] = new Pawn(Position(6, 6), true);
	board[7][6] = new Pawn(Position(7, 6), true);


	board[1][0] = new Knight(Position(1, 0), false);
	board[6][0] = new Knight(Position(6, 0), false);
	board[0][0] = new Rook(Position(0, 0), false);
	board[7][0] = new Rook(Position(7, 0), false);
	board[2][0] = new Bishop(Position(2, 0), false);
	board[5][0] = new Bishop(Position(5, 0), false);
	board[3][0] = new Queen(Position(3, 0), false);
	board[4][0] = new King(Position(4, 0), false);
	board[0][1] = new Pawn(Position(0, 1), false);
	board[1][1] = new Pawn(Position(1, 1), false);
	board[2][1] = new Pawn(Position(2, 1), false);
	board[3][1] = new Pawn(Position(3, 1), false);
	board[4][1] = new Pawn(Position(4, 1), false);
	board[5][1] = new Pawn(Position(5, 1), false);
	board[6][1] = new Pawn(Position(6, 1), false);
	board[7][1] = new Pawn(Position(7, 1), false);


}

// we really REALLY need to delete this. 
//Space space;

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
//const Piece& Board::operator [] (const Position& pos) const
//{
//   return space;
//}
//Piece& Board::operator [] (const Position& pos)
//{
//   return space;
//}
Piece& Board::operator[](const Position& pos) {

	if (pos.isValid()) {
		assert(0 <= pos.getCol() && pos.getCol() < 8);
		assert(0 <= pos.getRow() && pos.getRow() < 8);
		return *board[pos.getCol()][pos.getRow()];  // Return reference to the Piece at the specified position
	}

}
const Piece& Board::operator[](const Position& pos) const {
	if (pos.isValid()) {
		assert(0 <= pos.getCol() && pos.getCol() < 8);
		assert(0 <= pos.getRow() && pos.getRow() < 8);
		return *board[pos.getCol()][pos.getRow()];  // Return const reference to the Piece at the specified position
	}
}

/***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position& posHover, const Position& posSelect) const
{
	
	pgout->drawBoard();
	for each (Piece* piece in board)
	{
		if ((piece != nullptr) && (piece->getType() != SPACE))
		{
			
			piece->display(pgout);
		}
	}
}


/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{
	for (int r = 0; r < 8; r++)
		for (int c = 0; c < 8; c++)
			board[c][r] = nullptr;
	if (noreset == false)
	{
		reset();
	}
}


/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{

}


/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{

}


/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(Move& move)
{
	if ((move.getMoveType() == Move::CASTLE_QUEEN))
	{
		
		const Position posSource = move.getSource();
		const Position posDest = move.getDest();
		const Position whiteKing(4,0);
		if (posSource == whiteKing)
		{
			const Position posRook(3, 0);
			Piece* curMovePiece = board[posSource.getCol()][posSource.getRow()];
			Piece* rook = board[0][0];
			curMovePiece->setPosition(posDest);
			rook->setPosition(posRook);
			board[posDest.getCol()][posDest.getRow()] = curMovePiece;
			board[posRook.getCol()][posRook.getRow()] = rook;
			board[0][0] = nullptr;
			board[4][0] = nullptr;
		}
		else
		{
			const Position posRook(3, 7);
			Piece* curMovePiece = board[posSource.getCol()][posSource.getRow()];
			Piece* rook = board[0][7];
			curMovePiece->setPosition(posDest);
			rook->setPosition(posRook);
			board[posDest.getCol()][posDest.getRow()] = curMovePiece;
			board[posRook.getCol()][posRook.getRow()] = rook;
			board[0][7] = nullptr;
			board[4][7] = nullptr;
		}
	}
	if ((move.getMoveType() == Move::CASTLE_KING))
	{

		const Position posSource = move.getSource();
		const Position posDest = move.getDest();
		const Position whiteKing(0,4);
		if (posSource == whiteKing)
		{
			const Position posRook(5, 0);
			Piece* curMovePiece = board[posSource.getCol()][posSource.getRow()];
			Piece* rook = board[7][0];
			curMovePiece->setPosition(posDest);
			rook->setPosition(posRook);
			board[posDest.getCol()][posDest.getRow()] = curMovePiece;
			board[posRook.getCol()][posRook.getRow()] = rook;
			board[7][0] = nullptr;
			board[4][0] = nullptr;
		}
		else
		{
			const Position posRook(5, 7);
			Piece* curMovePiece = board[posSource.getCol()][posSource.getRow()];
			Piece* rook = board[7][7];
			curMovePiece->setPosition(posDest);
			rook->setPosition(posRook);
			board[posDest.getCol()][posDest.getRow()] = curMovePiece;
			board[posRook.getCol()][posRook.getRow()] = rook;
			board[7][7] = nullptr;
			board[4][7] = nullptr;
		}
	}
	else
	{
		// move the piece
		if (move.getCapture() == SPACE)
		{
			const Position posSource = move.getSource();
			const Position posDest = move.getDest();
			Piece* curMovePiece = board[posSource.getCol()][posSource.getRow()];
			Piece* destPiece = board[posDest.getCol()][posDest.getRow()];
			curMovePiece->setPosition(posDest);
			destPiece->setPosition(posSource);
			board[posDest.getCol()][posDest.getRow()] = curMovePiece;
			board[posSource.getCol()][posSource.getRow()] = destPiece;
		}
		else
		{
			const Position posSource = move.getSource();
			const Position posDest = move.getDest();
			Piece* curMovePiece = board[posSource.getCol()][posSource.getRow()];
			Piece* destPiece = board[posDest.getCol()][posDest.getRow()];
			Space* space = new Space(posSource);
			curMovePiece->setPosition(posDest);
			board[posDest.getCol()][posDest.getRow()] = curMovePiece;
			board[posSource.getCol()][posSource.getRow()] = space;
		}
	}
	// update number of moves
	numMoves++;
}

/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr)
{
	pSpace = new Space(0, 0);  // was pSpace = new Space;
}
BoardEmpty::~BoardEmpty()
{
	delete pSpace;
}