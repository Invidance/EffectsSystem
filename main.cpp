#include "stdafx.h"
#include "raylib.h"
#include "Easing.h"

int main()
{
	InitWindow(CONSTS::SCREEN_WIDTH, CONSTS::SCREEN_HEIGHT, "Effects System");

	SetTargetFPS(120);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Empty window", int(CONSTS::SCREEN_WIDTH * 0.5f), int(CONSTS::SCREEN_HEIGHT * 0.5f), 20, LIGHTGRAY);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
