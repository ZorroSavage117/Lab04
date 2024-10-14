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
#include <cassert>
using namespace std;

/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     N         N     8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1     n         n     1
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

	board[1][0] = new Knight(Position(1, 0), false);
	board[6][0] = new Knight(Position(6, 0), false);
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