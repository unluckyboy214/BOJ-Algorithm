#include<iostream>
#include<queue>

using namespace std;

int m, n; // 가로, 세로
int grid[1001][1001];
int dist[1001][1001];

int dy[] = {-1, 1, 0, 0}; // 상, 하
int dx[] = {0, 0, -1, 1}; // 상, 하

void bfs(queue<pair<int, int>>& q){ // 미리 채운 큐를 참조
    while(!q.empty()){
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();

        for(int d=0 ; d<4 ; d++){ // 상 하 좌 우 탐색
            int next_y = current_y + dy[d];
            int next_x = current_x + dx[d];

            if(next_y < 0 || next_y >= n || next_x <0 || next_x >= m) continue; // 좌표를 벗어나면 넘어감
            if(grid[next_y][next_x] != 0) continue; // -1인 경우 토마토가 없으니 넘어감
            if(dist[next_y][next_x] != -1) continue; // -1이 아닌 경우 이미 방문. 넘어감

            dist[next_y][next_x] = dist[current_y][current_x] +1;
            q.push({next_y, next_x});

        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;

    queue<pair<int, int>> q;

    for(int y = 0; y<n; y++){
        for(int x = 0 ; x<m ; x++){
            cin >> grid[y][x];
            dist[y][x] = -1;

            if(grid[y][x] == 1){
                q.push({y,x});
                dist[y][x]=0;
            }
        }
    }

    bfs(q);

    int answer = 0;

    for(int y=0; y<n ; y++){
        for(int x=0 ; x<m ; x++){
            if(grid[y][x] == 0 && dist[y][x] == -1){
                cout << -1 << "\n";
                return 0;
            }
            answer = max(answer, dist[y][x]);
        }
    }

    cout << answer << "\n";

    return 0;
}