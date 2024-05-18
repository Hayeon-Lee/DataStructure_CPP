#pragma once
template <class T>
class Queue
{
private:
	T* queue;
	int front, rear, capacity;

public:
	Queue(int queueCapacity = 10); //크기가 10인 큐를 생성
	bool IsEmpty(); //큐가 비어있는지 여부를 확인, 비어있을 시 True
	T& Front(); //큐의 가장 앞의 원소를 반환
	T& Rear(); //큐의 가장 뒤에 있는 원소를 반환
	void Push(const T& x); //큐의 마지막칸에 x를 삽입
	void Pop(); //큐의 앞 원소를 삭제
};

