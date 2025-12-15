// Copyright @ Vi Tran - VFS 2025-2026
#pragma once

#include "Object.hpp"
#include "Consumable.hpp"
class Board
{
public:

    Board();
    ~Board();

    static const int _rows = 31;
    static const int _cols = 28;

    char renderedBoard[_rows][_cols + 1] = {
        "############################",
        "#............##............#",
        "#.####.#####.##.#####.####.#",
        "#.####.#####.##.#####.####.#",
        "#.####.#####.##.#####.####.#",
        "#..........................#",
        "#.####.##.########.##.####.#",
        "#.####.##.########.##.####.#",
        "#......##....##....##......#",
        "######.##### ## #####.######",
        "     #.##### ## #####.#     ",
        "     #.##          ##.#     ",
        "######.## ######## ##.######",
        "      .   #      #   .      ",
        "######.## ######## ##.######",
        "     #.##          ##.#     ",
        "     #.## ######## ##.#     ",
        "######.## ######## ##.######",
        "#............##............#",
        "#.####.#####.##.#####.####.#",
        "#o..##................##..o#",
        "###.##.##.########.##.##.###",
        "###.##.##.########.##.##.###",
        "#......##....##....##......#",
        "#.##########.##.##########.#",
        "#.##########.##.##########.#",
        "#..........................#",
        "#............##............#",
        "############################"
    };



    Consumable* dataBoard[_rows][_cols + 1] = {nullptr};

    void RenderBoard();
    void ChangeCell(std::pair<int, int> pos, char newChar);
    bool IsCellTraversible(std::pair<int, int> pos);
    bool CellContainsConsumable(std::pair<int, int> pos);
    char GetCharacterAtPos(std::pair<int, int> pos);
    void DrawCell(std::pair<int, int> pos);
    void RestoreCell(std::pair<int, int> pos);
    std::pair<int, int> WrapPosition(const std::pair<int, int>& pos);
    


private:


};

