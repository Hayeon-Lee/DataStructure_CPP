#include <iostream>
#include "List.h" //비정렬리스트의 헤더파일
#include "OrderedList.h" //정렬리스트의 헤더파일
using namespace std;

int main() {
	List list1 = List(); //작업을 하는 비정렬리스트
	List list2 = List(); //합치는 작업을 위해 만든 비정렬리스트
	
	OrderedList olist1 = OrderedList(); //작업을 하는 정렬리스트
	OrderedList olist2 = OrderedList(); //합치는 작업을 위해 만든 비정렬리스트

	int optlist = 0, optfunc = 0, index, itm, result; //리스트옵션, 함수옵션, 사용자입력 인덱스, 사용자입력 아이템, 함수실행결과

	for (int i = 0; i < 20; i++) { //concat을 실험해볼 리스트
		list2.addItem(i); //비정렬리스트2
		olist2.addItem(i); //정렬리스트2
	}

	cout << "순서가 없는 리스트(1), 정렬된 리스트(2) 중 하나를 고르세요.: "; //리스트 선택
	cin >> optlist; //사용자 입력

	if (optlist == 1) { //비정렬 리스트 선택 시
		cout << "순서가 없는 리스트를 고르셨습니다." << endl;
		while (optfunc != -1) {
			cout << "-1(종료), 1(getItem), 2(addItem), 3(insertItem), 4(removeAt), 5(removeItem), 6(concat), 7(print) 중 하나를 고르세요.: ";
			cin >> optfunc; //사용자가 원한는 실행 함수를 고를 수 있게 함
			if (optfunc == -1) cout << "프로그램을 종료합니다." << endl;

			switch (optfunc) {
			case 1: //특정 위치의 아이템 값을 얻는 함수 실행
				cout << "값을 얻기 원하는 인덱스를 입력하세요.: ";
				cin >> index;
				result = list1.getItem(index);
				cout << "해당 위치의 값은 " << result << "입니다.(-99999일 경우 잘못된 인덱스)" << endl;
				break;

			case 2: //끝자리에 값을 추가하는 함수 실행
				cout << "추가하고자 하는 값을 입력하세요.: ";
				cin >> itm;
				list1.addItem(itm);
				break;

			case 3: //특정 위치에 아이템 값을 추가하는 함수 실행
				cout << "어떤 위치에 추가하고 싶은지 입력하세요.: ";
				cin >> index;
				cout << "추가하고자 하는 값을 입력하세요.: ";
				cin >> itm;
				list1.insertItem(index, itm);
				break;

			case 4: //특정 위치의 값을 삭제하는 함수 실행
				cout << "어떤 위치의 값을 삭제하고 싶은지 입력하세요.: ";
				cin >> index;
				result = list1.removeAt(index);
				cout << "삭제된 값은 " << result << "입니다.(-99999일 경우 잘못된 인덱스)" << endl;
				break;

			case 5: //특정 값을 삭제하는 함수 실행
				cout << "어떤 값을 삭제하고 싶은지 입력하세요.: ";
				cin >> itm;
				result = list1.removeItem(itm);
				cout << "삭제된 값은 " << result << "입니다.(-99999일 경우 잘못된 값)" << endl;
				break;

			case 6: //list1 과 list2를 합치는 함수 실행
				cout << "두 개의 리스트를 합치겠습니다." << endl;
				list1.concat(list2);
				break;

			case 7: //현 리스트 상태를 출력하는 함수 실행
				cout << "리스트 현황입니다." << endl;
				list1.print();
				cout << endl;
				break;
			}
		}
	}
	
	else if (optlist == 2) { //정렬리스트 선택 시
		cout << "순서가 있는 리스트를 고르셨습니다." << endl;
		while (optfunc != -1) {
			cout << "-1(종료), 1(getItem), 2(addItem), 3(removeAt), 4(removeItem), 5(concat), 6(print) 중 하나를 고르세요.: ";
			cin >> optfunc;
			if (optfunc == -1) cout << "프로그램을 종료합니다." << endl;

			switch (optfunc) {
			case 1: //특정 위치의 값을 얻는 함수 실행
				cout << "값을 얻기 원하는 인덱스를 입력하세요.: ";
				cin >> index;
				result = olist1.getItem(index);
				cout << "해당 위치의 값은 " << result << "입니다.(-99999일 경우 잘못된 인덱스)" << endl;
				break;

			case 2: //끝자리에 원소를 추가하는 함수 실행
				cout << "추가하고자 하는 값을 입력하세요.: ";
				cin >> itm;
				olist1.addItem(itm);
				break;

			case 3: //특정 위치의 값을 삭제하는 함수 실행
				cout << "어떤 위치의 값을 삭제하고 싶은지 입력하세요.: ";
				cin >> index;
				result = olist1.removeAt(index);
				cout << "삭제된 값은 " << result << "입니다.(-99999일 경우 잘못된 인덱스)" << endl;
				break;

			case 4: //특정 값을 삭제하는 함수 실행
				cout << "어떤 값을 삭제하고 싶은지 입력하세요.: ";
				cin >> itm;
				result = olist1.removeItem(itm);
				cout << "삭제된 값은 " << result << "입니다.(-99999일 경우 잘못된 값)" << endl;
				break;

			case 5: //olist1과 olist2를 합치는 함수 실행
				cout << "두 개의 리스트를 합치겠습니다." << endl;
				olist1.concat(olist2);
				break;

			case 6: //리스트 현황을 출력하는 함수 실행
				cout << "리스트 현황입니다." << endl;
				olist1.print();
				cout << endl;
				break;
			}
		}
	}

	else cout << "잘못된 옵션입니다. 프로그램을 재시작하세요." << endl; //1과 2중 어떤 것도 고르지 않았을 때
	return 0;
}
