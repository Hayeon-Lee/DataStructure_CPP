//main.cpp
#include "Calculator.h"
using namespace std;

int main() {
	cout << "=======================계산기 프로그램입니다. =========================" << endl;
	cout << "========================== <주의사항> =============================" << endl;
	cout << "1. 프로그램 종료는 n또는 N을 입력하세요." << endl;
	cout << "2. 지원되는 연산자는 괄호와 +,-,*,/입니다." << endl;
	cout << "3. 자연수만 계산할 수 있습니다. 음수 입력 시 오류가 발생합니다." << endl;
	cout << "4. 오류 코드는 아래와 같습니다." << endl;
	cout << "     1) errCode 1: 괄호 오류" << endl;
	cout << "     2) errCode 2: 연산 불가 기호 오류" << endl;
	cout << "     3) errCode 3: 0으로 나누기를 시도" << endl;
	cout << "     4) errCode 4: 연산자 개수 부족" << endl;
	cout << "     5) errCode 5: 피연산자 개수 부족" << endl;
	cout << "     6) errCode 6: 정상적이지 않은 수식" << endl;
	cout << "     7) errCode 7: 아무것도 입력하지 않음" << endl;
	cout << "================================================================\n" << endl;

	while (true) {
		cout << "==================================================================" << endl;
		cout << "수식을 입력하시오(종료는 n 또는 N): ";

		char expr[1000];
		Calculator c;

		cin.getline(expr, 1000);

		if (expr[0] == 'n' || expr[0] == 'N') {
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		}

		c.setExpression(expr);
		if (c.getErrorCode() == 0) {
			String posfix = c.getPostFix();
			cout << "후위표기식 : ";
			posfix.print();
			cout << "결과값 : " << c.getValue() << endl;
		}
		else {
			c.printErrorMessage();
		}
		cin.clear();
	}
}
