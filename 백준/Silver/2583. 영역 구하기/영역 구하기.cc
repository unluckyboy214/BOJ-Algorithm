#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int M, N, K; // 세로, 가로, 직사각형 개수
int grid[101][101];
bool visited[101][101];

int dy[] = {-1 , 1, 0, 0}; // 상하
int dx[] = {0, 0, -1, 1}; // 좌우

int bfs(int start_y, int start_x){
    queue<pair<int, int>> q;
    q.push({start_y, start_x});
    visited[start_y][start_x] = true;
    int area=0;

    while(!q.empty()){
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();
        area++;

        for(int d=0; d<4 ; d++){
            int next_y = current_y + dy[d];
            int next_x = current_x + dx[d];

            if(next_y < 0 || next_y >= M || next_x < 0 || next_x >= N) continue;
            if(visited[next_y][next_x]) continue; // 이미 방문하면 넘어감
            if(grid[next_y][next_x]) continue; // 1이면 직사각형 내부. 넘어감

            visited[next_y][next_x] = true;
            q.push({next_y, next_x});
        }

    }
    return area;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N >> K;

    for(int i=0 ; i<K ; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 좌표 -> 배열 인덱스 변환, 내부 1로 채우기
        for(int row = M-y2; row < M-y1 ; row++){
            for(int col = x1 ; col < x2 ; col++){
                grid[row][col]=1;
            }
        }
    }

    vector<int> areas;
    for(int y=0; y<M ; y++){
        for(int x=0 ; x<N ; x++){
            if(grid[y][x] == 0 && !visited[y][x]){
                areas.push_back(bfs(y,x));
            }
        }
    }

    sort(areas.begin(), areas.end());

    cout << areas.size() << "\n";
    for(int i=0; i<(int)areas.size(); i++){
        if(i > 0) cout << " ";
        cout << areas[i];
    }

    return 0;
}