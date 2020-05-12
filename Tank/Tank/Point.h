#ifndef __POINT_H_
#define __POINT_H_

class Point
{
public:
	Point(int x = 0, int y = 0) :m_center_x(x),m_center_y(y) {}
	~Point() {}

	//重载 = 运算符  使得point对象可以进行对象参数传递
	Point& operator=(const Point &p) {
		this->m_center_x = p.m_center_x;
		this->m_center_y = p.m_center_y;
		return *this;
	}

	void setPoint(int x, int y);
	void setPointx(int x);
	void setPointy(int y);

	int getPointx() const;
	int getPointy() const;
private:
	int m_center_x;
	int m_center_y;
};


#endif