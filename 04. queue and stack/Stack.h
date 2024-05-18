template <class T>

class Stack
{
private:
	T* stack; //스택 원소를 위한 배열
	int top; //톱 원소의 위치
	int capacity; //스택 배열의 크기

public:
	Stack(int stackCapacity = 10); //처음에 크기가 stackCapacity인 공백 스택을 생성
	bool IsEmpty() const; //스택의 원소 수가 0이면 true, 아니면 false를 반환
	T& Top() const; //스택의 톱 원소를 반환
	void Push(const T& item); //스택의 톱에 item을 삽입
	void Pop(); //스택의 톱 원소를 삭제
};

