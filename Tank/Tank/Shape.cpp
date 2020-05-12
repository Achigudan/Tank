#include "Shape.h"

bool Shape::checkPointInRect(const Point & point,const Rect & rect)
{
	if (point.getPointx() < rect.getStartPoint().getPointx() || point.getPointx() > rect.getEndPoint().getPointx()
		|| point.getPointy() < rect.getStartPoint().getPointy() || point.getPointy() > rect.getEndPoint().getPointy()) {
		return false;
	}
	else
	{
		return true;
	}
}

bool Shape::checkIntersect(const Rect& rectA,const Rect & rectB)
{
	//judge first rect's four points in second rect's sphere
	if (checkPointInRect(rectA.getStartPoint(), rectB) || checkPointInRect(rectA.getEndPoint(), rectB)
		|| checkPointInRect(rectA.getTRPoint(), rectB) || checkPointInRect(rectA.getBLPoint(), rectB)) {
		return true;
	}
	else {
		return false;	
	}
}
