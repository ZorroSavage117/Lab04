/***********************************************************************
 * Source File:
 *    QUEEN
 * Author:
 *    Arlo Jolley & Daniel Carr
 * Summary:
 *    The queen class
 ************************************************************************/

#include "pieceQueen.h"
#include "board.h"


 /**********************************************
  * QUEEN : GET POSITIONS
  *********************************************/
void Queen::getMoves(set<Move>& moves, const Board& board) const
{
    // The possible relative moves for a queen
    int offsets[8][7][2] = {
        {{0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}},
        {{-1,0}, {-2,0}, {-3,0}, {-4,0}, {-5,0}, {-6,0}, {-7,0}},
        {{0,-1}, {0,-2}, {0,-3}, {0,-4}, {0,-5}, {0,-6}, {0,-7}},
        {{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}},
        {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7}},
        {{-1,1}, {-2,2}, {-3,3}, {-4,4}, {-5,5}, {-6,6}, {-7,7}},
        {{1,-1}, {2,-2}, {3,-3}, {4,-4}, {5,-5}, {6,-6}, {7,-7}},
        {{-1,-1}, {-2,-2}, {-3,-3}, {-4,-4}, {-5,-5}, {-6,-6}, {-7,-7}}
    };

    const Position currentPos = this->getPosition();
    Move newMove;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            int newCol = currentPos.getCol() + offsets[i][j][0];
            int newRow = currentPos.getRow() + offsets[i][j][1];
            Position destPos(newCol, newRow);
            string smith;

            // Check if the new position is within board boundaries
            if (destPos.isValid())
            {
                const Piece* pTarget( &(board[destPos])); // Get piece at new position
                // If there's no piece, it's a valid move
                if (pTarget == nullptr || pTarget->getType() == PieceType::SPACE)
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
    }
}
