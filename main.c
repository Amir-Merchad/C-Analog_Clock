#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "raylib.h"

const int width = 900;
const int height = 900;
const float radius = ( height / 2 ) - 100;
const float centerX = width / 2;
const float centerY = height / 2;
Vector2 center = {centerX, centerY};
const float hourHandLength = radius * 0.45;
const float minuteHandLength = radius * 0.75;
const float secondHandLength = radius * 0.85;

void DrawClock() {
    DrawCircle(centerX, centerY, radius, RAYWHITE);
    for (int i = 0; i < 60; i++) {
        float angle = i * (2 * PI / 60) - PI / 2;
        float xInner = centerX + radius * 0.92 * cos(angle);
        float yInner = centerY + radius * 0.92 * sin(angle);
        float xOuter = centerX + radius * cos(angle);
        float yOuter = centerY + radius * sin(angle);
        float xInnerExt = centerX + radius * 0.88 * cos(angle);;
        float yInnerExt = centerY + radius * 0.88 * sin(angle);
        Vector2 start = {xInner, yInner};
        Vector2 end = {xOuter, yOuter};
        Vector2 starExt = {xInnerExt, yInnerExt};

        if (i % 5 == 0) {
            DrawLineEx(starExt, end, 5, BLACK);
        } else {
            DrawLineEx( start, end, 3, GRAY);
        }

        if (i % 5 == 0) {
            char buffer[4];
            sprintf(buffer, "%d", i / 5 == 0 ? 12 : i / 5);
            Vector2 textSize = MeasureTextEx(GetFontDefault(), buffer, 20, 1);
            const float xText = centerX + radius * 0.78 * cosf(angle) - textSize.x / 2;
            const float yText = centerY + radius * 0.78 * sinf(angle) - textSize.y / 2;

            DrawText(buffer, xText, yText, 50, BLACK);
        }
    }
}

void DrawHand(float angle, float length, Color color) {
    float endX = centerX + length * cos(angle);
    float endY = centerY + length * sin(angle);
    Vector2 start = {centerX, centerY};
    Vector2 end = {endX, endY};
    DrawLineEx(start, end, 3,color);
}

int main(void) {
    InitWindow(width, height, "Clock");
    InitAudioDevice();

    Sound tick = LoadSound("resources/clock_tick.wav");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        time_t now = time(NULL);
        struct tm *local = localtime(&now);

        static int lastCheckedSecond = -1;
        if (local->tm_sec != lastCheckedSecond) {
            PlaySound(tick);
            lastCheckedSecond = local->tm_sec;
        }

        float hourAngle = (local->tm_hour % 12 + local->tm_min / 60.0f) * (2 * PI / 12) - PI / 2;
        float minuteAngle = (local->tm_min + local->tm_sec / 60.0f) * (2 * PI / 60) - PI / 2;
        float secondAngle = local->tm_sec * (2 * PI / 60) - PI / 2;

        BeginDrawing();
        ClearBackground(BLACK);

        DrawClock();
        DrawHand(hourAngle, hourHandLength, BLACK);
        DrawHand(minuteAngle, minuteHandLength, BLACK);
        DrawHand(secondAngle, secondHandLength, RED);

        Rectangle linkRect = {10, height - 30, 300, 25};
        Vector2 mouse = GetMousePosition();

        if (CheckCollisionPointRec(mouse, linkRect)) {
            DrawText("github.com/Amir-Merchad", 10, height - 30, 20, BLUE);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                OpenURL("https://github.com/Amir-Merchad");
            }
        } else {
            DrawText("github.com/Amir-Merchad", 10, height - 30, 20, LIGHTGRAY);
        }

        DrawTextEx(GetFontDefault(), "Created by Amir Merchad ", (Vector2){width - 180, height - 30}, 14, 1, GRAY);

        EndDrawing();
    }

    UnloadSound(tick);
    CloseAudioDevice();
    CloseWindow();
}
