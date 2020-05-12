#include "enemyTank.h"
#include "Bullet.h"
void enemyTank::randomTank(){

	m_Pos.setPointx(rand() % Graph::getBattleGround().getWidth());
	m_Pos.setPointy(rand() % Graph::getBattleGround().getHeight());
	m_color = WHITE;
	m_direc = (direction)(direction::right + (rand() % 4));
	m_step = 2;
	m_stepCnt = rand();
	
}


//style ==1 与当前一样的方向  0任意
void enemyTank::randomDir(int style) {
	if (style == 1) {
		direction dir;
		while ((dir = (direction)(direction::up + (rand() % 4))) == m_direc){

			//nothing
	    }
		m_direc = dir;
	}
	else{
		m_direc = (direction)(direction::up + (rand() % 4));
	}
}

void enemyTank::calCulateSphere(){
	switch (m_direc) {
	case up:
	case down:
		m_recrSphere.set(m_Pos.getPointx() - 13, m_Pos.getPointy() - 10, m_Pos.getPointx() + 13, m_Pos.getPointy() + 10);
		break;
	case right:
	case left:
		m_recrSphere.set(m_Pos.getPointx() - 10, m_Pos.getPointy() - 13, m_Pos.getPointx() + 10, m_Pos.getPointy() + 13);
		break;
	default:
		break;
	}
}

void enemyTank::tankDisplay()
{
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();
	setfillcolor(m_color);
	setcolor(m_color);   //前景色

	fillrectangle(m_Pos.getPointx() - 6, m_Pos.getPointy() - 6, m_Pos.getPointx() + 6, m_Pos.getPointy() + 6);

	fillrectangle(m_recrSphere.getStartPoint().getPointx(), m_recrSphere.getStartPoint().getPointy(),
		m_recrSphere.getStartPoint().getPointx()+4, m_recrSphere.getStartPoint().getPointy() + 4);
	fillrectangle(m_recrSphere.getEndPoint().getPointx() - 4, m_recrSphere.getStartPoint().getPointy(),
		m_recrSphere.getEndPoint().getPointx(), m_recrSphere.getStartPoint().getPointy()+4);

	fillrectangle(m_recrSphere.getStartPoint().getPointx(), m_recrSphere.getEndPoint().getPointy() - 4,
		m_recrSphere.getStartPoint().getPointx() + 4, m_recrSphere.getEndPoint().getPointy());
	fillrectangle(m_recrSphere.getEndPoint().getPointx() - 4, m_recrSphere.getEndPoint().getPointy()-4,
		m_recrSphere.getEndPoint().getPointx(), m_recrSphere.getEndPoint().getPointy());

	switch (m_direc) {

	case up:
		line(m_Pos.getPointx(), m_Pos.getPointy(), m_Pos.getPointx(), m_Pos.getPointy() - 15);
		break;
	case down:
		line(m_Pos.getPointx(), m_Pos.getPointy(), m_Pos.getPointx(), m_Pos.getPointy() + 15);
		break;
	case left:
		line(m_Pos.getPointx(), m_Pos.getPointy(), m_Pos.getPointx() - 15, m_Pos.getPointy());
		break;
	case right:
		line(m_Pos.getPointx(), m_Pos.getPointy(), m_Pos.getPointx() + 15, m_Pos.getPointy());
		break;
	default:
		break;
	}

}
void enemyTank::tankMove()
{
	switch (m_direc) {
	case up:
		m_Pos.setPointy(m_Pos.getPointy() - m_step);
		if (m_Pos.getPointy() < Graph::getBattleGround().getStartPoint().getPointy()) {
			m_Pos.setPointy(m_Pos.getPointy() + m_step);
			this->randomDir(1);
		}
		break;
	case down:
		m_Pos.setPointy(m_Pos.getPointy() + m_step);
		if (m_Pos.getPointy() > Graph::getBattleGround().getEndPoint().getPointy()) {
			m_Pos.setPointy(m_Pos.getPointy() - m_step);
			this->randomDir(1);
		}
		break;
	case left:
		m_Pos.setPointx(m_Pos.getPointx() - m_step);
		if (m_Pos.getPointx() < Graph::getBattleGround().getStartPoint().getPointx()) {
			m_Pos.setPointx(m_Pos.getPointx() + m_step);
			this->randomDir(1);
		}
		break;
	case right:
		m_Pos.setPointx(m_Pos.getPointx() + m_step);
		if (m_Pos.getPointx() > Graph::getBattleGround().getEndPoint().getPointx()) {
			m_Pos.setPointx(m_Pos.getPointx() - m_step);
			this->randomDir(1);
		}
		break;
	default:
		break;
	}
	calCulateSphere();
	m_stepCnt++;
	if (m_stepCnt >= MAX_STEP) {
		m_stepCnt = 0;
		this->randomDir(0);
	}

	if (m_stepCnt % MAX_STEP_SHOOT == 0) {
		m_bNeedShoot = true;
	}
}

void enemyTank::Shoot(list<Object*>& lstBullets)
{
	Bullet *pBullet = new Bullet(m_Pos,m_direc,m_color);
	lstBullets.push_back(pBullet);

	m_bNeedShoot = false;
}
