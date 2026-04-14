#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N; // 지도의 크기

int grid[26][26];
int visited[26][26];

int dy[] = {-1, 1, 0, 0}; // 상, 하
int dx[] = {0, 0, -1, 1}; // 좌, 우

int bfs(int start_y, int start_x){
    queue<pair<int,int>> q;

    q.push({start_y, start_x});
    visited[start_y][start_x] = true;
    int cnt = 0; // 단지 집 개수 파악

    while(!q.empty()){
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();
        cnt++;

        for(int d=0 ; d<4 ; d++){
            int next_y = current_y + dy[d];
            int next_x = current_x + dx[d];

            if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) continue;
            if(grid[next_y][next_x] == 0) continue; // 다음이 0이면 넘어감
            if(visited[next_y][next_x]) continue; // 이미 방문한 경우 넘어감

            visited[next_y][next_x] = true;
            q.push({next_y, next_x});
        }

    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int y=0 ; y<N ; y++){
        for(int x=0 ; x<N ; x++){
            char ch;
            cin >> ch;
            grid[y][x] = ch - '0';
        }
    }

    vector<int> areas;
    int count = 0;

    for(int y=0 ; y<N ; y++){
        for(int x=0 ; x<N ; x++){
            if(grid[y][x] == 1 && !visited[y][x]){ // 방문하지 않은 단지면 집 개수 파악
                int area = bfs(y, x);
                count++;
                areas.push_back(area);
            }
        }
    }
    
    sort(areas.begin(), areas.end());

    cout << count << "\n";
    for(int i=0 ; i<areas.size() ; i++){
        cout << areas[i] << "\n";
    }

    return 0;
}