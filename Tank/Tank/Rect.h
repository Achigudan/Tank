#ifndef __RECT_H_
#define __RECT_H_
#include "Point.h"

class Rect {

public:
	Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0):startPoint(x1,y1),endPoint(x2,y2) {}
	Rect(const Point p1,const Point p2):startPoint(p1),endPoint(p2) {}
	~Rect() {}

	Rect& operator=(const Rect&r) {
		this->startPoint = r.startPoint;
		this->endPoint = r.endPoint;
		return *this;
	}


	void set(const  Point pStart,const  Point pEnd);
	void set(int x1,int y1,int x2,int y2);

	void setStartPoint(const Point start);
	void setEndPoint(const Point end);
	Point getStartPoint() const ;
	Point getEndPoint() const ;
	Point getTRPoint() const;  //get top right Point
	Point getBLPoint() const;  //get bottom left Point 


	int getWidth();
	int getHeight();

private:
	void check();
	Point startPoint;
	Point endPoint;
};



#endif
