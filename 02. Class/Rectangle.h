#pragma once
class Rectangle
{
private:
	float x, y; //좌측 상단 좌표(시작점)
	float lx, ly; //우측 하단 좌표
	float width, height;

public:
	Rectangle();
	~Rectangle();

	void read();
	void print();
	float getArea();

	float getX();
	float getY();
	float getW();
	float getH();

	Rectangle operator+(Rectangle& r);
	Rectangle operator/(Rectangle& r);
	bool operator==(Rectangle& r);
};

