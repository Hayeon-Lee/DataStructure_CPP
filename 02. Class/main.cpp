#include <iostream>
#include "Rectangle.h"

using namespace std;

ostream& operator<<(ostream& os, Rectangle& r) {
	os << "x 좌표: " << r.getX() << endl;
	os << "y 좌표: " << r.getY() << endl;

	os << "가로: " << r.getW() << endl;
	os << "세로: " << r.getH() << endl;

	os << "넓이: " << r.getArea() << endl;

	return os;
}

int main() {
	Rectangle rect1;
	Rectangle rect2;

	Rectangle uni;
	Rectangle inter;

	cout << "rect1 입력\n";
	rect1.read();

	cout << "\nrect2 입력\n";
	rect2.read();
	
	cout << "\n입력하신 두 직사각형의 정보들입니다.\n";
	
	cout << "rect1\n";
	rect1.print();

	cout << "\nrect2\n";
	rect2.print();
	
	cout << "\n입력하신 두 직사각형의 넓이들은 아래와 같습니다.\n";
	cout << "rect1 의 넓이는 " << rect1.getArea() << " 입니다.\n";
	cout << "rect2 의 넓이는 " << rect2.getArea() << " 입니다.\n";

	cout << "\n두 직사각형의 합집합 직사각형의 정보는 아래와 같습니다.\n";
	uni = rect1 + rect2;
	cout << uni;

	cout << "\n두 직사각형의 교집합 직사각형의 정보는 아래와 같습니다.\n";
	inter = rect1 / rect2;
	cout << inter;
	if (inter.getArea() == 0.0) cout << "두 직사각형은 겹치는 부분이 없으므로 넓이가 0입니다.\n";

	cout << "\n두 직사각형은 ";
	if ((rect1 == rect2) == true) cout << "동일한 직사각형입니다.\n";
	else cout << "동일한 직사각형이 아닙니다.\n";
}
