#include<iostream>
#include<queue>

using namespace std;

const int MAX = 100001;
int dist[MAX];

void bfs(int start){
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        int next[] = {current - 1, current + 1, current * 2}; // 이동 방법 3가지

        for(int i=0;i<3;i++){
            int next_move = next[i];

            if(next_move < 0 || next_move >= MAX) continue; // 범위 초과는 넘어감
            if(dist[next_move] != -1) continue; // -1이 아니면 이미 방문. 넘어감

            dist[next_move] = dist[current] +1;
            q.push(next_move);
        }

    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    fill(dist, dist+MAX, -1); // -1로 초기화

    bfs(N);

    cout << dist[K] ;

    return 0;
}