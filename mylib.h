#ifndef _MYLIB_H_
#define _MYLIB_H_

#include <stdio.h>
#include <conio.h>
#include <ctime> /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần s

#define KEY_NONE	-1

int whereX();
int whereY();
void gotoXY(int x, int y);
void SetColor(WORD color);
void ShowCur(bool CursorVisibility);
int inputKey();

#endif