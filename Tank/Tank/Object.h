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
	virtual bool IsDisappear() = 0;   //判断是否消失
	virtual void Boom( list<Object *>  &lstBombs) = 0; //爆炸
	virtual Rect getSphere() = 0;
	virtual void setDisappear() = 0;
protected:
	virtual void calCulateSphere() = 0;  //计算势力范围
	Point m_Pos;       //位置
	Rect m_recrSphere;   //势力范围
	direction m_direc; //方向
	int m_step;        //步长
	bool m_Disappear;  //存在状态
	COLORREF m_color;  //颜色
	
};




#endif
