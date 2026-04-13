#include<iostream>
#include<queue>

using namespace std;

int n, m;
int grid[501][501];
bool visited[501][501];

int dy[] = {-1, 1, 0, 0}; // 상, 하
int dx[] = {0, 0, -1, 1}; // 좌, 우

// bfs로 연결된 1 전부 탐색 후 넒이 반환
int bfs(int y, int x){
    queue<pair<int, int>>q;

    q.push({y, x});
    visited[y][x] = true;
    int area = 0; // 넓이 반환

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        area++;

        for(int d = 0; d<4 ; d++){ // 상, 하, 좌, 우 4번 탐색
            int ny = cy + dy[d]; // 상, 하
            int nx = cx + dx[d]; // 좌, 우

            if(ny < 0 || ny >= n || nx < 0 || nx >= m){
                continue; // 범위 밖인 경우 넘어감 
            } 
            if(grid[ny][nx] == 0){
                continue; // 0인 경우 그림이 아니니 넘어감
            }
            if(visited[ny][nx]){
                continue; // 이미 방문한 경우 넘어감
            }

            visited[ny][nx] = true; // 첫 방문
            q.push({ny,nx}); 
        }

    }
    return area;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m; // 세로, 가로

    // 그림 정보 입력
    for(int y = 0; y<n ;y++){
        for(int x=0;x<m;x++){
            cin >> grid[y][x];
        }
    }

    int count = 0; // 그림 개수
    int maxArea = 0; // 최대 넓이

    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            // 방문 안 한 1 발견 -> 새 그림 인식
            if(grid[y][x] == 1 && !visited[y][x]){
                int area = bfs(y, x);
                count++;
                maxArea = max(maxArea, area);
            }
        }
    }

    cout << count << "\n" << maxArea << "\n";

    return 0;
}