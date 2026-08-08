#include <iostream>

#include "utilities.h"
#include "bitboards/bitboards.h"

int main()
{
    uint64_t rookBoard = slowMoveGenerateRook(0,0);
    outputBoard(rookBoard);

    return 0;
}