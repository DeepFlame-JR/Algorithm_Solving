#include<bits/stdc++.h>
using namespace std;

const int max_n = 104;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N, M, Map[max_n][max_n], Visit[max_n][max_n], x, y, nx, ny;

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < M; j ++){
            scanf("%1d", &Map[i][j]);
        }
    }

    queue<pair<int, int>> q;
    q.push({0,0});
    Visit[0][0] = 1;

    while(!q.empty()){
        tie(x, y) = q.front(); q.pop();

        for(int i = 0 ;i < 4 ;i ++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || Map[nx][ny] == 0 || Visit[nx][ny] > 0) continue;

            q.push({nx,ny});
            Visit[nx][ny] = Visit[x][y] + 1;
        }
    }

    cout << Visit[N-1][M-1] << '\n';

    return 0;
}