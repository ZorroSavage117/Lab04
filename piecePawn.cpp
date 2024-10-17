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
	// the possible moves for a pawn are:
	// if nMoves == 0, it can move 1 or 2 spaces forward // done
	// if nMoves > 0, it can only move 1 space forward   // done
	// if there is an enemy piece diagonally in front of it and it just moved 2 spaces, it can capture it en passant

    const Position currentPos = this->getPosition();
    Move newMove;
    string smith;
	
	// 2 space advansment
	if (nMoves == 0)
	{
		int offsets[2] = { 1, 2 };
		// Check if the new position is within board boundaries
		for (int i = 0; i < 2; i++)
		{
			int newCol = currentPos.getCol();
			int newRow;
			if (fWhite)
			{
				newRow = currentPos.getRow() + offsets[i];

			}
			else
			{
				newRow = currentPos.getRow() - offsets[i];
			}
			Position destPos(newCol, newRow);

			if (destPos.isValid())
			{
				const Piece* pTarget = &(board[destPos]); // Get piece at new position
				// If there's no piece, it's a valid move
				if (pTarget->getType() == PieceType::SPACE)
				{
					smith = newMove.getText(currentPos, destPos, Move::MOVE);
					moves.insert(Move(smith));
				}
				// If there's a piece, check if it's an enemy piece for capturing
				else if (pTarget->isWhite() != this->fWhite)
				{
					smith = newMove.getText(currentPos, destPos, Move::MOVE, pTarget->getType());
					moves.insert(Move(smith)); // Mark as capture
				}
			}
		}
	}
	else
	{
        int newCol = currentPos.getCol();
		int newRow;
		if (fWhite)
		{
			newRow = currentPos.getRow() + 1;
		}
		else
		{
			newRow = currentPos.getRow() - 1;
		}
		Position destPos(newCol, newRow);


        // Check if the new position is within board boundaries
        if (destPos.isValid())
        {
            const Piece* pTarget = &(board[destPos]); // Get piece at new position
            // If there's no piece, it's a valid move
            if (pTarget->getType() == PieceType::SPACE)
            {
                smith = newMove.getText(currentPos, destPos, Move::MOVE);
                moves.insert(Move(smith));
            }
            // If there's a piece, check if it's an enemy piece for capturing
            else if (pTarget->isWhite() != this->fWhite)
            {
                smith = newMove.getText(currentPos, destPos, Move::MOVE, pTarget->getType());
                moves.insert(Move(smith)); // Mark as capture
            }
        }
		
		// en passont white
		if (fWhite && currentPos.getRow() == 4)
		{
			int offsets[2] = { 1, -1 };
			// Check if the new position is within board boundaries
			for (int i = 0; i < 2; i++)
			{
				int newCol = currentPos.getCol() + offsets[i];
				int newRow = currentPos.getRow() + 1;
				Position destPos(newCol, newRow);
				newRow -= 1;
				Position capPos(newCol, newRow);

				if (destPos.isValid() && capPos.isValid())
				{
					const Piece* pTarget = &(board[capPos]); // Get piece at new position
					if (pTarget->isWhite() != this->fWhite)
					{
						smith = newMove.getText(currentPos, destPos, Move::ENPASSANT);
						moves.insert(Move(smith)); // Mark as capture
					}
				}
			}
		}
		if (!fWhite && currentPos.getRow() == 3)
		{
			int offsets[2] = { 1, -1 };
			// Check if the new position is within board boundaries
			for (int i = 0; i < 2; i++)
			{
				int newCol = currentPos.getCol() + offsets[i];
				int newRow = currentPos.getRow() - 1;
				Position destPos(newCol, newRow);
				newRow += 1;
				Position capPos(newCol, newRow);

				if (destPos.isValid() && capPos.isValid())
				{
					const Piece* pTarget = &(board[capPos]); // Get piece at new position
					if (pTarget->isWhite() != this->fWhite)
					{
						smith = newMove.getText(currentPos, destPos, Move::ENPASSANT);
						moves.insert(Move(smith)); // Mark as capture
					}
				}
			}
		}
    }
}



