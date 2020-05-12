#include "mainTank.h"
#include <list>

//void mainTank::tankDraw()
//{
//
//	setfillcolor(m_color);
//	fillrectangle(m_center_x - 10, m_center_y - 10, m_center_x + 10, m_center_y - 5);
//	fillrectangle(m_center_x - 5, m_center_y - 5, m_center_x + 5, m_center_y + 5);
//	fillrectangle(m_center_x - 10, m_center_y + 5, m_center_x + 10, m_center_y + 10);
//	setlinecolor(m_color);
//	line(m_center_x, m_center_y, m_center_x + 15, m_center_y);
//}
//void mainTank::tankNewPos()
//{
//	switch (m_direc) {
//	case right:
//		m_center_x += 5;
//		if (m_center_x > SCREEN_WIDTH) {
//			m_center_x = 0;
//		}
//		break;
//	case up:
//		m_center_y -= 5;
//		if (m_center_y < 0) {
//			m_center_y = SCREEN_HEIGHT;
//		}
//		break;
//	case down:
//		m_center_y += 5;
//		if (m_center_y > SCREEN_HEIGHT) {
//			m_center_y = 0;
//		}
//		break;
//	case left:
//		m_center_x -= 5;
//		if (m_center_x < 0) {
//			m_center_x = SCREEN_WIDTH;
//		}
//		break;
//	default:break;
//	}
//}
//
//void mainTank::tankRemove()
//{
//	setfillcolor(0);
//	setlinecolor(0);
//	fillrectangle(m_center_x - 10, m_center_y - 10, m_center_x + 10, m_center_y - 5);
//	fillrectangle(m_center_x - 5, m_center_y - 5, m_center_x + 5, m_center_y + 5);
//	fillrectangle(m_center_x - 10, m_center_y + 5, m_center_x + 10, m_center_y + 10);
//	line(m_center_x, m_center_y, m_center_x + 15, m_center_y);
//}
//
//
//
//void mainTank::tankIint()
//{
//	
//	if (m_center_x > SCREEN_WIDTH)
//		m_center_x = 0;
//	if (m_center_x < 0) 
//		m_center_x = SCREEN_WIDTH;
//	m_center_x = rand() % SCREEN_WIDTH;
//	if (m_center_y > SCREEN_HEIGHT)
//		m_center_y = 0;
//	if (m_center_y < 0)
//		m_center_y = SCREEN_HEIGHT;
//	m_center_y = rand() % SCREEN_HEIGHT;
//	m_step = 5;
//	m_color = RGB(255,255,255);  //白色最亮
//	m_direc = right;
//}
//
//void mainTank::tankMove()
//{
//	this->tankRemove();
//	this->tankNewPos();
//	this->tankDraw();
//}
//
//




void mainTank::drawTankBody()
{
	fillrectangle(m_Pos.getPointx() - 6, m_Pos.getPointy() - 6, m_Pos.getPointx() + 6, m_Pos.getPointy() + 6);
	switch(m_direc)
	{
		//上下
	case up:
	case down:
		fillrectangle(m_recrSphere.getStartPoint().getPointx(), m_recrSphere.getStartPoint().getPointy(),
			m_recrSphere.getStartPoint().getPointx()+4, m_recrSphere.getEndPoint().getPointy());
		fillrectangle(m_recrSphere.getEndPoint().getPointx() - 4, m_recrSphere.getStartPoint().getPointy(),
			m_recrSphere.getEndPoint().getPointx(), m_recrSphere.getEndPoint().getPointy());
		break;
		//左右
	case right:
	case left:   
		fillrectangle(m_recrSphere.getStartPoint().getPointx(), m_recrSphere.getStartPoint().getPointy(), 
			m_recrSphere.getEndPoint().getPointx() , m_recrSphere.getStartPoint().getPointy()+4);
		fillrectangle(m_recrSphere.getStartPoint().getPointx(), m_recrSphere.getEndPoint().getPointy()-4,
			m_recrSphere.getEndPoint().getPointx() , m_recrSphere.getEndPoint().getPointy());   
		break;
	default:
		break;
	}

}

void mainTank::calCulateSphere(){
	switch (m_direc){
	case up:
	case down:
		m_recrSphere.set(m_Pos.getPointx() -13, m_Pos.getPointy() - 10, m_Pos.getPointx() + 13, m_Pos.getPointy() + 10);
		break;
	case right:
	case left:
		m_recrSphere.set(m_Pos.getPointx() - 10, m_Pos.getPointy() - 13, m_Pos.getPointx() + 10, m_Pos.getPointy() + 13);
		break;
	default:
		break;
	}
}

void mainTank::setDir(direction dir)
{
	this->m_direc = dir;
}

void mainTank::tankDisplay()
{
	COLORREF fill_color_save = getfillcolor();  //获取当前设备填充颜色
	COLORREF color_save = getcolor();   //获取当前绘图的前景色
		
	setfillcolor(m_color);
	setcolor(m_color);
	drawTankBody();

	switch (m_direc)
	{
	case up:
		line(m_Pos.getPointx(), m_Pos.getPointy(), m_Pos.getPointx(), m_Pos.getPointy()-15);
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
	//setcolor(color_save);
	//setfillcolor(fill_color_save);  
}

void mainTank::tankMove()
{
	switch (m_direc) {
	case up:
		m_Pos.setPointy(m_Pos.getPointy() - m_step);
		if (m_Pos.getPointy() < Graph::getBattleGround().getStartPoint().getPointy()) {
			m_Pos.setPointy(m_Pos.getPointy() + m_step);
		}
		break;
	case down:
		m_Pos.setPointy(m_Pos.getPointy() + m_step);
		if (m_Pos.getPointy() > Graph::getBattleGround().getEndPoint().getPointy()) {
			m_Pos.setPointy(m_Pos.getPointy() - m_step);
		}
		break;
	case left:
		m_Pos.setPointx(m_Pos.getPointx() - m_step);
		if (m_Pos.getPointx() < Graph::getBattleGround().getStartPoint().getPointx()) {
			m_Pos.setPointx(m_Pos.getPointx() + m_step);
		}
		break;
	case right:
		m_Pos.setPointx(m_Pos.getPointx() + m_step);
		if (m_Pos.getPointx() > Graph::getBattleGround().getEndPoint().getPointx()) {
			m_Pos.setPointx(m_Pos.getPointx() - m_step);
		}
		break;
	default:
		break;
	}
	calCulateSphere();
}

void mainTank::Boom(list<Object*>& lstBombs)
{

}

void mainTank::Shoot(list<Object*>& lstBullets){

	Bullet *pBullet = new Bullet(m_Pos,m_direc,m_color);
	lstBullets.push_back(pBullet);
}



mainTank::~mainTank()
{
}
