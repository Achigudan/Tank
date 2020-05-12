#pragma once
#include <graphics.h>
#include "Rect.h"
#define SCREEN_WIDTH       1024
#define SCREEN_HEIGHT      768   

#define BATTLE_GROUND_X1   5
#define BATTLE_GROUND_Y1   5
#define BATTLE_GROUND_X2   800
#define BATTLE_GROUND_Y2   (SCREEN_HEIGHT - BATTLE_GROUND_Y1) 

class Graph {
private:
	static Rect rectScreen;
	static Rect rectBattleGround;

	static char m_pArray[100];
public:
	static void graphOpen();          //创建幕布
	static void graphClose();         //关闭幕布
	static int  getScreenWidth();    
    static int  getScreenHeight();
	static void drawBattleGround();   //活动区域
	static Rect getBattleGround();    //获取区域
	static void showScore();          //绘制分数
	static void ShowGameLevel(int nLevel);  //绘制关卡提示
	static void ShowGameOver();
};   