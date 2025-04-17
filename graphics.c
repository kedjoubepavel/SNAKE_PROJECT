#include "raylib.h"
#include"graphics.h"

void lancer_interface() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Interface de lancement");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Appuyez sur ESPACE pour commencer", 180, 200, 20, DARKGRAY);
        EndDrawing();

        if (IsKeyPressed(KEY_SPACE)) break;
    }

    CloseWindow();
}
