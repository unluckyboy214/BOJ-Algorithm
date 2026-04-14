#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N;

int common_grid[101][101];
int uncommon_grid[101][101];
bool visited[101][101];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void common_bfs(int start_y, int start_x){
    queue<pair<int,int>> q;
    q.push({start_y, start_x});
    visited[start_y][start_x] = true;
    char color = common_grid[start_y][start_x]; // 색 기억. 같은 색의 구역만 가야하기 때문

    while(!q.empty()){
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();

        for(int d=0 ; d<4 ; d++){
            int next_y = current_y + dy[d];
            int next_x = current_x + dx[d];

            if(next_y<0 || next_y>=N || next_x<0 || next_x>=N) continue;
            if(visited[next_y][next_x]) continue;
            if(common_grid[next_y][next_x] != color) continue; // 다른 색이면 넘어감

            visited[next_y][next_x] = true;
            q.push({next_y, next_x});
        }
    }

}

void uncommon_bfs(int start_y, int start_x){
    queue<pair<int,int>> q;
    q.push({start_y, start_x});
    visited[start_y][start_x] = true;
    char color = uncommon_grid[start_y][start_x]; // 색 기억. 같은 색의 구역만 가야하기 때문

    while(!q.empty()){
        int current_y = q.front().first;
        int current_x = q.front().second;
        q.pop();

        for(int d=0 ; d<4 ; d++){
            int next_y = current_y + dy[d];
            int next_x = current_x + dx[d];

            if(next_y<0 || next_y>=N || next_x<0 || next_x>=N) continue;
            if(visited[next_y][next_x]) continue;
            if(uncommon_grid[next_y][next_x] != color) continue; // 다른 색이면 넘어감

            visited[next_y][next_x] = true;
            q.push({next_y, next_x});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int y = 0; y<N; y++){
        for(int x=0 ; x<N ; x++){
            char ch;
            cin >> ch;
            common_grid[y][x] = ch;
            uncommon_grid[y][x] = (ch == 'G') ? 'R' : ch;
        }
    }

    int common_cnt = 0;
    int uncommon_cnt = 0;

    for(int y=0 ; y<N ; y++){
        for(int x=0 ; x<N ; x++){
            if(!visited[y][x]){
                common_bfs(y, x);
                common_cnt++;
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for(int y=0 ; y<N ; y++){
        for(int x=0 ; x<N ; x++){
            if(!visited[y][x]){
                uncommon_bfs(y, x);
                uncommon_cnt++;
            }
        }
    }

    cout << common_cnt << " " << uncommon_cnt ;

    return 0;
}