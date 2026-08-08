#include "utilities.h"


void outputBoard(uint64_t bitboard) {
    uint64_t bit = 1;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            int num = 8*y + x;
            if ((bitboard & (bit << num)) == 0) {
                std::cout << "0";
            } else {
                std::cout << "1";
            }
        }
        std::cout << std::endl;
    }
}