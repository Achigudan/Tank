#include "Graph.h"
#include "setting.h"
Rect Graph::rectScreen;
Rect Graph::rectBattleGround;
char Graph::m_pArray[100];

const int SCORE_LEFT = 810;
const int SCORE_TOP = 5;
void Graph::graphOpen()
{
	rectScreen.set(0,0, SCREEN_WIDTH, SCREEN_HEIGHT);
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	setbkcolor(DARKGRAY);   //背景颜色深灰色
	rectBattleGround.set(BATTLE_GROUND_X1, BATTLE_GROUND_Y1, BATTLE_GROUND_X2, BATTLE_GROUND_Y2);
}

void Graph::graphClose()
{
	closegraph();
}

int Graph::getScreenWidth()
{
	return SCREEN_WIDTH;
}

int Graph::getScreenHeight()
{
	return SCREEN_HEIGHT;
}

void Graph::drawBattleGround()
{
	rectangle(rectBattleGround.getStartPoint().getPointx(), rectBattleGround.getStartPoint().getPointy(),
	   rectBattleGround.getEndPoint().getPointx(), rectBattleGround.getEndPoint().getPointy());
}


Rect Graph::getBattleGround()
{
	return rectBattleGround;
}




void Graph::showScore()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();
	rectangle(SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40);


	RECT r = { SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40 };
	wsprintf((LPSTR)m_pArray, _T("第 %d 关"), Setting::GetGameLevel());
	drawtext((LPCTSTR)m_pArray, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("分  数  :  %d"), Setting::GetSumScore());
	drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("级  别  :  %d"), Setting::GetTankLevel());
	drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("生  命  :  %d"), Setting::GetLife());
	drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("敌人数  :  %d"), Setting::GetTankNum());
	drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

	r.top += 50;
	r.bottom += 50;

	line(SCORE_LEFT, r.bottom, SCREEN_WIDTH - 5, r.bottom);

	r.top += 50;
	r.bottom += 50;
	wsprintf((LPSTR)m_pArray, _T("共击毁敌人数  :  %d"), Setting::GetTnakSum());
	drawtext((LPCTSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);


	setcolor(color_save);
	setfillcolor(fill_color_save);
	
}

void Graph::ShowGameLevel(int nLevel)
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 100,BATTLE_GROUND_Y1 +200,BATTLE_GROUND_X1+700,BATTLE_GROUND_Y1+380);
	LOGFONT fontBak;
	gettextstyle(&fontBak);               // 获取当前字体设置

	LOGFONT f = fontBak;
	f.lfHeight = 48;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("黑体"));  // 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	wsprintf((LPSTR)m_pArray, _T("第 %d 关"), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 300, BATTLE_GROUND_Y1 + 250, (LPSTR)m_pArray);

	f.lfHeight = 18;
	settextstyle(&f);
	wsprintf((LPSTR)m_pArray, _T("按 Enter 键开始"), nLevel);
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPSTR)m_pArray);

	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void Graph::ShowGameOver()
{

	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	rectangle(BATTLE_GROUND_X1 + 100, BATTLE_GROUND_Y1 + 200, BATTLE_GROUND_X1 + 700, BATTLE_GROUND_Y1 + 380);

	LOGFONT fontBak;
	gettextstyle(&fontBak);               // 获取当前字体设置

	LOGFONT f = fontBak;
	f.lfHeight = 48;                      // 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("黑体"));  // 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	settextstyle(&f);                     // 设置字体样式
	wsprintf((LPSTR)m_pArray, _T("GAME OVER"));
	outtextxy(BATTLE_GROUND_X1 + 300, BATTLE_GROUND_Y1 + 250, (LPSTR)m_pArray);

	f.lfHeight = 18;
	settextstyle(&f);
	wsprintf((LPSTR)m_pArray, _T("按 Enter 键退出"));
	outtextxy(BATTLE_GROUND_X1 + 550, BATTLE_GROUND_Y1 + 350, (LPSTR)m_pArray);

	settextstyle(&fontBak);

	setcolor(color_save);
	setfillcolor(fill_color_save);
}
