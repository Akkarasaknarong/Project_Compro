#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
public:
    Block();

    void Draw(int offsetX, int offsetY);  // Draw Block
    void Move(int rows, int columns);     // Move Block
    void Rotate();                        // Rotate Block
    void UndoRotation();                  // Check If the block is collistion things

    int id;
    std::vector<Position> GetCellPositions();
    std::map<int, std::vector<Position>> cells;

private:
    int cellSize;
    int rotationState;
    int rowOffset;
    int columnOffset;
    std::vector<Color> colors;
};