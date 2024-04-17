#include <iostream>
#include <cstring>

using namespace std;
int map[16][16];
int start_x, start_y;
//상하좌우
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int DFS(int y, int x) {
	// 3 발견시 1리턴
	if (map[y][x] == 3) return 1;

	// 방문시 1 표시
	map[y][x] = 1;

	for (int dir = 0; dir < 4; dir++) {
		int new_y = y + dy[dir];
		int new_x = x + dx[dir];

		// 다음 좌표가 map 안에 있을때 동작
		if (new_x >= 0 && new_x < 16 && new_y >= 0 && new_y < 16 &&map[new_y][new_x] !=1) {
			if (DFS(new_y, new_x) == 1) return 1;
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc;

	for (int i = 0; i < 10; i++) {
		
		cin >> tc;

		//미로 정보 저장
		for (int j = 0; j < 16; j++) {
			string x;
			cin >> x;
			for (int k = 0; k < 16; k++) {
				map[j][k] = x[k] - '0';

				if (map[j][k] == 2) {
					start_y = j;
					start_x = k;
				}
			}

		}

		cout << "#" << tc << " " << DFS(start_y, start_x) <<"\n";
	}


	return 0;
}