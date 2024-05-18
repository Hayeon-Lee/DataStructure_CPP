#pragma once
class OrderedList //정렬리스트 헤더
{
private:
	int* items; //리스트를 저장할 포인터
	int itemCount; //전체 아이템 개수
	int size; //전체 리스트 크기
	void sort(); //리스트 내부 원소 정렬 함수

public:
	OrderedList(); //생성자
	~OrderedList(); //소멸자
	int getItem(int index); //index위치의 값을 반환하는 함수 
	void addItem(int itm); //itm을 끝자리에 추가하는 함수
	int removeAt(int index); //index위치의 값을 삭제하는 함수
	int removeItem(int itm); //특정 itm을 삭제하는 함수
	void concat(OrderedList& olist); //두 개의 정렬리스트를 합치는 함수
	void print(); //전체 리스트 요소를 출력하는 함수
};

