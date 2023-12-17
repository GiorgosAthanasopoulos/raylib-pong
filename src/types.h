#pragma once

#include <raylib.h>

typedef struct {
  int w,
      h; // current window width and height - can change if user resizes window
  int p1y, p2y; // paddle1Y, paddle2Y

  int paddleW, paddleH;   // paddle width and height
  int paddleMovementStep; // paddle movement step - basically speed
  int paddlePaddingX;     // padding to be applied to the paddle on the X axis -
                      // just so it doesn't touch the border - aesthetic reasons

  bool gameHasStarted;

  int ballX, ballY, ballRadius;
  int ballAngle, ballSpeedX, ballSpeedY,
      ballSpeed; // ballAngle: ball that angle travels at,
                 // ballSpeedX: ballSpeed applied to X axis
                 // ballSpeedY: ballSpeed applied to Y axis
                 // ballSpeed: movement speed for ball
  Color ballColor;

  int score1, score2; // score of player 1 and 2
} Pong;
