/***********************************************************************
 * Source File:
 *    BOARD
 * Author:
 *    Daniel Carr
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
#include "iostream"
#include <cassert>
using namespace std;

/***********************************************
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8   R N B Q K B N R   8
 *   7   P P P P P P P P   7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2   p p p p p p p p   2
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
	// white pieces
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

	// black pieces
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

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
Piece& Board::operator[](const Position& pos)
{
	if (pos.isValid()) 
	{
		assert(0 <= pos.getCol() && pos.getCol() < 8);
		assert(0 <= pos.getRow() && pos.getRow() < 8);
		return *board[pos.getCol()][pos.getRow()];  // Return reference to the Piece at the specified position
	}
}
/**********************************************
* BOARD : GET CONST
*         Get a const piece from a given position.
***********************************************/
const Piece& Board::operator[](const Position& pos) const
{
	if (pos.isValid()) 
	{
		assert(0 <= pos.getCol() && pos.getCol() < 8);
		assert(0 <= pos.getRow() && pos.getRow() < 8);
		return *board[pos.getCol()][pos.getRow()];  // Return const reference to the Piece at the specified position
	}
}

//void Board::getMoves(set<Move>& moves, PieceType type) const
//{
//	switch (type)
//	{
//	case PAWN:
//		Pawn pawn;
//		pawn.getMoves(moves, *this);
//		break;
//	case KNIGHT:
//		Knight knight;
//		knight.getMoves(moves, *this);
//		break;
//	case BISHOP:
//		Bishop bishop;
//		bishop.getMoves(moves, *this);
//		break;
//	case ROOK:
//		Rook rook;
//		rook.getMoves(moves, *this);
//		break;
//	case QUEEN:
//		Queen queen;
//		queen.getMoves(moves, *this);
//		break;
//	case KING:
//		King king;
//		king.getMoves(moves, *this);
//		break;
//	default:
//		break;
//	}
//}

/***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position& posHover, const Position& posSelect) const
{
	pgout->drawBoard();
	pgout->drawHover(posHover);
	pgout->drawSelected(posSelect);
	/*set<Move> moves;
	Piece & = Piece;
		.getMoves(moves
	pgout->drawPossible(posSelect);*/
	for each (Piece* piece in board)
	{
		if ((piece != nullptr) && (piece->getType() != SPACE))
		{
			
			//if (piece->getPosition() == posSelect)
			//{
			//	set<Move> moves;
			//	getMoves(moves, piece->getType());
			//	set <Move> ::iterator it;
			//	for (it = moves.begin(); it != moves.end(); ++it)
			//	{
			//		pgout->drawPossible(it->getDest());
			//	}
			//	//pgout->drawPossible(posSelect);
			//}
			piece->display(pgout);
		}

	}
	// draw the hover piece
	/*if (posHover.isValid())
	{
		pgout->drawHover(posHover);
	}*/
}

/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0)
{
	// delete all the pieces
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			board[c][r] = nullptr;
		}
	}
	// reset the board
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
	// delete all the pieces
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			delete board[c][r];
			board[c][r] = nullptr;
		}
	}
}

/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{
	// make sure the board is well-formed
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (board[c][r] != nullptr)
			{
				assert(board[c][r]->getPosition().getCol() == c);
				assert(board[c][r]->getPosition().getRow() == r);
			}
		}
	}
}

/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(Move& move)
{
	// move the piece
	if ((move.getMoveType() == Move::CASTLE_QUEEN))
	{
		// move the king and the rook on the queen side
		const Position posSource = move.getSource();
		const Position posDest = move.getDest();
		const Position whiteKing(4,0);
		// white queen side castle
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
		// black queen side castle
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
	// move the king and the rook on the king side
	else if ((move.getMoveType() == Move::CASTLE_KING))
	{

		const Position posSource = move.getSource();
		const Position posDest = move.getDest();
		const Position whiteKing(4,0);
		// white king side castle
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
		// black king side castle
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
	// move the piece
	else if (move.getMoveType() == Move::MOVE)
	{
		// if the move is a promotion
		if (move.getPromote() != SPACE)
		{
			const Position posSource = move.getSource();
			const Position posDest = move.getDest();
			delete board[posSource.getCol()][posSource.getRow()];
			Queen* queen = new Queen(posDest, move.getIsWhite());
			Space* space = new Space(posSource);
			board[posSource.getCol()][posSource.getRow()] = queen;
			board[posDest.getCol()][posDest.getRow()] = space ;
		}
		// if the move is not a capture
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
		// if the move is a capture
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
	// if the move is an enpassant
	else if (move.getMoveType() == Move::ENPASSANT)
	{
		// if the move is a white enpassant
		if (move.getIsWhite() == true)
		{
			const Position posSource = move.getSource();
			const Position posDest = move.getDest();
			Piece* curMovePiece = board[posSource.getCol()][posSource.getRow()];
			Piece* destPiece = board[posDest.getCol()][posDest.getRow()];
			Space* space = new Space(posSource);
			Space* space2 = new Space(posSource);
			curMovePiece->setPosition(posDest);
			board[posDest.getCol()][posDest.getRow() - 1] = space2;
			board[posDest.getCol()][posDest.getRow()] = curMovePiece;
			board[posSource.getCol()][posSource.getRow()] = space;
		}
		// if the move is a black enpassant
		else
		{
			const Position posSource = move.getSource();
			const Position posDest = move.getDest();
			Piece* curMovePiece = board[posSource.getCol()][posSource.getRow()];
			Piece* destPiece = board[posDest.getCol()][posDest.getRow()];
			Space* space = new Space(posSource);
			Space* space2 = new Space(posSource);
			curMovePiece->setPosition(posDest);
			board[posDest.getCol()][posDest.getRow() + 1] = space2;
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

/**********************************************
 * BOARD EMPTY : DESTRUCTOR
 * Free up the space
 *********************************************/
BoardEmpty::~BoardEmpty()
{
	delete pSpace; // was delete pSpace;
}

/**********************************************
 * BOARD : GET CURRENT MOVE
 * Get the current move number
 *********************************************/
bool Board::whiteTurn() const
{
	// if the number of moves is even, it's white's turn
	if (numMoves % 2 == 0)
	{
		return true;
	}
	// if the number of moves is odd, it's
	else
	{
		return false;
	}
}