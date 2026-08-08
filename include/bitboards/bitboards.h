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
uint64_t slowMoveGenerateRook(int position, uint64_t fullBoard);