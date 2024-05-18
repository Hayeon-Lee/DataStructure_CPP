//Calculator.h
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include "Stack.h"
#include "String.h"
#include "Queue.h"
#include <string>
using namespace std;

class Calculator {
private:
	List<String> tokens; //입력받은 문자열을 List<String>으로 변환
	int errCode; //에러코드 저장
	int value; //결과값 저장
	String postfix; //후위수식 
	int makePostFix(); //중위->후위수식 변환
	int evaluation(); //후위수식을 계산

public:
	Calculator(); //생성자
	void storeInTokens(const char * expr); //입력받은 값을 토큰에 저장
	int getErrorCode(); //에러코드의 값을 받아옴
	int setExpression(const char* expr); //중위->후위 후 계산 하는 함수
	String getPostFix(); //후위수식의 값을 받아옴
	int getValue(); //결과값을 받아옴
	void printErrorMessage(); //에러메시지를 출력함
	int getOperPrio(char c); //연산자의 우선순위를 반환함
	int compareOper(char op1, char op2); //두 연산자의 우선순위를 비교함
};

Calculator::Calculator() { //생성자
	errCode = 0; //에러코드는 초기값이 0
	value = 0; //값도 초기값이 0
	String init = String((char*)"", 0); //공백으로 초기화
	postfix = init; 
}

int Calculator::makePostFix() { //중위수식 -> 후위수식
	if (errCode != 0) return 1; //괄호 오류 혹은 미확인 연산자 발생

	Stack<char> s = Stack<char>(tokens.getItemCount() + 1); //리스트의 요소 개수+1 만큼 스택 크기 설정

	for (int i = 0; i < tokens.getItemCount(); i++) {
		char ch[1000]; //리스트 요소마다 저장된 스트링을 문자열로 저장할 배열
		strcpy(ch, tokens.getItem(i).getAddress(0)); //리스트 요소를 문자열로 저장
	
		if (ch[0] == '\0') break;
		
		if (ch[0] == '0' || isdigit(ch[0]) != 0) { //만약 숫자일 때
			postfix = postfix.Concat(String((char*)ch, strlen(ch))); //후위수식 표현식에 그대로 넣는다
			postfix = postfix.Concat(String((char*)" ", 1));; //정수 사이마다 공백
		}

		else {
			if (ch[0] == '(') s.Push('('); //여는 괄호일 때 저장한다
			else if (ch[0] == ')') { //닫는 괄호일 때
				while (true) {
					if (s.IsEmpty() == true) { //만약 여는 괄호가 나오기 전에 스택이 빈다면
						errCode = 1; //에러코드 1(괄호 오류)
						return 1; //오류 시 1반환
					}
					if (s.Top() == '(') { //여는괄호가 나오면
						s.Pop(); //스택에서 값을 지우고
						break; //반복문을 멈춘다
					}
					else { //여는 괄호가 아니라면
						postfix = postfix.Concat(String((char*)&s.Top(), 1)); //후위수식 변수에 저장한다
						s.Pop(); //해당 문자를 삭제한다
					}
				}
			}
			else if (ch[0] == '+' || ch[0] == '-' || ch[0] == '*' || ch[0] == '/') { //그 외의 연산자일 때
				if (s.IsEmpty() == true) {
					s.Push(ch[0]); //처음 나온 연산자라면
				}
				else { //아니라면
					while (1) {
						if (s.IsEmpty() == true) { //밑의 과정에서 stack에서 pop한 뒤 스택이 비면 해당 조건문 실행
							s.Push(ch[0]); 
							break;
						}
						int compare = compareOper(ch[0], s.Top()); //우선순위 비교
						if (s.IsEmpty() == false) {
							if (compare == -1) { //스택 안의 연산자가 자신보다 우선순위가 높으면
								postfix = postfix.Concat(String((char*)&s.Top(), 1)); //스택 안의 연산자 후위수식 뒤에 추가
								s.Pop(); //스택에서 삭제
							}
							else if (compare == 0) { //스택 안의 연산자가 자신과 우선순위가 같다면
								postfix = postfix.Concat(String((char*)&s.Top(), 1)); //스택 안의 연산자 후위수식에 추가
								s.Pop(); //스택에서 삭제
								s.Push(ch[0]); //자신을 스택에 넣음
								break;
							}
							else if (compare == 1) { //스택 안의 연산자가 자신의 우선순위보다 낮다면
								s.Push(ch[0]); //자신을 스택에 넣음
								break; //반복문을 멈춤
							}
							else {
								errCode = 2; //목록에 없는 연산자
								return 1; //오류값 반환
							}
						}
					}
				}
			}
			else {
				if (ch[0] == '\0') {
					errCode = 0; //오류 없음
					break; //작업을 끝냄
				}
				if (ch[0] != ' ') {//공백이 아니면
					errCode = 2; //목록에 없는 연산자
					return 1; //오류값 반환
				}
			}
		}
	}

	while (s.IsEmpty() == false) { //스택에 남은 것이 없을 때까지
		postfix = postfix.Concat(String((char*)&s.Top(), 1)); //후위수식에 넣는다
		s.Pop(); //없앤다
	}

	if (s.IsEmpty() == true) {
		postfix = postfix.Concat(String((char*)"\0", 1));
		return 0; //스택이 정상적으로 비워지면 정상값 반환
	}
}

int Calculator::evaluation() {
	if (errCode != 0) return 1; //오류가 있을 시 비정상 값 반환

	tokens.removeAll(tokens.getItemCount());//토큰의 값을 모두 지우기
	storeInTokens(postfix.getAddress(0));//postfix로 토큰만들기
	
	Stack<int> s = Stack<int>(tokens.getItemCount()); //int형으로 스택 재생성(연산을 위해 정수형)

	for (int i = 0; i < tokens.getItemCount(); i++) {
		char c = tokens.getItem(i).strToChar(0); 

		if (c == '\0') break; //후위수식이 끝났을 때

		if (c== '+' || c == '-' || c == '*' || c == '/') { //연산자일 때
			int op1 = 0, op2 = 0;

			if (s.IsEmpty() == true) { //스택에 피연산자가 남아있지 않을 때
				errCode = 5; //피연산자 부족 오류
				return 1;
			}
			else {
				op2 = s.Top();
				s.Pop();
			}//여기까지 실행됐다면 피연산자 1개 확보

			if (s.IsEmpty() == true) { //피연산자가 더 없을 때(피연산자 1개 일때)
				errCode = 5; //피연산자 부족 오류
				return 1;
			}
			else {
				op1 = s.Top();
				s.Pop();
			}//여기까지 실행됐다면 피연산자 모두 정상

			if (c == '+') s.Push(op1 + op2);
			else if (c== '-') s.Push(op1 - op2);
			else if (c == '*') s.Push(op1 * op2);
			else if (c== '/') {
				if (op2 == 0) {
					errCode = 3; //0으로 나눌 시 생기는 오류
					value = -9999;
					break;
				}
				else s.Push(op1 / op2);
			}
			else {
				errCode = 2; //확인할 수 없는 연산자/기호
				value = -9999;
				break;
			}
		}

		else {//숫자일 때
			s.Push(stoi(tokens.getItem(i).getAddress(0))); //정수로 바꾸어 스택에 넣는다
		}
	}
	
	if (errCode != 0) return 1;
	value = s.Top(); //정상적으로 계산했다면 제일 위의 값이 정답
	s.Pop();

	if (s.IsEmpty() == true) return 0; //스택이 비었다면 정상
	else { //삭제 뒤 스택이 비지 않았다면
		errCode = 4; //연산마무리 불가 오류
		value = -9999;
		return 1;
	}
}

void Calculator::storeInTokens(const char* expr) { //사용자 입력을 토큰에 저장하기
	int size = strlen(expr);
	if (size == 0) {
		errCode = 7;
		return;
	}

	Queue<String>q = Queue<String>();
	int leftPrN = 0, rightPrN = 0; //좌괄호, 우괄호의 개수를 저장
	int variable = 0;
	int oper = 0;

	for (int i = 0; i < size + 1; i++) {
		char c = expr[i];

		if (c == '0' || isdigit(c) != 0) {
			q.Push(String((char*)&c, 1)); //숫자일 때
			variable += 1;
		}

		else if (c == ' ' || c == '\0') { //공백일 때 혹은 문장이 끝나면
			if (q.IsEmpty() == false) {//큐가 비어있지 않다면(숫자가 들어있다면)
				String s;
				while (true) {
					if (q.IsEmpty() == true) break;
					s = s.Concat(q.Front());//숫자를 꺼내서 스트링에 저장
					q.Pop();
				}
				tokens.addItem(s); //지금까지 스트링에 저장한 숫자를 토큰에 저장

				if (c == '\0') {
					tokens.addItem(String((char*)&c, 1)); //입력이 끝나면 널문자를 삽입
					break;
				}
			}
		}

		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') { //기호일 때
			if (c == '(') leftPrN += 1; //왼쪽괄호
			else if (c == ')') rightPrN += 1; //오른쪽괄호
			else oper += 1; //연산자 개수
			if (q.IsEmpty() == false) { //큐가 비어있지 않다면(숫자가 있다면)
				String s;
				while (true) { //위의 과정과 동일
					if (q.IsEmpty() == true) break;
					s = s.Concat(q.Front());
					q.Pop();
				}
				tokens.addItem(s); //토큰에 숫자 저장
			}
			tokens.addItem(String((char*)&c, 1)); //토큰에 연산 기호 저장
		}

		else {
			errCode = 2; //확인불가 연산자
			return;
		}

	}
	
	if (leftPrN != rightPrN) errCode = 1; //괄호 오류
	if (variable == 0) errCode = 5;  //피연산자 개수 부족
	if (oper == 0) errCode = 4; //연산자 개수 부족
	if (variable == 0 && oper == 0) errCode = 6; //괄호만 있거나 이상한 기호만 있는 식, 비정상 수식

	return;
}

int Calculator::getErrorCode() {
	return errCode;
}

int Calculator::setExpression(const char* expr) {
	storeInTokens(expr); //expr(사용자입력)을 string으로 변환한 뒤 리스트에 삽입하는 과정
	makePostFix(); //후위수식으로 변환하는 과정

	if (errCode == 0) evaluation(); //만약 후위수식 변환에서 에러코드가 발생하지 않았다면 계산 진행
	else return errCode; //아니라면 에러코드 반환

	if (errCode == 0) return value; //만약 계산에서 에러코드가 발생하지 않았다면 값을 반환
	else return errCode; //아니라면 에러코드 반환
}


String Calculator::getPostFix() {
	return postfix;
}

int Calculator::getValue() {
	return value;
}

void Calculator::printErrorMessage() {
	if (errCode == 0) cout << "정상 식입니다." << endl;
	else if (errCode == 1) cout << "errCode:1 >> 괄호가 서로 짝이 맞는지 확인하세요." << endl;
	else if (errCode == 2) cout << "errCode:2 >> +, -, *, / 외의 연산자, 또는 연산 불가 기호가 존재합니다." << endl;
	else if (errCode == 3) cout << "errCode:3 >> 0으로 나누기를 시도하였습니다." << endl;
	else if (errCode == 4) cout << "errCode:4 >> 연산자의 개수가 부족합니다." << endl;
	else if (errCode == 5) cout << "errCode:5 >> 피연산자의 개수가 부족합니다." << endl;
	else if (errCode == 6) cout << "errCode:6 >> 비정상적인 수식입니다." << endl;
	else if (errCode == 7) cout << "errCode:7 >> 입력값이 없습니다." << endl;
	else cout << "기타에러발생!" << endl;
}

int Calculator::getOperPrio(char c) { //우선순위 반환
	if (c == '*') return 5;
	else if (c == '/') return 5;

	else if (c == '+') return 3;
	else if (c == '-') return 3;

	else if (c == '(') return 1;
	else return -1; //예외 연산자
}

int Calculator::compareOper(char op1, char op2) { //두 연산자의 우선순위를 비교함
	int op1High = getOperPrio(op1);
	int op2High = getOperPrio(op2);

	if (op1High == -1 || op2High == -1) return -2; //예외인 연산자

	if (op1High > op2High) return 1;
	else if (op1High < op2High) return -1;
	else return 0;
}
