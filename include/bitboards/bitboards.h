#pragma once
#include <cstdint>

extern std::uint64_t knightMoves[64];
extern std::uint64_t bishopMoves[64];
extern std::uint64_t rookMoves[64];
extern std::uint64_t queenMoves[64];
extern std::uint64_t kingMoves[64];
extern std::uint64_t WhitePawnMoves[64]; 
extern std::uint64_t BlackPawnMoves[64]; 
extern std::uint64_t WhitePawnAttacks[64]; 
extern std::uint64_t BlackPawnAttacks[64]; 

void initializeKnightMoves();
void initializeBishopMoves();
void initializeRookMoves();
void initializeQueenMoves();

/*
Implementation of bitboards for all pieces.
These are to be stored for each unique position, going from 0 to 63.
For sliding pieces, these define the maximum reach that each piece can move to.
When doing magic number hashing, these will be corrected depending on the occupancy state.
*/



uint64_t slowMoveGenerateRook(int position, uint64_t fullBoard);
uint64_t slowMoveGenerateBishop(int position, uint64_t fullBoard);
uint64_t slowMoveGenerateQueen(int position, uint64_t fullBoard);

/*
SLow implementation for a board for a sliding piece, given its position and the rest of the board.
Returns an attack bitboard.
*/

extern std::uint64_t rookMagicNumbers[64];
extern std::uint64_t bishopMagicNumbers[64];
extern std::uint64_t slidingRookMoves[64][4096];
int mapRookPositionToIndex(int position, uint64_t occupancyBoard, int magicNumber);


/*

*/
