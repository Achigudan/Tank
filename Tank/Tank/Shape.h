#ifndef __SHAPE_H_
#define __SHAPE_H_


#include "Rect.h"


class Shape {
public:
	static bool checkPointInRect(const Point &point,const Rect & rect);   //判断一个点是否在矩形的范围内
	static bool checkIntersect(const Rect & ,const Rect & rectB);    //判断两个矩形是否重合
};



#endif