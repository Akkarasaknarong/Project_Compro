#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

// Timer MoveBlockDown
double lastUpdateTime = 0;
bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    // Setup system game
    InitWindow(500, 620, "Tetris_G3");
    SetTargetFPS(60);
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    Game game = Game();

    while (WindowShouldClose() == false)
    {
        // Setup system game
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(0.01))
        {
            game.MoveBlockDown();
        }
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 1, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, darkGrey);
        BeginDrawing();

        // Draw all
        ClearBackground(BLACK);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, darkGrey);

        // Update score
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);

        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}