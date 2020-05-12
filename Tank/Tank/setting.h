#ifndef __SETTING_H _
#define __SETTING_H_

#include <list>
using namespace std;

class Setting {
private:
	static int m_nLife;       //����ֵ
	static int m_nGameLevel;  //��Ϸ����
	static int m_nTankLevel;  //̹�˼���
	static int m_nTankNum;    //��ǰ̹����Ŀ
	static int m_nSumScore;   //��ǰ����
	static int m_nTankScore;  //����̹�˵÷�
	static int m_nTankSum;    //����̹����Ŀ
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