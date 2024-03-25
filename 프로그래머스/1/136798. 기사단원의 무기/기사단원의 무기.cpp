
#include <cmath>

int factor(int a) {
	int fact = 0;
	for (int i = 1; i <= sqrt(a); i++) {
		if (a % i == 0) {
			if (a / i == i) fact++;
			else fact += 2;
		}
	}
	return fact;
}

int solution(int number, int limit, int power) {
	int answer = 0;

	for (int i = 1; i <= number; i++) {
		if (factor(i) > limit) {
			answer += power;
		}
		else {
			answer += factor(i);
		}
		
	}

	return answer;
}
