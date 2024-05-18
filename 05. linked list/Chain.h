//Chain.h
#pragma once
#include <iostream>
using namespace std;
template <class T> class Chain; //전방 선언

template <class T> 
class ChainNode
{
	friend class Chain<T>;
public:
	ChainNode(T element = 0, ChainNode* next = 0)
	{
		data = element;
		link = next;
	}
private:
	T data;
	ChainNode<T>* link;
};

template <class T>
class Chain {
public:
	Chain() { first = 0; }; //first를 0으로 초기화하는 생성자
	void InsertBack(const T& e);
	void Concatenate(Chain <T>& b);
	void Reverse();
	void Print();
private:
	ChainNode<T>* first;
	ChainNode<T>* last;
};

template <class T>
void Chain<T>::InsertBack(const T& e) //리스트의 끝에 노드를 삽입하는 함수
{
	if (first) { //공백이 아닌 체인
		last->link = new ChainNode<T>(e);
		last = last->link;
	}
	else first = last = new ChainNode<T>(e); //공백인 체인
}

template <class T>
void Chain<T>::Concatenate(Chain <T>& b) //두 체인의 접합
{//b는 this의 끝에 연결
	if (first) {
		last->link = b.first;
		last = b.last;
	}
	else {
		first = b.first;
		last = b.last;
		b.first = b.last = 0;
	}
}

template <class T>
void Chain<T>::Reverse()//임의의 체인 한개가 역순으로 바뀐다
{
	ChainNode<T>* current = first;
	ChainNode<T>* previous = 0;

	while (current) {
		ChainNode<T>* r = previous;
		previous = current;
		current = current->link;
		previous->link = r;
	}
	first = previous;
}

template <class T>
void Chain<T>::Print()
{
	ChainNode<T>* current = first;
	ChainNode<T>* tmp = current;

	if (!tmp) cout << "There is no in list..." << endl;

	while (tmp) {
		cout << tmp->data << '\t';
		tmp = tmp->link;
	}
}
