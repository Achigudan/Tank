#include "Rect.h"
 
void Rect::set(const Point pStart, const Point pEnd)
{
	this->startPoint = pStart;
	this->endPoint = endPoint;
}

void Rect::set(int x1, int y1, int x2, int y2)
{
	this->startPoint.setPoint(x1,y1);
	this->endPoint.setPoint(x2,y2);
}

void Rect::setStartPoint(const Point start)
{
	this->startPoint = start;
}

void Rect::setEndPoint(const Point end)
{
	this->endPoint = end;
}

Point Rect::getStartPoint() const
{
	return startPoint;
}

Point Rect::getEndPoint() const
{
	return endPoint;
}

Point Rect::getTRPoint() const
{
	Point p = startPoint;
	p.setPointx(endPoint.getPointx());
	return p;
}

Point Rect::getBLPoint() const
{
	Point p = startPoint;
	p.setPointy(endPoint.getPointy());
	return p;
}

int Rect::getWidth()
{
	return startPoint.getPointx() - endPoint.getPointx();
}

int Rect::getHeight()
{
	return startPoint.getPointy() - endPoint.getPointy();
}


//·ÀÖ¹Î»ÖÃ´íÎó
void Rect::check()
{
	if (startPoint.getPointx() > endPoint.getPointx() || startPoint.getPointy() > endPoint.getPointy()){
		Point p = startPoint;
		startPoint = endPoint;
		endPoint = p;
	}
}
