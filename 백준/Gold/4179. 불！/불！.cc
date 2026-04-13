#include<iostream>
#include<queue>

using namespace std;

int r, c;
char grid[1001][1001];
int fire_dist[1001][1001]; // 불이 각 칸에 도착하는 시간
int JH_dist[1001][1001]; // 지훈이가 각 칸에 도착하는 시간

int dy[] = {-1, 1, 0 , 0}; // 상, 하
int dx[] = {0, 0, -1 , 1}; // 좌, 우

void bfs(queue<pair<int, int>>& q, int dist[][1001]){
    while(!q.empty()){
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();

        for(int d=0 ; d<4 ; d++){
            int next_y = current_y + dy[d];
            int next_x = current_x + dx[d];

            if(next_y < 0 || next_y >= r || next_x < 0 || next_x >= c) continue; // 범위 밖은 넘어감
            if(grid[next_y][next_x] == '#') continue; // 벽이면 넘어감
            if(dist[next_y][next_x] != -1) continue; // 이미 방문해서 넘어감

            dist[next_y][next_x] = dist[current_y][current_x] +1;
            q.push({next_y, next_x});
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;

    queue<pair<int, int>> fire_q;
    queue<pair<int, int>> JH_q;

    for(int y=0 ; y<r ; y++){
        for(int x=0 ; x<c ; x++){
            cin >> grid[y][x];
            fire_dist[y][x] = -1;
            JH_dist[y][x] = -1;

            if(grid[y][x] == 'J'){ // 지훈이 시작점
                JH_q.push({y,x});
                JH_dist[y][x] = 0;
            }
            
            if(grid[y][x] == 'F'){ // 불 시작점
                fire_q.push({y,x});
                fire_dist[y][x] = 0;
            }
        }
    }

    // 불 이동 경로
    bfs(fire_q, fire_dist);

    // 지훈 이동 경로
    while(!JH_q.empty()){
        int current_y = JH_q.front().first;
        int current_x = JH_q.front().second;
        JH_q.pop();

        for(int d=0 ; d<4 ; d++){
            int next_y = current_y + dy[d];
            int next_x = current_x + dx[d];
            
            // 다음이 격자 밖이면 탈출 성공. 다음에 탈출 성공이기 때문에 출력값에 +1
            if(next_y < 0 || next_y >= r || next_x < 0 || next_x >= c){
                cout << JH_dist[current_y][current_x] + 1;
                return 0;
            }
            if(grid[next_y][next_x] == '#') continue; // 벽이면 넘어감
            if(JH_dist[next_y][next_x] != -1) continue; // 이미 방문한 곳은 넘어감

            int next_time = JH_dist[current_y][current_x] +1;

            // 불이 이미 있고, 지훈이보다 먼저 도착하면 못감
            if(fire_dist[next_y][next_x] != -1 && fire_dist[next_y][next_x] <= next_time) continue;

            JH_dist[next_y][next_x] = next_time;
            JH_q.push({next_y, next_x});
        }
    }

    // 위 bfs에서 종료 안되면 탈출 불가
    cout << "IMPOSSIBLE";

    return 0;
}