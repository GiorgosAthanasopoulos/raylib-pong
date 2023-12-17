#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <raylib.h>

#include "config.h"
#include "types.h"
#include "utils.h"

void Update(Pong *pong)
{
    // update variables that change depending on resolution, when resizing
    int newW = GetRenderWidth();
    int newH = GetRenderHeight();
    if (newW != pong->w || newH != pong->h)
    { // check if window was resized
        UpdatePaddleYAfterResize(&pong->p1y, pong->h, newH);
        UpdatePaddleYAfterResize(&pong->p2y, pong->h, newH);
        UpdateBallPositionAfterResize(&pong->ballX, &pong->ballY, pong->w, pong->h, newW, newH);

        pong->w = newW;
        pong->h = newH;
    }
    pong->paddleW = pong->w / PADDLE_W_FACTOR;
    pong->paddleH = pong->h / PADDLE_H_FACTOR;
    pong->paddlePaddingX = pong->w / PADDLE_PADDING_X_FACTOR;
    pong->paddleMovementStep = pong->w / PADDLE_MOVEMENT_STEP_FACTOR;
    pong->ballSpeed = pong->w / BALL_MOVEMENT_STEP_FACTOR;

    // if KEY_START_GAME is pressed start the game by settings the ball to travel
    // at a random trajectory
    if (IsKeyPressed(KEY_START_GAME) && !pong->gameHasStarted)
    {
        pong->gameHasStarted = true;
        pong->ballAngle = GetRandomValue(0, 360);
        pong->ballSpeedX = cos(pong->ballAngle * DEG2RAD) * pong->ballSpeed;
        pong->ballSpeedY = sin(pong->ballAngle * DEG2RAD) * pong->ballSpeed;
    }
    if (!pong->gameHasStarted)
    {
        return;
    }

    // player 1 movement
    if (IsKeyDown(KEY_PLAYER_1_DOWN))
    {
        pong->p1y += pong->paddleMovementStep;
    }
    if (IsKeyDown(KEY_PLAYER_1_UP))
    {
        pong->p1y -= pong->paddleMovementStep;
    }
    BoundCheckPaddleY(&pong->p1y, pong->h, pong->paddleH);

    // player 2 movement
    if (IsKeyDown(KEY_PLAYER_2_DOWN))
    {
        pong->p2y += pong->paddleMovementStep;
    }
    if (IsKeyDown(KEY_PLAYER_2_UP))
    {
        pong->p2y -= pong->paddleMovementStep;
    }
    BoundCheckPaddleY(&pong->p2y, pong->h, pong->paddleH);

    CheckPlayerWon(pong);
    BoundCheckBall(pong);

    // Apply speed to ball
    pong->ballX += pong->ballSpeedX;
    pong->ballY += pong->ballSpeedY;
}

void Draw(Pong *pong)
{
    BeginDrawing();
    ClearBackground(BG_COLOR);

    // Player 1 - Left side
    DrawRectangle(pong->paddlePaddingX, pong->p1y, pong->paddleW, pong->paddleH, PADDLE_1_COLOR);
    // Player 2 - Right side
    DrawRectangle(pong->w - 2 * pong->paddlePaddingX, pong->p2y, pong->paddleW, pong->paddleH, PADDLE_2_COLOR);
    // Ball
    DrawCircle(pong->ballX, pong->ballY, pong->ballRadius, pong->ballColor);

    // Scores
    char *text = (char *)malloc(sizeof("Score 0: ") + sizeof(char) * 5);
    sprintf(text, "Score 1: %d", pong->score1);
    int fontSize = AssertTextFitsInViewport(text, TEXT_FONT_SIZE, pong->w / MAX_SCORE_TEXT_W_FACTOR, MAX_SCORE_TEXT_H);
    DrawText(text, SCORE_TEXT_PADDING_X, SCORE_TEXT_PADDING_Y, fontSize, PADDLE_1_COLOR);
    sprintf(text, "Score 2: %d", pong->score2);
    fontSize = AssertTextFitsInViewport(text, TEXT_FONT_SIZE, pong->w / MAX_SCORE_TEXT_W_FACTOR, MAX_SCORE_TEXT_H);
    int textW = MeasureText(text, fontSize);
    DrawText(text, pong->w - SCORE_TEXT_PADDING_X - textW, SCORE_TEXT_PADDING_Y, fontSize, PADDLE_2_COLOR);
    free(text);

    // START GAME HINT
    if (!pong->gameHasStarted)
    {
        const char *text = "PRESS SPACEBAR TO START";
        int fontSize =
            AssertTextFitsInViewport(text, TEXT_FONT_SIZE, pong->w / MAX_SCORE_TEXT_W_FACTOR, MAX_SCORE_TEXT_H);
        int textW = MeasureText(text, fontSize);
        DrawText(text, pong->w / 2 - textW / 2, pong->h / 2 - fontSize - pong->ballRadius, fontSize, TEXT_FG_COLOR);
    }

    EndDrawing();
}

int main()
{
    Pong pong = {0};
    pong.w = DEFAULT_WINDOW_WIDTH, pong.h = DEFAULT_WINDOW_HEIGHT;
    pong.ballRadius = pong.w / BALL_RADIUS_FACTOR;
    pong.score1 = 0, pong.score2 = 0;
    ResetGame(&pong);

    SetConfigFlags(WINDOW_FLAGS);
    InitWindow(pong.w, pong.h, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);
    SetExitKey(KEY_EXIT);

    while (!WindowShouldClose())
    {
        Update(&pong);
        Draw(&pong);
    }

    CloseWindow();
    return 0;
}
