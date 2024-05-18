#pragma once
class List //비정렬리스트 헤더
{
private: //private 변수
	int* items; //리스트를 저장할 포인터
	int itemCount; //전체 아이템 개수
	int size; //전체 리스트 크기

public:
	List(); //생성자
	~List(); //소멸자
	int getItem(int index); //index 위치의 값을 반환하는 함수
	void addItem(int itm); //리스트의 끝에 itm을 추가하는 함수
	void insertItem(int index, int itm); //index에 itm을 삽입하는 함수
	int removeAt(int index); //index위치의 값을 삭제하는 함수
	int removeItem(int itm); //특정 itm을 삭제하는 함수
	void concat(List& list); //두 개의 비정렬리스트를 결합하는 함수
	void print(); //전체 리스트 요소를 출력하는 함수
};
