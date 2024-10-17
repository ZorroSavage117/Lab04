/***********************************************************************
 * Source File:
 *    TEST PAWN
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the pawn
 ************************************************************************/

#include "testPawn.h"
#include "piecePawn.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      



 /*************************************
  * GET MOVES TEST Simple
  * White pawn in the middle of the board: b4
  *
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5     .               5
  * 4    (p)              4
  * 3                     3
  * 2                     2
  * 1                     1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestPawn::getMoves_simpleWhite()
{
	// Setup
	BoardEmpty board;
	Pawn pawn(1, 3, true);
	pawn.setNMoves(1);
	board.board[1][3] = &pawn;
	set <Move> moves;

	// Exercise
	pawn.getMoves(moves, board);

	// Verify
	assertUnit(moves.size() == 1);  // many possible moves
	assertUnit(moves.find(Move("b4b5")) != moves.end());

	// Teardown
	board.board[1][3] = nullptr; // white pawn
}

/*************************************
 * GET MOVES TEST Simple
 * Black pawn in the middle of the board: b4
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4    (P)              4
 * 3     .               3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_simpleBlack()
{
	// Setup
	BoardEmpty board;
	Pawn pawn(1, 3, false);
	pawn.setNMoves(1);
	board.board[1][3] = &pawn;
	set <Move> moves;

	// Exercise
	pawn.getMoves(moves, board);

	// Verify
	assertUnit(moves.size() == 1);  // many possible moves
	assertUnit(moves.find(Move("b4b3")) != moves.end());

	// Teardown
	board.board[1][3] = nullptr; // black pawn
}


/*************************************
 * GET MOVES TEST InitialAdvance
 * White pawn initial advance
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4     .               4
 * 3     .               3
 * 2    (p)              2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceWhite()
{
	// Setup
	BoardEmpty board;
	Pawn pawn(1, 1, true);
	board.board[1][1] = &pawn;
	set <Move> moves;

	// Exercise
	pawn.getMoves(moves, board);

	// Verify
	assertUnit(moves.size() == 2);  // many possible moves
	assertUnit(moves.find(Move("b2b3")) != moves.end());
	assertUnit(moves.find(Move("b2b4")) != moves.end());

	// Teardown
	board.board[1][1] = nullptr; // white pawn
}

/*************************************
 * GET MOVES TEST InitialAdvance
 * Black pawn initial advance
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7      (P)            7
 * 6       .             6
 * 5       .             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceBlack()
{
	// Setup
	BoardEmpty board;
	Pawn pawn(2, 6, false);
	board.board[2][6] = &pawn;
	set <Move> moves;

	// Exercise
	pawn.getMoves(moves, board);

	// Verify
	assertUnit(moves.size() == 2);  // many possible moves
	assertUnit(moves.find(Move("c7c6")) != moves.end());
	assertUnit(moves.find(Move("c7c5")) != moves.end());

	// Teardown
	board.board[2][6] = nullptr; // white pawn
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move pawn to b6 and capture
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7   P P P             7
 * 6    (p)              6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureWhite()
{
	// Setup
	BoardEmpty board;
	Pawn pawn1(1, 5, true);
	board.board[1][5] = &pawn1;
	Pawn pawn2(0, 6, false);
	board.board[0][6] = &pawn2;
	Pawn pawn3(1, 6, false);
	pawn3.setNMoves(1);
	board.board[1][6] = &pawn3;
	Pawn pawn4(2, 6, false);
	board.board[2][6] = &pawn4;
	set <Move> moves;

	// Exercise
	pawn3.getMoves(moves, board);

	// Verify
	assertUnit(moves.size() == 1);  // many possible moves
	assertUnit(moves.find(Move("b7b6p")) != moves.end());

	// Teardown
	board.board[1][5] = nullptr;
	board.board[0][6] = nullptr;
	board.board[1][6] = nullptr;
	board.board[2][6] = nullptr;

}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move pawn to b6 and capture
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6    (P)              6
 * 5   p p p             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureBlack()
{
	// Setup
	BoardEmpty board;
	Pawn pawn1(1, 5, false);
	board.board[1][5] = &pawn1;
	Pawn pawn2(0, 4, true);
	board.board[0][4] = &pawn2;
	Pawn pawn3(1, 4, true);
	pawn3.setNMoves(1);
	board.board[1][4] = &pawn3;
	Pawn pawn4(2, 4, true);
	board.board[2][4] = &pawn4;
	set <Move> moves;

	// Exercise
	pawn3.getMoves(moves, board);

	// Verify
	assertUnit(moves.size() == 1);  // many possible moves
	assertUnit(moves.find(Move("b5b6p")) != moves.end());

	// Teardown
	board.board[1][5] = nullptr;
	board.board[0][4] = nullptr;
	board.board[1][4] = nullptr;
	board.board[2][4] = nullptr;
}

/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant b5a6E
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6   . P .             6
 * 5   P(p)P             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantWhite()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant f4g3E
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4           p(P)p     4
 * 3           . p .     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantBlack()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET MOVES TEST Promotion
 * Promotion: b6a7rQ
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   P . P             8
 * 7    (p)              7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionWhite()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET MOVES TEST Promotion
 * Promotion: e2d1rQ
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2          (P)        2
 * 1         r   r       1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionBlack()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET TYPE : pawn
 * Input:
 * Output: PAWN
 **************************************/
void TestPawn::getType()
{
	// Setup
	Pawn pawn(3, 0, true);

	// Verify
	assertUnit(pawn.getType() == PieceType::PAWN);
}

