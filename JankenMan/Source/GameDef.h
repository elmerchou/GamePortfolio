#pragma once

enum Janken {//じゃんけん種類列挙
	gu,
	choki,
	pan,
};

enum Outcome {//結果列挙
	lose,
	draw,
	win,
};

const Vector2f winPosition[5] = {//連勝ライト位置
	{-147.0f,256.0f},
	{-80.0f,285.0f},
	{0.0f,292.0f},
	{76.0f,285.0f},
	{146.0f,259.0f},
};

const Vector2f panelPosition[3] = {//結果パネル位置
	{-146.0f,197.0f},
	{1.0f,234.0f},
	{146.0f,197.0f},
};

const Vector2f selectedPosition[3] = {//じゃんけんボタン位置
	{-106.0f,-289.0f},
	{4.0f,-289.0f},
	{114.0f,-289.0f},
};

const Vector2f startPositionLight = { -204.0f,-289.0f };//スタートボタン中心位置

const Vector2f startPosition[2] = {//スタートボタン位置
	{-240.0f,-315.0f},
	{-165.0f,-265.0f},
};


const Vector2f guPosition[2] = {//グボタン位置
	{-135.0f,-315.0f},
	{-70.0f,-265.0f},
};

const Vector2f chokiPosition[2] = {//チョキボタン位置
	{-25.0f,-315.0f},
	{40.0f,-265.0f},
};

const Vector2f panPosition[2] = {//パンボタン位置
	{85.0f,-315.0f},
	{150.0f,-265.0f},
};