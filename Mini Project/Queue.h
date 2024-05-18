//Queue.h
#pragma once
#include <algorithm>
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

template <class T>
Queue<T>::Queue(int queueCapacity) :capacity(queueCapacity) {
	if (capacity < 1) throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = 0;
}

template <class T>
inline bool Queue<T> ::IsEmpty() { return front == rear; }

template <class T>
inline T& Queue<T> ::Front()
{
	if (IsEmpty()) throw "Queue is empty. No front element";
	return queue[(front + 1) % capacity];
}

template <class T>
inline T& Queue<T>::Rear()
{
	if (IsEmpty()) throw "Queue is empty. No rear element";
	return queue[rear];
}

template <class T>
void Queue<T> ::Push(const T& x)
{
	if ((rear + 1) % capacity == front)
	{
		T* newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (start < 2) {
			copy(queue + start, queue + start + capacity - 1, newQueue);
		}
		else {
			copy(queue + start, queue + capacity, newQueue);
			copy(queue, queue + rear + 1, newQueue + capacity - start);
		}

		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;
	}

	rear = (rear + 1) % capacity;
	queue[rear] = x;
}

template <class T>
void Queue<T> ::Pop() {
	if (IsEmpty()) throw "Queue is empty. Cannot delete.";
	front = (front + 1) % capacity;
	queue[front].~T();
}
