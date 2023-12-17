#pragma once

#include "config.h"
#include "types.h"
#include <cstdio>
#include <raylib.h>

void BoundCheckPaddleY(int *playerY, int winH, int paddleH)
{
    if (*playerY < 0)
    {
        *playerY = 0;
        return;
    }
    if (*playerY > winH - paddleH)
    {
        *playerY = winH - paddleH;
    }
}

void UpdatePaddleYAfterResize(int *paddleY, int oldH, int newH)
{
    if (*paddleY == 0)
    {
        return;
    }
    int oldRatio = oldH / *paddleY;
    if (oldRatio == 0)
    {
        *paddleY = 0;
        return;
    }
    *paddleY = newH / oldRatio;
}

void UpdateBallPositionAfterResize(int *ballX, int *ballY, int oldW, int oldH, int newW, int newH)
{
    if (*ballX != 0)
    {
        int oldXRatio = oldW / *ballX;
        if (oldXRatio == 0)
        {
            *ballX = 0;
            return;
        }
        *ballX = newW / oldXRatio;
    }
    if (*ballY != 0)
    {
        int oldYRatio = oldH / *ballY;
        if (oldYRatio == 0)
        {
            *ballY = 0;
            return;
        }
        *ballY = newH / oldYRatio;
    }
}

void ResetGame(Pong *pong)
{
    pong->p1y = PADDLE_START_Y;
    pong->p2y = PADDLE_START_Y;
    pong->ballX = BALL_START_X;
    pong->ballY = BALL_START_Y;
    pong->ballColor = DEFAULT_BALL_COLOR;
    pong->gameHasStarted = false;
    pong->winner = NO_WINNER;
    pong->ballSpeedX = 0;
    pong->ballSpeedY = 0;
}

int AssertTextFitsInViewport(const char *text, int fontSize, int maxW, int maxH)
{
    int w = MeasureText(text, fontSize);
    while (w > maxW || fontSize > maxH)
    {
        fontSize--;
        w = MeasureText(text, fontSize);
    }
    return fontSize;
}

void CheckPlayerWon(Pong *pong)
{
    if (pong->ballX < pong->paddlePaddingX)
    {
        pong->winner = PLAYER_2;
        pong->score2++;
        ResetGame(pong);
    }
    if (pong->ballX > pong->w - pong->paddlePaddingX)
    {
        pong->winner = PLAYER_1;
        pong->score1++;
        ResetGame(pong);
    }
}

void BoundCheckBall(Pong *pong)
{
    // top or bottom border
    if (pong->ballY < 0 || pong->ballY > pong->h - 2 * pong->ballRadius)
    {
        pong->ballSpeedY = -pong->ballSpeedY;
    }
    // left paddle
    if (pong->ballX < pong->paddlePaddingX + pong->paddleW && pong->ballY > pong->p1y &&
        pong->ballY < pong->p1y + pong->paddleH)
    {
        pong->ballSpeedX = -pong->ballSpeedX;
    }
    // rigt paddle
    if (pong->ballX > pong->w - 2 * pong->paddlePaddingX && pong->ballY > pong->p2y &&
        pong->ballY < pong->p2y + pong->paddleH)
    {
        pong->ballSpeedX = -pong->ballSpeedX;
    }
}
