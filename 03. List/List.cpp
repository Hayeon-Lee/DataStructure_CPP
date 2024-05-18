#include "List.h" //비정렬리스트 헤더파일
#include <iostream>
using namespace std;

List::List() //생성자
{
	itemCount = 0; //초기 아이템 개수는 0개
	size = 5; //초기 리스트의 크기는 5
	items = new int[size]; //리스트에 공간을 할당
}

List::~List()
{
	delete[] items; //클래스가 소멸될 때 할당한 공간의 메모리를 해제
}

int List::getItem(int index) //index 위치의 값을 반환하는 함수
{
	if (itemCount == 0) { //리스트가 비어있을 때
		cout << "아직 아무것도 저장되지 않은 리스트입니다." << endl; //안내문구 입력
		return 0; //0 반환
	}
	else if (index <0 || index >= itemCount) return -99999; //잘못된 인덱스 입력 시
	else return items[index]; //올바른 인덱스 입력 시
}

void List::addItem(int itm) //리스트의 맨 마지막 자리에 아이템을 저장
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
		items = newitems; //기존에 사용하던 공간이 새로운 공간을 가리키도록 함
	}
}

void List::insertItem(int index, int itm) //index위치에 itm을 삽입하는 함수
{
	if (index < 0 || index > itemCount) { //아이템 개수보다 적은 범위에서 저장하지 않을 때
		cout << "잘못된 자리입니다. 삽입이 이루어지지 않았습니다." << endl;
		return;
	}

	if (itemCount < size) { //올바른 위치에 저장하면서 저장 시 배열의 크기보다 커지지 않을 때
		for (int i = itemCount - 1; i >= index; i--) {
			items[i + 1] = items[i]; //한칸씩 뒤로 밀어줌.
		}
		items[index] = itm; //원하는 위치에 삽입
		itemCount++; //전체 개수 한 개 증가
	}

	else { //올바른 위치에 저장하지만 저장 시 배열의 크기보다 커질 때
		int* newitems = new int[size * 2]; //새로운 배열 생성
		for (int i = 0; i < itemCount; i++) //기존 배열 대입
			newitems[i] = items[i];

		for (int i = itemCount - 1; i >= index; i--) { //한칸씩 뒤로 밀어줌
			newitems[i + 1] = newitems[i];
		}
		newitems[index] = itm; //원하는 위치에 삽입
		itemCount++; //총 개수 한 개 증가
		size *= 2; //사이즈 초기화
		delete[] items; //기존 공간 메모리 해제
		items = newitems; //기존공간이 새로운 공간 가리키도록 함
	}
}

int List::removeAt(int index) { //index위치의 값을 삭제하는 함수

	if (itemCount == 0) { //리스트가 비어있을 때
		cout << "아직 아무것도 저장되지 않은 리스트입니다." << endl; //안내문구 입력
		return 0; //0 반환
	}
    else if (index<0 || index>=itemCount) return -99999; //올바르지 않은 위치의 값을 삭제하려 할 때
	else { //올바른 위치의 값을 삭제할 때
		int r = items[index]; //삭제하려는 값을 따로 저장
		for (int i = index; i < itemCount - 1; i++) //뒤에 있는 것들 한칸씩 앞으로 당김
			items[i] = items[i + 1];
		itemCount--; //전체 개수 한 개 감소
		return r; //삭제되는 값 반환
	}
}

int List::removeItem(int itm) { //특정 값을 삭제하는 함수

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

	if (r == -99999) return r; //해당 값이 없으니 -99999반환
	else { //해당 값이 있으면
		for (int i = index; i < itemCount - 1; i++) 
			items[i] = items[i + 1]; //뒤의 값을 한칸씩 당김
		itemCount--; //전체 개수 한 개 감소
		return r; //삭제된 값 반환
	}
}

void List::concat(List& list) //두 개의 리스트를 결합
{
	for (int i = 0; i < list.itemCount; i++)
		addItem(list.items[i]); //add함수를 이용하여 리스트 결합
}

void List::print() //전체 리스트 출력 
{
	if (itemCount == 0) cout << "비어있는 리스트입니다." << endl;//비어있을 때
	for (int i = 0; i < itemCount; i++)
		cout << "<" << i << "," << items[i] << "> ";
}
