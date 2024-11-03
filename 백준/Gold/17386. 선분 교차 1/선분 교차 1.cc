#include <iostream>
#include <algorithm>

using namespace std;

struct P {
	long long x;
	long long y;
};

// CCW 함수: 세 점의 반시계 방향, 시계 방향, 또는 일직선 여부를 판단합니다.
int CCW(P a, P b, P c) {
	long long ret = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (ret > 0) - (ret < 0);  // 반시계 방향이면 1, 시계 방향이면 -1, 일직선이면 0
}

// 두 선분이 교차하는지 확인하는 함수
int intersect(P a, P b, P c, P d) {
	long long ab = CCW(a, b, c) * CCW(a, b, d);
	long long cd = CCW(c, d, a) * CCW(c, d, b);

	// 일반적인 교차 판정
	if (ab == 0 && cd == 0) {
		// 두 선분이 일직선상에 위치할 때 겹치는지 추가로 확인합니다
		if (a.x > b.x) swap(a, b);
		if (c.x > d.x) swap(c, d);
		return !(b.x < c.x || d.x < a.x);
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	P p1, p2, p3, p4;
	cin >> p1.x >> p1.y >> p2.x >> p2.y;
	cin >> p3.x >> p3.y >> p4.x >> p4.y;

	cout << intersect(p1, p2, p3, p4) << '\n';

	return 0;
}
