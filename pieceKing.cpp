/***********************************************************************
 * Source File:
 *    KING
 * Author:
 *    Daniel Carr
 * Summary:
 *    The king class
 ************************************************************************/

#include "pieceKing.h"
#include "board.h"


 /**********************************************
  * KING : GET POSITIONS
  *********************************************/
void King::getMoves(set<Move>& moves, const Board& board) const
{
    // The possible relative moves for a king
    int offsets[8][2] = {
        {0,1},
        {-1,0},
        {0,-1},
        {1,0},
        {1,1},
        {-1,1},
        {1,-1},
        {-1,-1}
    };

    const Position currentPos = this->getPosition();
    Move newMove;
    string smith;

    for (int i = 0; i < 8; ++i)
    {
        int newCol = currentPos.getCol() + offsets[i][0];
        int newRow = currentPos.getRow() + offsets[i][1];
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
                break;
            }
            else
            {
                break;
            }
        }
    }

	// Check for castling
	if (nMoves == 0)
	{
		// Check for castling on the king side
		if (board[Position(7, currentPos.getRow())].getType() == PieceType::ROOK &&
			board[Position(7, currentPos.getRow())].getNMoves() == 0 &&
            board[Position(7, currentPos.getRow())].isWhite() == fWhite)
		{
			bool canCastle = true;
			for (int i = 1; i < 3; ++i)
			{
				if (board[Position(currentPos.getCol() + i, currentPos.getRow())].getType() != PieceType::SPACE)
				{
					canCastle = false;
					break;
				}
			}
			if (canCastle)
			{
				smith = newMove.getText(currentPos, Position(currentPos.getCol() + 2, currentPos.getRow()), Move::CASTLE_KING);
				moves.insert(Move(smith)); // 
			}
		}

		// Check for castling on the queen side
		if (board[Position(0, currentPos.getRow())].getType() == PieceType::ROOK &&
			board[Position(0, currentPos.getRow())].getNMoves() == 0 &&
            board[Position(7, currentPos.getRow())].isWhite() == this->fWhite)
		{
			bool canCastle = true;
			for (int i = 1; i < 4; ++i)
			{
				if (board[Position(currentPos.getCol() - i, currentPos.getRow())].getType() != PieceType::SPACE)
				{
					canCastle = false;
					break;
				}
			}
			if (canCastle)
			{
				smith = newMove.getText(currentPos, Position(currentPos.getCol() - 2, currentPos.getRow()), Move::CASTLE_QUEEN);
				moves.insert(Move(smith));
			}
		}
	}   
}
