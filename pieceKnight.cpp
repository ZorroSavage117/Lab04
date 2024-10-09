/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{

}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set<Move>& moves, const Board& board) const
{
    // The possible relative moves for a knight
    int offsets[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    Position currentPos = this->getPosition();
	Move newMove;

    for (int i = 0; i < 8; ++i) {
        int newCol = currentPos.getCol() + offsets[i][0];
        int newRow = currentPos.getRow() + offsets[i][1];
		Position destPos(newCol, newRow);
		string smith;

        // Check if the new position is within board boundaries
        if (destPos.isValid()) {
            PieceDerived target(board[destPos]); // Get piece at new position
			      // board[newCol, newRow]
            // If there's no piece, it's a valid move
            if (target.getType() == PieceType::SPACE)
            {
				smith = newMove.getText(currentPos, destPos, Move::MOVE);
                moves.insert(Move());
            }
            // If there's a piece, check if it's an enemy piece for capturing
            else if (target.isWhite() != this->fWhite) 
            {
				smith = newMove.getText(currentPos, destPos, Move::MOVE, target.getType());
                moves.insert(Move(smith)); // Mark as capture
            }
        }
    }
}
