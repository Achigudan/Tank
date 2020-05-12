#ifndef __SETTING_H _
#define __SETTING_H_

#include <list>
using namespace std;

class Setting {
private:
	static int m_nLife;       //生命值
	static int m_nGameLevel;  //游戏级别
	static int m_nTankLevel;  //坦克级别
	static int m_nTankNum;    //当前坦克数目
	static int m_nSumScore;   //当前分数
	static int m_nTankScore;  //击毁坦克得分
	static int m_nTankSum;    //击毁坦克数目
public:
	static void NewGameLevel();
	static void TankGamaged();
	static int GetLife() {
		return m_nLife;
	}
	static int GetGameLevel() {
		return m_nGameLevel;
	}
	static int GetTankLevel() {
		return m_nTankLevel;
	}
	static int GetTankNum() {
		return m_nTankNum;
	}
	static int GetSumScore() {
		return m_nSumScore;
	}
	static int GetTnakSum() {
		return m_nTankSum;
	}
	static void Die() {
		m_nLife--;
	}
	static bool m_bNewLevel;
};




#endif