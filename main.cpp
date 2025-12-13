#include "stdafx.h"
#include "raylib.h"
#include "Core/Easing.h"
#include "Components/Slider.h"
#include "Core/App.h"

using namespace Core;

int main()
{
	InitWindow(CONSTS::SCREEN_WIDTH, CONSTS::SCREEN_HEIGHT, "Effects System");

	SetTargetFPS(120);
	Application* app = new Application();

	Slider* slider = new Slider();
	slider->init(0.f);
	slider->setX(CONSTS::SCREEN_WIDTH * 0.5f);
	slider->setY(CONSTS::SCREEN_HEIGHT * 0.5f);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		app->draw();
		//DrawText("Empty window", int(CONSTS::SCREEN_WIDTH * 0.5f), int(CONSTS::SCREEN_HEIGHT * 0.5f), 20, LIGHTGRAY);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
