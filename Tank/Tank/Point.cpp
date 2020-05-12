#include "Point.h"

void Point::setPoint(int x, int y)
{
	this->m_center_x = x;
	this->m_center_y = y;
}

void Point::setPointx(int x)
{
	this->m_center_x = x;
}

void Point::setPointy(int y)
{
	this->m_center_y = y;
}

int Point::getPointx() const
{
	return this->m_center_x;
}

int Point::getPointy() const
{
	return this->m_center_y;
}
