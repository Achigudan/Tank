#ifndef __OBJECT_H_
#define __OBJECT_H_

#include <list>
#include "Graph.h"
using namespace std;
enum direction {
	up,
	down,
	left,
	right
};

class Object {
public:
	virtual void tankDisplay() = 0;   //picture
	virtual void tankMove() = 0;      //move
	virtual bool IsDisappear() = 0;   //�ж��Ƿ���ʧ
	virtual void Boom( list<Object *>  &lstBombs) = 0; //��ը
	virtual Rect getSphere() = 0;
	virtual void setDisappear() = 0;
protected:
	virtual void calCulateSphere() = 0;  //����������Χ
	Point m_Pos;       //λ��
	Rect m_recrSphere;   //������Χ
	direction m_direc; //����
	int m_step;        //����
	bool m_Disappear;  //����״̬
	COLORREF m_color;  //��ɫ
	
};




#endif
