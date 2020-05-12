#include "Bomb.h"

Bomb::Bomb(){
	this->m_Disappear = false;
	this->m_color = YELLOW;
	this->m_direc = right;  //����̹�˵ķ���
}

Bomb::Bomb(Point pos, BombType type):Bomb(){  //�Ҹо��е���ί�й��캯��  ��������ȫ��һ��
	
	this->m_Pos = pos;
	this->m_type = type;

	switch (m_type) {
	case LARGE:
		m_timer = 8;
		break;
	case SMALL:
		m_timer = 4;
		break;
	default:
		break;
	}
}

void Bomb::tankDisplay(){
	COLORREF fill_color_save = getfillcolor();
	COLORREF color_save = getcolor();

	setfillcolor(m_color);
	setcolor(RED);
	fillcircle(m_Pos.getPointx(),m_Pos.getPointy(),8-m_timer);
	setcolor(color_save);
	setfillcolor(fill_color_save);
}

void Bomb::tankMove(){
	m_timer -= 2;
	if (m_timer < 0) {
		m_Disappear = true;   //�����Ǳ�ըԲ����һ���̶Ⱥ����ʧ
	}
}

void Bomb::Boom(list<Object*>& lstBombs){
	
}

bool Bomb::IsDisappear()
{
	return m_Disappear;
}

void Bomb::setDisappear()
{
}

Rect Bomb::getSphere()
{
	return m_recrSphere;
}


void Bomb::calCulateSphere()
{
}
