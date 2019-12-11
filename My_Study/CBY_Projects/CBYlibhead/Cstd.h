#pragma once
#include <windows.h>
#include <tchar.h>
#include <iostream>

#define CBY_WINDOWHEAD int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
#define CBY_WINDOWRUN(Class,b,c) {Class game; if(game.InitWindow(L#b,L#c)){game.GameRun();} return 1;
#define CBY_WINDOWTAIL }
#define CBY_RUN(Class,b,c) CBY_WINDOWHEAD CBY_WINDOWRUN(Class,b,c) CBY_WINDOWTAIL

