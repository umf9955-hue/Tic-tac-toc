#include "raylib.h"
#include <iostream>

const int screenWidth = 600;
const int screenHeight = 600;
const int gridSize = 3;
const int cellSize = screenWidth / gridSize;

// Constants to represent players
const int NONE = 0;
const int X = 1;
const int O = 2;

int grid[gridSize][gridSize];
int currentPlayer = X;
bool gameOver = false;
int winner = NONE;

// Reset the game board
void ResetGame() {
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridSize; j++)
            grid[i][j] = NONE;

    currentPlayer = X;
    gameOver = false;
    winner = NONE;
}

// Check for a winner or a draw
void CheckGameState() {
    // Check rows and columns
    for (int i = 0; i < gridSize; i++) {
        // Check row
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != NONE)
            winner = grid[i][0];

        // Check column
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != NONE)
            winner = grid[0][i];
    }

    // Check diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != NONE)
        winner = grid[0][0];

    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != NONE)
        winner = grid[0][2];

    // Check for a draw
    bool draw = true;
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridSize; j++)
            if (grid[i][j] == NONE)
                draw = false;

    if (winner != NONE) {
        gameOver = true;
    } else if (draw) {
        gameOver = true;
        winner = NONE;
    }
}

// Draw the grid
void DrawGrid() {
    for (int i = 1; i < gridSize; i++) {
        DrawLine(i * cellSize, 0, i * cellSize, screenHeight, BLACK);
        DrawLine(0, i * cellSize, screenWidth, i * cellSize, BLACK);
    }
}

// Draw X or O in a cell
void DrawMark(int player, int row, int col) {
    if (player == X) {
        DrawLine(col * cellSize + 20, row * cellSize + 20, (col + 1) * cellSize - 20, (row + 1) * cellSize - 20, RED);
        DrawLine((col + 1) * cellSize - 20, row * cellSize + 20, col * cellSize + 20, (row + 1) * cellSize - 20, RED);
    } else if (player == O) {
        DrawCircle(col * cellSize + cellSize / 2, row * cellSize + cellSize / 2, cellSize / 2 - 20, BLUE);
    }
}

int main() {
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe - Raylib");

    ResetGame();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Handle input
        if (!gameOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            int col = mousePos.x / cellSize;
            int row = mousePos.y / cellSize;

            if (grid[row][col] == NONE) {
                grid[row][col] = currentPlayer;
                currentPlayer = (currentPlayer == X) ? O : X;
                CheckGameState();
            }
        }

        if (gameOver && IsKeyPressed(KEY_R)) {
            ResetGame();
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawGrid();

        for (int i = 0; i < gridSize; i++)
            for (int j = 0; j < gridSize; j++)
                DrawMark(grid[i][j], i, j);

        if (gameOver) {
            if (winner == X) {
                DrawText("Player X Wins!", 150, 500, 40, RED);
            } else if (winner == O) {
                DrawText("Player O Wins!", 150, 500, 40, BLUE);
            } else {
                DrawText("It's a Draw!", 200, 500, 40, DARKGRAY);
            }
            DrawText("Press R to Restart", 180, 550, 20, GRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
