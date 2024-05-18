#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle() {
	x = 0.0;
	y = 0.0;
	lx = 0.0;
	ly = 0.0;

	width = 0.0;
	height = 0.0;
}

Rectangle::~Rectangle() {
	//객체 사라질 때
}

void Rectangle::read() {

	cout << "x좌표를 입력하세요: ";
	cin >> x;

	cout << "y좌표를 입력하세요: ";
	cin >> y;

	cout << "가로를 입력하세요: ";
	cin >> width;

	cout << "세로를 입력하세요: ";
	cin >> height;

	lx = x + width;
	ly = y + height;
}

void Rectangle::print() {

	cout << "x 좌표: " << x << endl;
	cout << "y 좌표: " << y << endl;

	cout << "가로: " << width << endl;
	cout << "세로: " << height << endl;
}

float Rectangle::getArea() {
	return width * height;
}

float Rectangle::getX() {
	return x;
}

float Rectangle::getY() {
	return y;
}

float Rectangle::getW() {
	return width;
}

float Rectangle::getH() {
	return height;
}

Rectangle Rectangle::operator+(Rectangle& r) {
	Rectangle trect;

	if (x <= r.x) trect.x = x;
	else trect.x = r.x;

	if (y <= r.y) trect.y = y;
	else trect.y = r.y; //시작점 좌표

	if (lx >= r.lx) trect.lx = lx;
	else trect.lx = r.lx;

	if (ly >= r.ly) trect.ly = ly;
	else trect.ly = r.ly; //끝점 좌표

	trect.width = trect.lx - trect.x;
	trect.height = trect.ly - trect.y;

	return trect;
}

Rectangle Rectangle::operator/(Rectangle& r) {
	Rectangle trect;

	if (x < r.x) { 
		if (x + width <= r.x) { //두 직사각형이 가로로 이어져서 혹은 멀리 떨어져서 겹친 부분이 없을 때
			trect.x = 0.0;
			trect.width = 0.0;
			trect.y = 0.0;
			trect.height = 0.0;
			return trect;
		}
	}

	if (r.x < x) {
		if (r.x + r.width <= x) { //두 직사각형이 가로로 이어져서 혹은 멀리 떨어져서 겹친 부분이 없을 때
			trect.x = 0.0;
			trect.width = 0.0;
			trect.y = 0.0;
			trect.height = 0.0;
			return trect;
		}
	}

	if (y < r.y) {
		if (y + height <= r.y) { //두 직사각형이 세로로 이어져서 혹은 멀리 떨어져서 겹친 부분이 없을 때
			trect.x = 0.0;
			trect.width = 0.0;
			trect.y = 0.0;
			trect.height = 0.0;
			return trect;
		}
	}

	if (r.y < y) {
		if (r.y + height <= y) { //두 직사각형이 세로로 이어져서 겹친 부분이 없을 때
			trect.x = 0.0;
			trect.width = 0.0;
			trect.y = 0.0;
			trect.height = 0.0;
			return trect;
		}
	}

	//그 외의 상황
	if (x >= r.x) trect.x = x;
	else trect.x = r.x;

	if (y >= r.y) trect.y = y;
	else trect.y = r.y;

	if (lx <= r.lx) trect.lx = lx;
	else trect.lx = r.lx;

	if (ly <= r.ly) trect.ly = ly;
	else trect.ly = r.ly;

	trect.width = trect.lx - trect.x;
	trect.height = trect.ly - trect.y;

	return trect;
}

bool Rectangle::operator==(Rectangle& r) {
	if (x == r.x && y == r.y && lx == r.lx && ly == r.ly) return true;
	else return false;
}
