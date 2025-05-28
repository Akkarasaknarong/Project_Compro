#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
    Game();
    ~Game();

    void Draw();             // Draw game
    void HandleInput();      // get HandleInput      
    void MoveBlockDown();    // MoveBlockDown
    bool gameOver;

    int score;
    Music music;

private:
    void MoveBlockLeft();     // MoveBlockLeft
    void MoveBlockRight();    // MoveBlockRight
    void RotateBlock();       // RotateBlock
    void LockBlock();         // Check if the block is on the ground
    bool BlockFits();         // Check If block is collision other block
    bool IsBlockOutside();    // Check if the block is Outside
    void Reset();             // Reset Game
    void UpdateScore(int linesCleared, int moveDownPoints);  // UpdateScore

    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    Grid grid;  
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;
};