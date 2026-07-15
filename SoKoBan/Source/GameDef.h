#pragma once
#include <App.h>

#define TILE_WIDTH 13


enum class Direction {
	Front,
	Back,
	Right,
	Left,
};

enum class SceneType {
	None=-1,
	Title,
	InGame,
	GameClear,
	Select,
};


enum {
	STAGE_AMOUNT = 4,
};

const float w = 1.0f / 13.0f;
const float h = 1.0f / 8.0f;

const Vector2f player_front[3] = {
	{0.0f,5.0f / 8.0f},
	{1.0f/13.0f,5.0f / 8.0f},
	{2.0f/13.0f,5.0f / 8.0f},
};

const Vector2f player_back[3] = {
	{3.0f / 13.0f,5.0f / 8.0f},
	{4.0f / 13.0f,5.0f / 8.0f},
	{5.0f / 13.0f,5.0f / 8.0f},
};

const Vector2f player_right[3] = {
	{0.0f,7.0f / 8.0f},
	{1.0f / 13.0f,7.0f / 8.0f},
	{2.0f / 13.0f,7.0f / 8.0f},
};

const Vector2f player_left[3] = {
	{3.0f / 13.0f,7.0f / 8.0f},
	{4.0f / 13.0f,7.0f / 8.0f},
	{5.0f / 13.0f,7.0f / 8.0f},
};

const UVRect uvs[] = {
	{0.0f,5.0f / 8.0f,w,h},
	{1.0f / 13.0f,5.0f / 8.0f,w,h},
	{2.0f / 13.0f,5.0f / 8.0f,w,h},//front]
	{3.0f / 13.0f,5.0f / 8.0f,w,h},
	{4.0f / 13.0f,5.0f / 8.0f,w,h},
	{5.0f / 13.0f,5.0f / 8.0f,w,h},//back
	{0.0f,7.0f / 8.0f,w,h},
	{1.0f / 13.0f,7.0f / 8.0f,w,h},
	{2.0f / 13.0f,7.0f / 8.0f,w,h},//right
	{3.0f / 13.0f,7.0f / 8.0f,w,h},
	{4.0f / 13.0f,7.0f / 8.0f,w,h},
	{5.0f / 13.0f,7.0f / 8.0f,w,h},//left


};