#pragma once

#include "Tank.h"
#include "Bullet.h"
class mainTank :public Tank{
protected:
	void drawTankBody();
	void calCulateSphere();
public:
	mainTank() {
		m_Pos.setPoint(300,300);

		this->calCulateSphere();

		m_color = YELLOW;
		m_direc = direction::right;
		m_step = 4;
	}
	~mainTank();
	void setDir(direction dir);
	void tankDisplay();
	void tankMove();
	void Boom(list<Object *> & lstBombs);

	void Shoot(list<Object *> &lstBullets);
};