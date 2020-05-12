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
	static void graphOpen();          //����Ļ��
	static void graphClose();         //�ر�Ļ��
	static int  getScreenWidth();    
    static int  getScreenHeight();
	static void drawBattleGround();   //�����
	static Rect getBattleGround();    //��ȡ����
	static void showScore();          //���Ʒ���
	static void ShowGameLevel(int nLevel);  //���ƹؿ���ʾ
	static void ShowGameOver();
};   