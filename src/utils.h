#pragma once

#include "config.h"
#include "types.h"

void BoundCheckPaddleY(int *playerY, int winH, int paddleH) {
  if (*playerY < 0) {
    *playerY = 0;
    return;
  }
  if (*playerY > winH - paddleH) {
    *playerY = winH - paddleH;
  }
}

void UpdatePaddleYAfterResize(int *paddleY, int oldH, int newH) {
  if (*paddleY == 0) {
    return;
  }
  int oldRatio = oldH / *paddleY;
  if (oldRatio == 0) {
    *paddleY = 0;
    return;
  }
  *paddleY = newH / oldRatio;
}

void UpdateBallPositionAfterResize(int *ballX, int *ballY, int oldW, int oldH,
                                   int newW, int newH) {
  if (*ballX != 0) {
    int oldXRatio = oldW / *ballX;
    if (oldXRatio == 0) {
      *ballX = 0;
      return;
    }
    *ballX = newW / oldXRatio;
  }
  if (*ballY != 0) {
    int oldYRatio = oldH / *ballY;
    if (oldYRatio == 0) {
      *ballY = 0;
      return;
    }
    *ballY = newH / oldYRatio;
  }
}

void ResetGame(Pong *pong) {
  pong->p1y = PADDLE_START_Y;
  pong->p2y = PADDLE_START_Y;
  pong->ballX = BALL_START_X;
  pong->ballY = BALL_START_Y;
  pong->ballColor = DEFAULT_BALL_COLOR;
  pong->gameHasStarted = false;
}
