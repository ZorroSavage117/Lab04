/***********************************************************************
 * Header File:
 *    TEST MOVE
 * Author:
 *    Arlo Jolley
 * Summary:
 *    test the Move class
 ************************************************************************/


#include "testMove.h"
#include "move.h"
#include <cassert>

 /*************************************
  * Constructor : default
  * Input:
  * Output: source=INVALID
  *         dest  =INVALID
  **************************************/
void TestMove::constructor_default()
{
	Move move;
	assertUnit(move.getSource() == INVALID && move.getDest() == INVALID);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * CONSTRUCTOR : standard string move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::constructString_simple()
{
	Move move("e5e6");
	Position sourceOut(4, 4);
	Position destOut(4, 5);
	assertUnit(move.getSource() == sourceOut && move.getDest() == destOut && move.getMoveType() == Move::MOVE);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * READ simple move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::read_simple()
{
	Move move("e5e6", true);
	Position sourceOut(4, 4);
	Position destOut(4, 5);
	assertUnit(move.getSource() == sourceOut && move.getDest() == destOut && move.getMoveType() == Move::MOVE);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * READ capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::read_capture()
{
	Move move("e5d6r");
	Position sourceOut(4, 4);
	Position destOut(3, 5);
	assertUnit(move.getSource() == sourceOut && move.getDest() == destOut && move.getCapture() == ROOK);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * READ enpassant move
 * Input:  e5f6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::read_enpassant()
{
	Move move("e5f6E", false);
	Position sourceOut(4, 4);
	Position destOut(5, 5);
	assertUnit(move.getSource() == sourceOut && move.getDest() == destOut && move.getMoveType() == Move::ENPASSANT);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * READ king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::read_castleKing()
{
	Move move("e1g1c", true);
	Position sourceOut(4, 0);
	Position destOut(6, 0);
	assertUnit(move.getSource() == sourceOut && move.getDest() == destOut && move.getMoveType() == Move::CASTLE_KING);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * READ queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::read_castleQueen()
{
	Move move("e1c1C", true);
	Position sourceOut(4, 0);
	Position destOut(2, 0);
	assertUnit(move.getSource() == sourceOut && move.getDest() == destOut && move.getMoveType() == Move::CASTLE_QUEEN);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * ASSIGN simple move
 * Input:  e5e6
 * Output: source=4,4
 *         dest  =4,5
 *         type  =MOVE
 **************************************/
void TestMove::assign_simple()
{
	Move move;
	move.setText("e5e6");
	Position sourceOut(4, 4);
	Position destOut(4, 5);
	assertUnit(move.getSource() == sourceOut && move.getDest() == destOut && move.getMoveType() == Move::MOVE);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * ASSIGN capture move
 * Input:  e5d6r
 * Output: source=4,4
 *         dest  =3,5
 *         type  =MOVE
 *         capture=ROOK
 **************************************/
void TestMove::assign_capture()
{
	Move move;
	move.setText("e5d6r");
	Position sourceOut(4, 4);
	Position destOut(3, 5);
	assertUnit(move.getSource() == sourceOut && move.getDest() == destOut && move.getCapture() == ROOK);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * ASSIGN enpassant move
 * Input:  e5f6E
 * Output: source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 **************************************/
void TestMove::assign_enpassant()
{
	Move move;
	move.setText("e5f6E");
	Position sourceOut(4, 4);
	Position destOut(5, 5);
	assertUnit(move.getSource() == sourceOut && move.getDest() == destOut && move.getMoveType() == Move::ENPASSANT);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * ASSIGN king side castle
 * Input:  e1g1c
 * Output: source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 **************************************/
void TestMove::assign_castleKing()
{
	Move move;
	move.setText("e1g1c");
	Position sourceOut(4, 0);
	Position destOut(6, 0);
	assertUnit(move.getSource() == sourceOut && move.getDest() == destOut && move.getMoveType() == Move::CASTLE_KING);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * ASSIGN queen side castle
 * Input:  e1c1C
 * Output: source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 **************************************/
void TestMove::assign_castleQueen()
{
	Move move;
	move.setText("e1c1C");
	Position sourceOut(4, 0);
	Position destOut(2, 0);
	assertUnit(move.getSource() == sourceOut && move.getDest() == destOut && move.getMoveType() == Move::CASTLE_QUEEN);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TEXT simple move
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 * Output:  e5e6
 **************************************/
void TestMove::getText_simple()
{
	//Move move('4,4', '4,5', MOVE, SPACE, SPACE, true);
	Move move;
	Position source(4, 4);
	Position dest(4, 5);
	assertUnit(move.getText(source, dest, Move::MOVE) == "e5e6");
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TEXT capture
 * Input : source=4,4
 *         dest  =4,5
 *         type  =MOVE
 *         capture=ROOK
 * Output:  e5e6r
 **************************************/
void TestMove::getText_capture()
{
	//Move move('4,4', '4,5', MOVE, ROOK, SPACE, true);
	Move move;
	Position source(4, 4);
	Position dest(4, 5);
	assertUnit(move.getText(source, dest, Move::MOVE, ROOK) == "e5e6r");
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TEXT en passant
 * Input : source=4,4
 *         dest  =5,5
 *         type  =ENPASSANT
 *         capture=PAWN
 * Output:  e5f6E
 **************************************/
void TestMove::getText_enpassant()
{
	//Move move('4,4', '5,5', ENPASSANT, PAWN, SPACE, true);
	Move move;
	Position source(4, 4);
	Position dest(5, 5);
	assertUnit(move.getText(source, dest, Move::ENPASSANT, PAWN) == "e5f6E");
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TEXT king side castle
 * Input : source=4,0
 *         dest  =6,0
 *         type  =CASTLE_KING
 * Output:  e1g1c
 **************************************/
void TestMove::getText_castleKing()
{
	//Move move('4,0', '6,0', CASTLE_KING, SPACE, SPACE, true);
	Move move;
	Position source(4, 0);
	Position dest(6, 0);
	assertUnit(move.getText(source, dest, Move::CASTLE_KING) == "e1g1c");
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * GET TEXT queen side castle
 * Input : source=4,0
 *         dest  =2,0
 *         type  =CASTLE_QUEEN
 * Output:  e1c1C
 **************************************/
void TestMove::getText_castleQueen()
{
	//Move move('4,0', '2,0', CASTLE_QUEEN, SPACE, SPACE, true);
	Move move;
	Position source(4, 0);
	Position dest(2, 0);
	assertUnit(move.getText(source, dest, Move::CASTLE_QUEEN) == "e1c1C");
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE space
 * Input :  SPACE
 * Output:  ' '
 **************************************/
void TestMove::letterFromPieceType_space()
{
	Move move;
	assertUnit(move.letterFromPieceType(SPACE) == ' ');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE pawn
 * Input : PAWN
 * Output:  'p'
 **************************************/
void TestMove::letterFromPieceType_pawn()
{
	Move move;
	assertUnit(move.letterFromPieceType(PAWN) == 'p');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE bishop
 * Input : BISHOP
 * Output:  'b'
 **************************************/
void TestMove::letterFromPieceType_bishop()
{
	Move move;
	assertUnit(move.letterFromPieceType(BISHOP) == 'b');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE knight
 * Input : KNIGHT
 * Output:  'n'
 **************************************/
void TestMove::letterFromPieceType_knight()
{
	Move move;
	assertUnit(move.letterFromPieceType(KNIGHT) == 'n');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE rook
 * Input : ROOK
 * Output:  'r'
 **************************************/
void TestMove::letterFromPieceType_rook()
{
	Move move;
	assertUnit(move.letterFromPieceType(ROOK) == 'r');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE queen
 * Input : QUEEN
 * Output:  'q'
 **************************************/
void TestMove::letterFromPieceType_queen()
{
	Move move;
	assertUnit(move.letterFromPieceType(QUEEN) == 'q');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * LETTER FROM PIECE TYPE king
 * Input : KING
 * Output:  'k'
 **************************************/
void TestMove::letterFromPieceType_king()
{
	Move move;
	assertUnit(move.letterFromPieceType(KING) == 'k');
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER pawn
 * Input : 'p'
 * Output:  PAWN
 **************************************/
void TestMove::pieceTypeFromLetter_pawn()
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('p') == PAWN);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER bishop
 * Input : 'b'
 * Output:  BISHOP
 **************************************/
void TestMove::pieceTypeFromLetter_bishop()
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('b') == BISHOP);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER knight
 * Input : 'n'
 * Output:  KNIGHT
 **************************************/
void TestMove::pieceTypeFromLetter_knight()
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('n') == KNIGHT);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER rook
 * Input : 'r'
 * Output:  ROOK
 **************************************/
void TestMove::pieceTypeFromLetter_rook()
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('r') == ROOK);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER queen
 * Input : 'q'
 * Output:  QUEEN
 **************************************/
void TestMove::pieceTypeFromLetter_queen()
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('q') == QUEEN);
	//assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * PIECE TYPE FROM LETTER king
 * Input : 'k'
 * Output:  KING
 **************************************/
void TestMove::pieceTypeFromLetter_king()
{
	Move move;
	assertUnit(move.pieceTypeFromLetter('k') == KING);
	//assertUnit(NOT_YET_IMPLEMENTED);
}


///*************************************
// * EQUAL - NOT
// * Input : b2b4 == b2b5
// * Output: false
// **************************************/
//void TestMove::equal_not()
//{
//	Move move;
//	assertUnit(move.equal("b2b4", "b2b5") == false);
//	//assertUnit(NOT_YET_IMPLEMENTED);
//}
//
///*************************************
// * EQUAL - EQUALS
// * Input : b2b4 == b2b4
// * Output: ture
// **************************************/
//void TestMove::equal_equals()
//{
//	Move move;
//	assertUnit(move.equal("b2b4", "b2b4") == true);
//	//assertUnit(NOT_YET_IMPLEMENTED);
//}
//
///*************************************
// * LESS THAN - LESS THAN
// * Input : b2b2 < b2b4
// * Output: true
// **************************************/
//void TestMove::lessthan_lessthan()
//{
//	Move move;
//	assertUnit(move.less_than("b2b2", "b2b4") == true);
//	//assertUnit(NOT_YET_IMPLEMENTED);
//}
//
///*************************************
// * LESS THAN - EQUALS
// * Input : b2b4 < b2b4
// * Output: false
// **************************************/
//void TestMove::lessthan_equals()
//{
//	Move move;
//	assertUnit(move.less_than("b2b4", "b2b4") == false);
//	//assertUnit(NOT_YET_IMPLEMENTED);
//}
//
///*************************************
// * LESS THAN - GREATAER THAN
// * Input : b2b4 < b2b2
// * Output: false
// **************************************/
//void TestMove::lessthan_greaterthan()
//{
//	Move move;
//	assertUnit(move.less_than("b2b2", "b2b2") == false);
//	//assertUnit(NOT_YET_IMPLEMENTED);
//}
