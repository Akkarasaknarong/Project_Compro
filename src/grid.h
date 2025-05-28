#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();
    void Initialize();                       // Initialize Grid
    void Print();                            // Print Grid
    void Draw();                             // Draw Grid
    bool IsCellOutside(int row, int column); // Check if the cell is outside the grid
    bool IsCellEmpty(int row, int column);   // Check if the cell Empty
    int ClearFullRows();                     // ClearFullRows

    int grid[20][10];

private:
    bool IsRowFull(int row);                // Check if row is full
    void ClearRow(int row);                 // ClearRow
    void MoveRowDown(int row, int numRows); // MoveRowDown after ClearRow

    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};