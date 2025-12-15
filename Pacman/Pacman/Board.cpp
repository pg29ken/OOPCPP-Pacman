// Copyright @ Vi Tran - VFS 2025-2026
#include "Board.hpp"

#include "Utils.hpp"
#include "Consumable.hpp"
#include "PowerPellet.hpp"
#include <windows.h>

Board::Board()
{
    for (int r = 0; r < _rows; r++) {
        for (int c = 0; c < _cols; c++) {
            char symbol = renderedBoard[r][c];
            if (symbol == '.') {
                dataBoard[r][c] = new Consumable("Pellet", { r, c });
            }
            else if (symbol == 'o') {
                dataBoard[r][c] = new PowerPellet("PowerPellet", { r, c });
            }
        }
    }
}

Board::~Board()
{
    for (int r = 0; r < _rows; r++) {
        for (int c = 0; c < _cols; c++) {
            delete dataBoard[r][c];  // safe even if nullptr
            dataBoard[r][c] = nullptr;
        }
    }
}


void Board::RenderBoard() {
    for (int r = 0; r < _rows; r++) {
        LOG_LN(renderedBoard[r]);
    }
}

void Board::ChangeCell(std::pair<int, int> pos, char newChar)
{
        renderedBoard[pos.first][pos.second] = newChar;
        DrawCell(pos);

}

bool Board::IsCellTraversible(std::pair<int, int> pos)
{
    if (pos.first < 0 || pos.first >= _rows || pos.second < 0 || pos.second >= _cols)
        return false;

    return renderedBoard[pos.first][pos.second] != '#';
}

char Board::GetCharacterAtPos(std::pair<int, int> pos)
{
    Consumable* cell = dataBoard[pos.first][pos.second];
    if (!cell) return ' ';
    if (dynamic_cast<PowerPellet*>(cell) != nullptr) return 'o';
    return '.';
}

void Board::DrawCell(std::pair<int, int> pos)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD coord;
    coord.X = static_cast<SHORT>(pos.second); // column
    coord.Y = static_cast<SHORT>(pos.first);  // row

    SetConsoleCursorPosition(hConsole, coord);

    LOG(renderedBoard[pos.first][pos.second]);
}

void Board::RestoreCell(std::pair<int, int> pos)
{
    Consumable* cell = dataBoard[pos.first][pos.second];

    if (!cell)
    {
        ChangeCell(pos, ' ');
        return;
    }

    if (dynamic_cast<PowerPellet*>(cell))
    {
        ChangeCell(pos, 'o');
    }
    else
    {
        ChangeCell(pos, '.');
    }
}

