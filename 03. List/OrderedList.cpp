#include "OrderedList.h" //정렬리스트 헤더파일
#include <iostream>
using namespace std;

OrderedList::OrderedList() //생성자
{
	itemCount = 0; //초기 아이템 개수는 0개
	size = 5; //초기 리스트의 크기는 5
	items = new int[size]; //리스트에 공간을 할당
}

OrderedList::~OrderedList()
{
	delete[] items; //클래스가 소멸될 때 할당한 공간의 메모리를 해제
}

int OrderedList::getItem(int index) //index 위치의 값을 반환하는 함수
{
	if (itemCount == 0) { //리스트가 비어있을 때
		cout << "아직 아무것도 저장되지 않은 리스트입니다." << endl; //안내문구 입력
		return 0; //0 반환
	}
	else if (index < 0 || index >= itemCount) return -99999; //잘못된 인덱스 입력 시 -99999 반환
	else return items[index]; //올바른 인덱스 입력 시 해당위치의 값 반환
}

void OrderedList::addItem(int itm) //리스트의 맨 마지막 자리에 아이템을 저장
{
	if (itemCount < size) { //그 인덱스가 사이즈보다 작으면 리스트 확장 불필요
		items[itemCount] = itm; //끝자리에 아이템 추가
		itemCount++; //아이템 개수 변수 1 증가
	}

	else { //그 인덱스가 사이즈와 같거나 크면 리스트 확장 필요
		int* newitems = new int[size * 2]; //2배의 크기로 확장
		for (int i = 0; i < itemCount; i++) 
			newitems[i] = items[i]; //새로만든 더 큰 리스트에 기존 리스트 옮기기
		newitems[itemCount] = itm; //끝자리에 아이템 추가
		itemCount++; //아이템 개수 증가
		size *= 2; //사이즈변수 2배 증가된 값으로 초기화
		delete[] items; //기존에 사용하던 공간의 메모리 해제
		items = newitems; //기존에 사용하던 공간이 새로운 공간을 가리키도록 만듦
	}

	sort(); //정렬
}

int OrderedList::removeAt(int index) //index 위치의 값을 삭제하는 함수
{
	if (itemCount == 0) { //리스트가 비어있을 때
		cout << "아직 아무것도 저장되지 않은 리스트입니다." << endl; //안내문구 입력
		return 0; //0 반환
	}
	else if (index<0 || index>=itemCount) return -99999; //올바르지 않은 위치의 값을 삭제하려할 시 오류 발생
	else { //올바른 위치의 값을 삭제할 때
		int r = items[index]; //삭제하려는 값을 따로 저장
		for (int i = index; i < itemCount - 1; i++)
			items[i] = items[i + 1]; //뒤에 있는 것들을 한칸씩 앞으로 당겨서 저장
		itemCount--; //전체개수 한 개 감소
		sort(); //정렬하기
		return r; //삭제된 값 반환
	}
}

int OrderedList::removeItem(int itm)
{
	if (itemCount == 0) { //리스트가 비어있을 때
		cout << "아직 아무것도 저장되지 않은 리스트입니다." << endl; //안내문구 입력
		return 0; //0 반환
	}

	int index = 0, r = -99999;

	for (int i = 0; i < itemCount; i++) { //앞에서부터 순차적으로 검색
		if (items[i] == itm) {
			index = i;
			r = items[i];
			break; //최초로 일치하는 곳을 삭제하므로 찾자마자 반복문을 멈춘다
		}
	}

	if (r == -99999) return r; //만약 해당 값이 없다면 -99999 반환
	else {
		for (int i = index; i < itemCount - 1; i++)
			items[i] = items[i + 1]; //뒤의 값을 한칸씩 앞으로 당겨서 저장
		itemCount--; //전체 개수 한 개 감소
		sort(); //정렬
		return r; //삭제된 값 반환
	}
}

void OrderedList::concat(OrderedList& olist) //두 개의 리스트를 결합
{
	for (int i = 0; i < olist.itemCount; i++)
		addItem(olist.items[i]); //add함수를 이용하여 리스트 결합
	sort(); //정렬
}

void OrderedList::print() //전체 리스트 출력
{
	if (itemCount == 0) cout << "비어있는 리스트입니다." << endl; //비어있는 리스트일 때 안내출력
	for (int i = 0; i < itemCount; i++)
		cout << "<" << i << "," << items[i] << "> "; //출력
}

void OrderedList::sort() { //정렬
	for (int i = 0; i < itemCount - 1; i++) { //버블정렬 이용
		for (int j = 0; j < itemCount - 1; j++) {
			if (items[j] > items[j + 1]) {
				int tmp = items[j];
				items[j] = items[j + 1];
				items[j + 1] = tmp;
			}
		}
	}
}
