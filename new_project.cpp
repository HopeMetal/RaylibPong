#include <iostream>
#include "raylib.h"
#include <random>
#include <string>

class Paddle
{
    public:
        Paddle(Rectangle rect)
        {
            this->rect = rect;
        }

        Rectangle rect;
        Vector2 direction = {1, 1};
        int speed = 120;
};

#define paddle_rect(paddle) paddle.rect.x, paddle.rect.y, paddle.rect.width, paddle.rect.height
int main()
{   
    const float ScreenHeight = 640;
    const float ScreenWidth = 720;

    const float ScreenHeightHalf = ScreenHeight/2;
    const float ScreenWidthHalf = ScreenWidth/2;

    InitWindow(ScreenWidth, ScreenHeight, "Raylib Pong");
    SetTargetFPS(60);

    Paddle paddle_player = Paddle(Rectangle{40.0f, ScreenHeight / 2.0f - 40.0f, 20.0f, 80.0f});
    Paddle paddle_enemy = Paddle(Rectangle{ScreenWidth - 60.0f, ScreenHeight / 2.0f - 40.0f, 20.0f, 80.0f});

    paddle_player.speed = 180;

    float ball_init_x = ScreenWidthHalf - 5;
    float ball_init_y = ScreenHeightHalf - 5;
    Paddle ball = Paddle(Rectangle{ball_init_x, ball_init_y, 10, 10});
    
    int player_points = 0;
    int enemy_points = 0;
    while (!WindowShouldClose())
    {
        ball.rect.x += ball.speed*GetFrameTime()*ball.direction.x;
        ball.rect.y += ball.speed*GetFrameTime()*ball.direction.y;

        if(ball.rect.y > ScreenHeight || ball.rect.y < 0)
            ball.direction.y *= -1;
        
        if(CheckCollisionRecs(ball.rect, paddle_player.rect) || CheckCollisionRecs(ball.rect, paddle_enemy.rect))
        {
            ball.direction.x *= -1;
            //ball.direction.y *= -1;
        }

        if(std::rand() % 20 == 0)
            paddle_enemy.rect.y = ball.rect.y;
        if(std::rand() % 200 == 0)
            paddle_enemy.rect.x -= 2;
        if(std::rand() % 10 == 0)
        {
            int random = std::rand() % 5 * 8;
            paddle_enemy.rect.height = 80 + random;
            paddle_enemy.rect.y = paddle_enemy.rect.y - random/2;
        }
            
        
        if(IsKeyDown(KEY_UP))
            paddle_player.rect.y -= paddle_player.speed*GetFrameTime();
        if(IsKeyDown(KEY_DOWN))
            paddle_player.rect.y += paddle_player.speed*GetFrameTime();

        if(ball.rect.x > ScreenWidth)
        {
            ball.rect.x = ball_init_x;
            ball.rect.y = ball_init_y;
            ball.direction.x *= -1;
            player_points += 1;
        }
        if(ball.rect.x < 0)
        {
            ball.rect.x = ball_init_x;
            ball.rect.y = ball_init_y;
            ball.direction.x *= -1;
            enemy_points += 1;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawLine(ScreenWidthHalf, 0, ScreenWidthHalf, ScreenHeight, WHITE);
        // Draw ball
        DrawRectangle(paddle_rect(ball), WHITE);
        // Draw paddles
        DrawRectangle(paddle_rect(paddle_player), WHITE);
        DrawRectangle(paddle_rect(paddle_enemy), WHITE);
        DrawText(std::to_string(player_points).data(), 80, 20, 80, WHITE);
        DrawText(std::to_string(enemy_points).data(), ScreenWidth - 120, 20, 80, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}