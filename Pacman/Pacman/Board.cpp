// Copyright @ Vi Tran - VFS 2025-2026

#include "Board.hpp"

#include "Utils.hpp"
#include "Consumable.hpp"
#include "PowerPellet.hpp"

void Board::RenderBoard() {
    for (int r = 0; r < _rows; r++) {
        LOG_LN(renderedBoard[r]);
    }
}

void Board::Init()
{
    for (int r = 0; r < _rows; r++) {
        for (int c = 0; c < _cols; c++) {
            char symbol = renderedBoard[r][c];

            // Initialize different objects depending on symbol
            if (symbol == '#') {
                dataBoard[r][c] = Object("Wall", { r, c });
            }
            else if (symbol == '.') {
                dataBoard[r][c] = Consumable("Pellet", { r, c });
            }
            else if (symbol == 'o') {
                dataBoard[r][c] = PowerPellet();
            }
            else {
                dataBoard[r][c] = Object("Empty", { r, c });
            }
        }
    }
}