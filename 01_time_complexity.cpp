#include <iostream>
#include <ctime>
using namespace std;

void multiple(int n) {
	int cnt = 0, ncnt = 0, i = 0, j = 0;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= 9; j++) {
			if (i * j % 5 == 0) cnt++;
			else ncnt++;
		}
	}

	cout << "\n5의 배수 개수는 " << cnt << endl;
	cout << "5의 배수가 아닌 수의 개수는 " << ncnt << "\n" << endl;
}

int main() {
	clock_t start, end;
	double time;

	start = clock();
	cout << "프로그램 실행시간 측정을 시작합니다." << endl;
	cout << "1부터 천만단까지의 구구단 중 5의 배수와 아닌 수들의 개수를 셉니다." << endl;
	multiple(10000000);
	end = clock();

	time = (double)(end - start);
	cout << "프로그램 실행에 걸린 시간(ms) : " << time << " 마이크로초" << endl;
	time /= CLOCKS_PER_SEC;
	cout << "프로그램 실행에 걸린 시간(s) : " << time << " 초" << endl;
	return 0;
}
