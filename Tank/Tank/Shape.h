#ifndef __SHAPE_H_
#define __SHAPE_H_


#include "Rect.h"


class Shape {
public:
	static bool checkPointInRect(const Point &point,const Rect & rect);   //�ж�һ�����Ƿ��ھ��εķ�Χ��
	static bool checkIntersect(const Rect & ,const Rect & rectB);    //�ж����������Ƿ��غ�
};



#endif