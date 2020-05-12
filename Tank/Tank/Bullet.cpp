#include "Bullet.h"

#include "Bomb.h"

Bullet::Bullet()
{
}

Bullet::Bullet(Point pos, direction dir, COLORREF color)
{
	m_Pos = pos;
	m_direc = dir;
	m_color = color;
	m_step = 20;
	m_Disappear = false;

	calCulateSphere();
}

Bullet::~Bullet()
{
}

void Bullet::tankDisplay(){
	COLORREF fill_save_color = getfillcolor();
	COLORREF save_color = getcolor();

	setfillcolor(m_color);
	setcolor(m_color);
	fillcircle(m_Pos.getPointx(),m_Pos.getPointy(),4);

	setcolor(save_color);
	setfillcolor(fill_save_color);

}

void Bullet::tankMove(){
	switch (m_direc) {
	case up:
		m_Pos.setPointy(m_Pos.getPointy() - m_step);
		calCulateSphere();
		if (m_Pos.getPointy() < Graph::getBattleGround().getStartPoint().getPointy()) {
			m_Pos.setPointy(Graph::getBattleGround().getStartPoint().getPointy());
			m_Disappear = true;
		}
		break;
	case down:
		m_Pos.setPointy(m_Pos.getPointy() + m_step);
		calCulateSphere();
		if (m_Pos.getPointy() > Graph::getBattleGround().getEndPoint().getPointy()) {
			m_Pos.setPointy(Graph::getBattleGround().getEndPoint().getPointy());
			m_Disappear = true;
		}
		break;
	case left:
		m_Pos.setPointx(m_Pos.getPointx() - m_step);
		calCulateSphere();
		if (m_Pos.getPointx() < Graph::getBattleGround().getStartPoint().getPointx()) {
			m_Pos.setPointx(Graph::getBattleGround().getStartPoint().getPointx());
			m_Disappear = true;
		}
		break;
	case right:
		m_Pos.setPointx(m_Pos.getPointx() + m_step);
		calCulateSphere();
		if (m_Pos.getPointx() > Graph::getBattleGround().getEndPoint().getPointx()) {
			m_Pos.setPointx(Graph::getBattleGround().getEndPoint().getPointx());
			m_Disappear = true;
		}
		break;
	default:
		break;
	}
}

void Bullet::Boom(list<Object*>& lstBombs)
{
	lstBombs.push_back(new Bomb(m_Pos, SMALL));
}



Rect Bullet::getSphere()
{
	return m_recrSphere;
}

void Bullet::calCulateSphere()
{
	m_recrSphere.set(m_Pos.getPointx() - 2,m_Pos.getPointy() - 2,m_Pos.getPointx() + 2,m_Pos.getPointy() +2);
}
