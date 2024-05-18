#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"
using namespace std;

int main() {
	Stack<int> s; //크기가 10인 공백 스택 생성

	cout << "================Stack 사용해보기====================" << endl;
	cout << "현재 스택의 상태(비어있을 때: 1, 아닐 때: 0): " << s.IsEmpty() << endl;

	cout << "\n스택에 0부터 9까지의 숫자를 순서대로 푸시합니다..." << endl;
	for (int i = 0; i < 10; i++) s.Push(i); //0부터 9까지의 수를 스택에 넣습니다.
	cout << "\n현재 스택의 상태(비어있을 때: 1, 아닐 때: 0): " << s.IsEmpty() << endl;

	cout << "\n가장 위에 있는 원소를 출력합니다.: " << s.Top() << endl;

	s.Pop();
	cout << "\n가장 위의 원소를 삭제한 뒤, 톱 원소를 반환합니다.: " << s.Top() << endl;

	cout << "\n스택에 있는 모든 숫자를 pop하고 삭제되는 원소를 출력합니다...  :";
	for (int i = 0; i < 9; i++) {
		cout << s.Top() << "   ";
		s.Pop();
	}
	cout << "\n\n현재 스택의 상태(비어있을 때: 1, 아닐 때: 0): " << s.IsEmpty() << endl;


	Queue<int> q; //크기가 10인 공백 큐 생성
	cout << "\n================Queue 사용해보기====================" << endl;
	cout << "현재 큐의 상태(비어있을 때: 1, 아닐 때: 0): " << q.IsEmpty() << endl;

	cout << "\n큐에 0부터 9까지의 숫자를 순서대로 푸시합니다..." << endl;
	for (int i = 0; i < 10; i++) q.Push(i); //0부터 9까지의 수를 큐에 넣습니다.
	cout << "\n현재 큐의 상태(비어있을 때: 1, 아닐 때: 0): " << q.IsEmpty() << endl;

	cout << "\n가장 앞의 원소를 반환합니다.: " << q.Front() << endl;
	cout << "가장 뒤의 원소를 반환합니다.: " << q.Rear() << endl;

	q.Pop();
	cout << "\n가장 앞의 원소를 삭제한 뒤, 앞의 원소를 반환합니다.: " << q.Front() << endl;

	cout << "\n큐에 있는 모든 숫자를 pop하고 삭제되는 원소를 출력합니다...  :";
	for (int i = 0; i < 9; i++) {
		cout << q.Front() << "   ";
		q.Pop();
	}
	cout << "\n\n현재 큐의 상태(비어있을 때: 1, 아닐 때: 0): " << q.IsEmpty() << endl;

	return 0;
}
