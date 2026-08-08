#include <iostream>

#include "utilities.h"
#include "bitboards/bitboards.h"

int main()
{
    uint64_t rookBoard = slowMoveGenerateRook(1,4);
    outputBoard(rookBoard);

    uint64_t bishopBoard = slowMoveGenerateBishop(0,8*8*8);
    outputBoard(bishopBoard);

    uint64_t queenBoard = slowMoveGenerateQueen(0,0);
    outputBoard(queenBoard);
    
    return 0;
}