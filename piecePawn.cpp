/***********************************************************************
 * Source File:
 *    PAWN
 * Author:
 *    Daniel Carr
 * Summary:
 *    The pawn class
 ************************************************************************/

#include "piecePawn.h"
#include "board.h"
#include <iostream>


 /**********************************************
  * PAWN : GET POSITIONS
  *********************************************/
void Pawn::getMoves(set<Move>& moves, const Board& board) const
{
	const Position currentPos = this->getPosition();
	Move newMove;
	string smith;
	int newCol;
	int newRow;
	
	// 1 space advansment
	int offsets[2] = { 1, -1};
	if (fWhite)
	{
		newRow = currentPos.getRow() + 1;
		Position destPosWA(currentPos.getCol(), newRow);
		if (destPosWA.isValid())
		{
			const Piece* pTarget = &(board[destPosWA]); // Get piece at new position
			if (currentPos.getRow() == 6)
			{
				if (pTarget->getType() == PieceType::SPACE)
				{
					smith = newMove.getText(currentPos, destPosWA, Move::MOVE, PieceType::SPACE, PieceType::QUEEN);
					moves.insert(Move(smith));
				}
			}
			else if (pTarget->getType() == PieceType::SPACE)
			{
				smith = newMove.getText(currentPos, destPosWA, Move::MOVE);
				moves.insert(Move(smith));
			}
		}
		for (int i = 0; i < 2; i++)
		{
			newCol = currentPos.getCol() + offsets[i];
			Position destPosWB(newCol, newRow);
			if (destPosWB.isValid())
			{
				const Piece* pTarget = &(board[destPosWB]);
				if (pTarget->isWhite() != fWhite && pTarget->getType() != PieceType::SPACE)
				{
					if (currentPos.getRow() == 6)
					{
						smith = newMove.getText(currentPos, destPosWB, Move::MOVE, pTarget->getType(), PieceType::QUEEN);
						moves.insert(Move(smith));
					}
					else
					{
						smith = newMove.getText(currentPos, destPosWB, Move::MOVE, pTarget->getType());
						moves.insert(Move(smith));
					}
				}
			}
		}
		if (nMoves == 0)
		{
			newRow += 1;
			Position destPosWC(currentPos.getCol(), newRow);
			const Piece* pTarget = &(board[destPosWC]); // Get piece at new position
			// If there's no piece, it's a valid move
			if (pTarget->getType() == PieceType::SPACE)
			{
				smith = newMove.getText(currentPos, destPosWC, Move::MOVE);
				moves.insert(Move(smith));
			}
		}
		
	}
	else
	{
		newRow = currentPos.getRow() - 1;
		Position destPosBA(currentPos.getCol(), newRow);
		if (destPosBA.isValid())
		{
			const Piece* pTarget = &(board[destPosBA]); // Get piece at new position
			if (currentPos.getRow() == 1)
			{
				if (pTarget->getType() == PieceType::SPACE)
				{
					smith = newMove.getText(currentPos, destPosBA, Move::MOVE, PieceType::SPACE, PieceType::QUEEN);
					moves.insert(Move(smith));
				}
			}
			else if (pTarget->getType() == PieceType::SPACE)
			{
				smith = newMove.getText(currentPos, destPosBA, Move::MOVE);
				moves.insert(Move(smith));
			}
		}
		for (int i = 0; i < 2; i++)
		{
			newCol = currentPos.getCol() + offsets[i];
			Position destPosBB(newCol, newRow);
			if (destPosBB.isValid())
			{
				const Piece* pTarget = &(board[destPosBB]);
				if (pTarget->isWhite() != fWhite && pTarget->getType() != PieceType::SPACE)
				{
					if (currentPos.getRow() == 1)
					{
						smith = newMove.getText(currentPos, destPosBB, Move::MOVE, pTarget->getType(), PieceType::QUEEN);
						moves.insert(Move(smith));
					}
					else
					{
						smith = newMove.getText(currentPos, destPosBB, Move::MOVE, pTarget->getType());
						moves.insert(Move(smith));
					}
				}
			}
		}
		if (nMoves == 0)
		{
			newRow -= 1;
			Position destPosBC(currentPos.getCol(), newRow);
			const Piece* pTarget = &(board[destPosBC]); // Get piece at new position
			// If there's no piece, it's a valid move
			if (pTarget->getType() == PieceType::SPACE)
			{
				smith = newMove.getText(currentPos, destPosBC, Move::MOVE);
				moves.insert(Move(smith));
			}
		}
	}

 
}



