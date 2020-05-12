#ifndef  __ENEMYTANK_H_
#define  __ENEMYTANK_H_

#include "Tank.h"

#define MAX_STEP 10   //最大步数

class enemyTank :public Tank{
protected:
	void randomTank();
	void randomDir(int style);
	void calCulateSphere();
	int m_stepCnt;

public:
	enemyTank() {
		randomTank();	
	}
	~enemyTank() {}
	void tankDisplay();
	void tankMove();
	void Shoot(list<Object *> & lstBombs);
};



#endif 
