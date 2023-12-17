#pragma once

#include <raylib.h>

// WINDOW SETTINGS
#define WINDOW_TITLE "Pong"

// DISPLAY SETTINGS
#define TARGET_FPS 60
#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720

// WINDOW SETTINGS - 2
#define WINDOW_FLAGS FLAG_WINDOW_RESIZABLE

// KEYBIND SETTINGS
#define KEY_EXIT KEY_NULL
#define KEY_PLAYER_1_DOWN KEY_S
#define KEY_PLAYER_1_UP KEY_W
#define KEY_PLAYER_2_DOWN KEY_DOWN
#define KEY_PLAYER_2_UP KEY_UP
#define KEY_START_GAME KEY_SPACE

// GENERIC COLOR SETTINGS
#define BG_COLOR BLACK

// PADDLE SETTINGS
#define PADDLE_W_FACTOR 20
#define PADDLE_H_FACTOR 5
#define PADDLE_PADDING_X_FACTOR 15
#define PADDLE_HEIGHT DEFAULT_WINDOW_HEIGHT / PADDLE_H_FACTOR
#define PADDLE_START_Y DEFAULT_WINDOW_HEIGHT / 2 - PADDLE_HEIGHT / 2
#define PADDLE_1_COLOR RED
#define PADDLE_2_COLOR BLUE
#define PADDLE_MOVEMENT_STEP_FACTOR 64

// BALL SETTINGS
#define BALL_RADIUS_FACTOR 20
#define DEFAULT_BALL_COLOR WHITE
#define BALL_MOVEMENT_STEP_FACTOR 64
#define BALL_START_X DEFAULT_WINDOW_WIDTH / 2
#define BALL_START_Y DEFAULT_WINDOW_HEIGHT / 2
