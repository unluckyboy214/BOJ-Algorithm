#include<iostream>
#include<queue>
#include<cstring> // memset 사용

using namespace std;

int l; // 체스판 크기
int dist[301][301];

// 나이트의 이동 경로
int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs(int start_y, int start_x){
    queue<pair<int, int>> q;
    q.push({start_y, start_x}); // 첫 시작점 큐 삽입
    dist[start_y][start_x] = 0; // 시작점 거리 0

    while(!q.empty()){
        int current_y = q.front().first; // 현재 나이트 y위치
        int current_x = q.front().second; // 현재 나이트 x위치
        q.pop(); // 현재로 다시 돌아오지 x

        for(int d=0 ; d<8 ; d++){
            int next_y = current_y + dy[d];
            int next_x = current_x + dx[d]; 

            if(next_y < 0 || next_y >= l || next_x < 0 || next_x >= l) continue; // 범위 밖
            if(dist[next_y][next_x] != -1) continue; // 이미 감

            dist[next_y][next_x] = dist[current_y][current_x] +1 ;
            q.push({next_y, next_x});

        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; // TC 개수
    cin >> T;
    
    while(T--){
        int start_y, start_x, end_y, end_x;
        cin >> l;
        cin >> start_y >> start_x;
        cin >> end_y >> end_x;

        memset(dist, -1, sizeof(dist)); // TC마다 초기화

        bfs(start_y, start_x); // bfs로 이동 횟수 파악

        cout << dist[end_y][end_x] << "\n";
    }

    return 0;
}