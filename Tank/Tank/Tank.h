#pragma once
#include "Object.h"
#include "Bomb.h"
#include <list>
using namespace std;

#define MAX_STEP_TURN   20
#define MAX_STEP_SHOOT  15


class Tank: public Object {
public:
	Tank() {
		m_Pos.setPoint(300,300);
		this->calCulateSphere();

		m_color = YELLOW;
		m_direc = direction::right;
		m_step = 4;
		m_Disappear = false;
		m_bNeedShoot = false;
	}
	~Tank() {}

	virtual void tankDisplay() {

	}

	virtual void tankMove() {

	}

	virtual void Shoot(list<Object *> &lstBullets) {

	}

	virtual bool IsDisappear() {
		return m_Disappear;
	}

	virtual void Boom(list<Object *> & lstBombs) {
		lstBombs.push_back(new Bomb(m_Pos, LARGE));

	}
	virtual Rect getSphere() {
		return m_recrSphere;
	}

	virtual void setDisappear() {
		m_Disappear = true;
	}
	bool NeedShoot()
	{
		return m_bNeedShoot;
	}
protected:
	virtual void calCulateSphere() {

	}
	bool m_bNeedShoot; 

};