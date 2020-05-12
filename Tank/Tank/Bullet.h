#ifndef  __BULLET_H_
#define  __BULLET_H_
#include "Object.h"
#include "Bomb.h"
using namespace std;

class Bullet:public Object {
public:
	Bullet();
	Bullet(Point pos,direction dir,COLORREF color);
	~Bullet();
	void tankDisplay();
	void tankMove();
	void Boom(list<Object*>& lstBombs);
	bool IsDisappear() {
		return m_Disappear;
	}

	Rect getSphere();
	void setDisappear() {
		m_Disappear = true;
	}
protected:
	void calCulateSphere();
};


#endif