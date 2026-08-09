#include "bitboards/bitboards.h"

std::uint64_t knightMoves[64];
std::uint64_t bishopMoves[64];
std::uint64_t rookMoves[64];
std::uint64_t queenMoves[64];

void initializeKnightMoves() 
{
    for (int i = 0; i < 64; i++) {
        knightMoves[i] = 0;
        if (i % 8 > 1) {
            if (i / 8 > 0) {
                knightMoves[i] |= 1ULL << (i - 10);
            }
            if (i / 8 < 7) {
                knightMoves[i] |= 1ULL << (i + 6);
            }
        }
        if (i % 8 < 6) {
            if (i / 8 > 0) {
                knightMoves[i] |= 1ULL << (i - 6);
            }
            if (i / 8 < 7) {
                knightMoves[i] |= 1ULL << (i + 10);
            }

        }
        if (i % 8 > 0) {
            if (i / 8 > 1) {
                knightMoves[i] |= 1ULL << (i - 17);
            }
            if (i / 8 < 6) {
                knightMoves[i] |= 1ULL << (i + 15);
            }
        }
        if (i % 8 < 7) {
            if (i / 8 > 1) {
                knightMoves[i] |= 1ULL << (i - 15);
            }
            if (i / 8 < 6) {
                knightMoves[i] |= 1ULL << (i + 17);
            }
        }
    }
}

void initializeBishopMoves() 
{
    for (int i = 0; i < 64; i++) {
        bishopMoves[i] = 0;
        int pos_x = i % 8;
        int pos_y = i / 8;
        for (int j = 1; j < 8; j++) {
            if (pos_x + j < 8 && pos_y + j < 8) {
                bishopMoves[i] |= 1ULL << (i + j * 9);
            }
            if (pos_x - j >= 0 && pos_y + j < 8) {
                bishopMoves[i] |= 1ULL << (i + j * 7);
            }
            if (pos_x + j < 8 && pos_y - j >= 0) {
                bishopMoves[i] |= 1ULL << (i - j * 7);
            }
            if (pos_x - j >= 0 && pos_y - j >= 0) {
                bishopMoves[i] |= 1ULL << (i - j * 9);
            }
        }
    }   
}


void initializeRookMoves() 
{
    for (int i = 0; i < 64; i++) {
        rookMoves[i] = 0;
        int pos_x = i % 8;
        int pos_y = i / 8;
        for (int j = 1; j < 8; j++) {
            if (pos_x + j < 8) {
                rookMoves[i] |= 1ULL << (i + j);
            }
            if (pos_x - j >= 0) {
                rookMoves[i] |= 1ULL << (i - j);
            }
            if (pos_y + j < 8) {
                rookMoves[i] |= 1ULL << (i + j * 8);
            }
            if (pos_y - j >= 0) {
                rookMoves[i] |= 1ULL << (i - j * 8);
            }
        }
    }
}

void initializeQueenMoves() 
{
    for (int i = 0; i < 64; i++) {
        queenMoves[i] = bishopMoves[i] | rookMoves[i];
    }
}

uint64_t slowMoveGenerateRook(int position, uint64_t fullBoard) 
{
    int pos_x = position % 8;
    int pos_y = position / 8;
    uint64_t bit = 0;
    uint64_t toFillBoard = 0;
    int foundRight = 0;
    int foundLeft = 0;
    int foundUp = 0;
    int foundDown = 0;
    for (int j = 1; j < 8; j++) {
        if ((pos_x + j < 8) && (foundRight == 0)) {
                bit = 1ULL << position + j;
                toFillBoard |= (~fullBoard & bit);
                if ((~fullBoard & bit) == 0) {
                    toFillBoard |= bit;
                    foundRight = 1;
                }
            }
            if ((pos_x - j >= 0) && (foundLeft == 0)) {
                bit = 1ULL << position - j;
                toFillBoard |= (~fullBoard & bit);
                if ((~fullBoard & bit) == 0) {
                    toFillBoard |= bit;
                    foundLeft = 1;
                }
            }
            if ((pos_y + j < 8) && (foundUp == 0)) {
                bit = 1ULL << position + 8*j;
                toFillBoard |= (~fullBoard & bit);
                if ((~fullBoard & bit) == 0) {
                    toFillBoard |= bit;
                    foundUp = 1;
                }
            }
            if ((pos_y - j >= 0) && (foundDown == 0)) {
                bit = 1ULL << position - 8*j;
                toFillBoard |= (~fullBoard & bit);
                if ((~fullBoard & bit) == 0) {
                    toFillBoard |= bit;
                    foundDown = 1;
                }
            }
    }

    return toFillBoard;
}

uint64_t slowMoveGenerateBishop(int position, uint64_t fullBoard) 
{
    int pos_x = position % 8;
    int pos_y = position / 8;
    uint64_t bit = 0;
    uint64_t toFillBoard = 0;
    int foundRU = 0;
    int foundLU = 0;
    int foundRD = 0;
    int foundLD = 0;
    for (int j = 1; j < 8; j++) {
        if ((pos_x + j < 8) && (pos_y + j < 8) && (foundRU == 0)) {
                bit = 1ULL << position + 9*j;
                toFillBoard |= (~fullBoard & bit);
                if ((~fullBoard & bit) == 0) {
                    toFillBoard |= bit;
                    foundRU = 1;
                }
            }
            if ((pos_x - j >= 0) && (pos_y + j < 8) && (foundLU == 0)) {
                bit = 1ULL << position + 7*j;
                toFillBoard |= (~fullBoard & bit);
                if ((~fullBoard & bit) == 0) {
                    toFillBoard |= bit;
                    foundLU = 1;
                }
            }
            if ((pos_x + j < 8) && (pos_y - j >= 0) && (foundRD == 0)) {
                bit = 1ULL << position - 7*j;
                toFillBoard |= (~fullBoard & bit);
                if ((~fullBoard & bit) == 0) {
                    toFillBoard |= bit;
                    foundRD = 1;
                }
            }
            if ((pos_x - j >= 0) && (pos_y - j >= 0) && (foundLD == 0)) {
                bit = 1ULL << position - 9*j;
                toFillBoard |= (~fullBoard & bit);
                if ((~fullBoard & bit) == 0) {
                    toFillBoard |= bit;
                    foundLD = 1;
                }
            }
    }

    return toFillBoard;
}

uint64_t slowMoveGenerateQueen(int position, uint64_t fullBoard) 
{
    return slowMoveGenerateRook(position, fullBoard) | slowMoveGenerateBishop(position, fullBoard);
}
 


int mapRookPositionToIndex(int position, uint64_t occupancyBoard, int magicNumber)
{
    uint64_t occupancyBoardFilter = (rookMoves[position] & 0x007E7E7E7E7E7E00);
    return (occupancyBoardFilter * magicNumber) & (0xFFF);
}

int verifyMagicNumber()