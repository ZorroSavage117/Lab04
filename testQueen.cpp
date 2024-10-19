/***********************************************************************
 * Source File:
 *    TEST QUEEN
 * Author:
 *    <your name here>
 * Summary:
 *    The unit tests for the queen
 ************************************************************************/

#include "testQueen.h"
#include "pieceQueen.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      




/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3     p p p           3
 * 2     p(q)p           2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_blocked()
{
	// Setup
	BoardEmpty board;
	Queen queen(2, 1, true);
	board.board[2][1] = &queen;
	White white1(PAWN);
	board.board[1][0] = &white1;
	White white2(PAWN);
	board.board[1][1] = &white2;
	White white3(PAWN);
	board.board[1][2] = &white3;
	White white4(PAWN);
	board.board[2][0] = &white4;
	White white5(PAWN);
	board.board[2][2] = &white5;
	White white6(PAWN);
	board.board[3][0] = &white6;
	White white7(PAWN);
	board.board[3][1] = &white7;
	White white8(PAWN);
	board.board[3][2] = &white8;
	set <Move> moves;

	// Exercise
	queen.getMoves(moves, board);

	// Verify
	assertUnit(moves.size() == 0);  // many possible moves

	// Teardown
	board.board[2][1] = nullptr; // white queen
	board.board[1][0] = nullptr; // white pawn
	board.board[1][1] = nullptr; // white pawn
	board.board[1][2] = nullptr; // white pawn
	board.board[2][0] = nullptr; // white pawn
	board.board[2][2] = nullptr; // white pawn
	board.board[3][0] = nullptr; // white pawn
	board.board[3][1] = nullptr; // white pawn
	board.board[3][2] = nullptr; // white pawn
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .         .   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   .   .   .         4
 * 3     . . .           3
 * 2   . .(q). . . . .   2
 * 1     . . .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToEnd()
{
	// Setup
	BoardEmpty board;
	Queen queen(2,1, true);
	board.board[2][1] = &queen;
	set <Move> moves;

	// Exercise
	queen.getMoves(moves, board);

	// Verify
	assertUnit(moves.size() == 23);  // many possible moves
	assertUnit(moves.find(Move("c2d1")) != moves.end());
	assertUnit(moves.find(Move("c2c1")) != moves.end());
	assertUnit(moves.find(Move("c2b1")) != moves.end());
	assertUnit(moves.find(Move("c2b2")) != moves.end());
	assertUnit(moves.find(Move("c2a2")) != moves.end());
	assertUnit(moves.find(Move("c2b3")) != moves.end());
	assertUnit(moves.find(Move("c2a4")) != moves.end());
	assertUnit(moves.find(Move("c2c3")) != moves.end());
	assertUnit(moves.find(Move("c2c4")) != moves.end());
	assertUnit(moves.find(Move("c2c5")) != moves.end());
	assertUnit(moves.find(Move("c2c6")) != moves.end());
	assertUnit(moves.find(Move("c2c7")) != moves.end());
	assertUnit(moves.find(Move("c2c8")) != moves.end());
	assertUnit(moves.find(Move("c2d3")) != moves.end());
	assertUnit(moves.find(Move("c2e4")) != moves.end());
	assertUnit(moves.find(Move("c2f5")) != moves.end());
	assertUnit(moves.find(Move("c2g6")) != moves.end());
	assertUnit(moves.find(Move("c2h7")) != moves.end());
	assertUnit(moves.find(Move("c2d2")) != moves.end());
	assertUnit(moves.find(Move("c2e2")) != moves.end());
	assertUnit(moves.find(Move("c2f2")) != moves.end());
	assertUnit(moves.find(Move("c2g2")) != moves.end());
	assertUnit(moves.find(Move("c2h2")) != moves.end());

	// Teardown
	board.board[2][1] = nullptr; // white queen
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .         p   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   p   .   .         4
 * 3     . . .           3
 * 2   p .(q). . . . p   2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToBlock()
{
	// Setup
	BoardEmpty board;
	Queen queen(2, 1, true);
	board.board[2][1] = &queen;
	White white1(PAWN);
	board.board[3][0] = &white1;
	White white2(PAWN);
	board.board[2][0] = &white2;
	White white3(PAWN);
	board.board[1][0] = &white3;
	White white4(PAWN);
	board.board[0][1] = &white4;
	White white5(PAWN);
	board.board[0][3] = &white5;
	White white6(PAWN);
	board.board[2][7] = &white6;
	White white7(PAWN);
	board.board[7][6] = &white7;
	White white8(PAWN);
	board.board[7][1] = &white8;
	set <Move> moves;

	// Exercise
	queen.getMoves(moves, board);

	// Verify
	assertUnit(moves.size() == 15);  // many possible moves
	assertUnit(moves.find(Move("c2b2")) != moves.end());
	assertUnit(moves.find(Move("c2b3")) != moves.end());
	assertUnit(moves.find(Move("c2c3")) != moves.end());
	assertUnit(moves.find(Move("c2c4")) != moves.end());
	assertUnit(moves.find(Move("c2c5")) != moves.end());
	assertUnit(moves.find(Move("c2c6")) != moves.end());
	assertUnit(moves.find(Move("c2c7")) != moves.end());
	assertUnit(moves.find(Move("c2d3")) != moves.end());
	assertUnit(moves.find(Move("c2e4")) != moves.end());
	assertUnit(moves.find(Move("c2f5")) != moves.end());
	assertUnit(moves.find(Move("c2g6")) != moves.end());
	assertUnit(moves.find(Move("c2d2")) != moves.end());
	assertUnit(moves.find(Move("c2e2")) != moves.end());
	assertUnit(moves.find(Move("c2f2")) != moves.end());
	assertUnit(moves.find(Move("c2g2")) != moves.end());
   
	// Teardown
	board.board[2][1] = nullptr; // white queen
	board.board[3][0] = nullptr; // white pawn
	board.board[2][0] = nullptr; // white pawn
	board.board[1][0] = nullptr; // white pawn
	board.board[0][1] = nullptr; // white pawn
	board.board[0][3] = nullptr; // white pawn
	board.board[2][7] = nullptr; // white pawn
	board.board[7][6] = nullptr; // white pawn
	board.board[7][1] = nullptr; // white pawn

}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .         P   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   P   .   .         4
 * 3     . . .           3
 * 2   P .(q). . . . P   2
 * 1     P P P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToCapture()
{
	// Setup
	BoardEmpty board;
	Queen queen(2, 1, false);
	board.board[2][1] = &queen;
	White white1(PAWN);
	board.board[3][0] = &white1;
	White white2(PAWN);
	board.board[2][0] = &white2;
	White white3(PAWN);
	board.board[1][0] = &white3;
	White white4(PAWN);
	board.board[0][1] = &white4;
	White white5(PAWN);
	board.board[0][3] = &white5;
	White white6(PAWN);
	board.board[2][7] = &white6;
	White white7(PAWN);
	board.board[7][6] = &white7;
	White white8(PAWN);
	board.board[7][1] = &white8;
	set <Move> moves;

	// Exercise
	queen.getMoves(moves, board);

	// Verify
	assertUnit(moves.size() == 23);  // many possible moves
	assertUnit(moves.find(Move("c2d1p")) != moves.end());
	assertUnit(moves.find(Move("c2c1p")) != moves.end());
	assertUnit(moves.find(Move("c2b1p")) != moves.end());
	assertUnit(moves.find(Move("c2b2")) != moves.end());
	assertUnit(moves.find(Move("c2a2p")) != moves.end());
	assertUnit(moves.find(Move("c2b3")) != moves.end());
	assertUnit(moves.find(Move("c2a4p")) != moves.end());
	assertUnit(moves.find(Move("c2c3")) != moves.end());
	assertUnit(moves.find(Move("c2c4")) != moves.end());
	assertUnit(moves.find(Move("c2c5")) != moves.end());
	assertUnit(moves.find(Move("c2c6")) != moves.end());
	assertUnit(moves.find(Move("c2c7")) != moves.end());
	assertUnit(moves.find(Move("c2c8p")) != moves.end());
	assertUnit(moves.find(Move("c2d3")) != moves.end());
	assertUnit(moves.find(Move("c2e4")) != moves.end());
	assertUnit(moves.find(Move("c2f5")) != moves.end());
	assertUnit(moves.find(Move("c2g6")) != moves.end());
	assertUnit(moves.find(Move("c2h7p")) != moves.end());
	assertUnit(moves.find(Move("c2d2")) != moves.end());
	assertUnit(moves.find(Move("c2e2")) != moves.end());
	assertUnit(moves.find(Move("c2f2")) != moves.end());
	assertUnit(moves.find(Move("c2g2")) != moves.end());
	assertUnit(moves.find(Move("c2h2p")) != moves.end());

	// Teardown
	board.board[2][1] = nullptr; // white queen
	board.board[3][0] = nullptr; // white pawn
	board.board[2][0] = nullptr; // white pawn
	board.board[1][0] = nullptr; // white pawn
	board.board[0][1] = nullptr; // white pawn
	board.board[0][3] = nullptr; // white pawn
	board.board[2][7] = nullptr; // white pawn
	board.board[7][6] = nullptr; // white pawn
	board.board[7][1] = nullptr; // white pawn
}


/*************************************
 * GET TYPE : queen
 * Input:
 * Output: QUEEN
 **************************************/
void TestQueen::getType()
{
	// Setup
	Queen queen(3, 0, true);

	// Verify
	assertUnit(queen.getType() == PieceType::QUEEN);
}