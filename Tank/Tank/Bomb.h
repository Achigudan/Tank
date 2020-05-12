#pragma once


#include "Object.h"

enum BombType
{
	LARGE,
	SMALL
};

class Bomb:public Object
{
public:
	Bomb();
	Bomb(Point pos,BombType type);
	~Bomb() {}
	void tankDisplay();
	void tankMove();
	void Boom(list<Object*>& lstBombs);
	bool IsDisappear();
	void setDisappear();
	Rect getSphere();
protected:
	void calCulateSphere();

	BombType m_type;
	int m_timer;

};
