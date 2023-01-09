#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321; // max값... 잘 잡자... ㅠㅠ
const int max_n = 1004;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N, M, Fire[max_n][max_n], Visit[max_n][max_n], fx, fy, x, y, nx, ny;
char Map[max_n][max_n];
string temp;

int main(){
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    fill(&Fire[0][0], &Fire[0][0]+max_n*max_n, INF); // 불이 도착하는 시간을 표시하는데 0이라면 혼선이 있을 수 있음
    fill(&Visit[0][0], &Visit[0][0]+max_n*max_n, 0);

    cin >> N >> M;
    for(int i = 0 ; i < N ; i ++){
        cin >> temp;
        for(int j = 0 ; j < M ; j ++){
            Map[i][j] = temp[j];
            if(Map[i][j] == 'F') {
                q1.push({i, j});
                Fire[i][j] = 1;
            }
            else if(Map[i][j] == 'J') {
                q2.push({i,j});
                Visit[i][j] = 1;
            }
        }
    }

    while(!q1.empty()){
        tie(x, y) = q1.front(); q1.pop();
        for(int i = 0 ; i < 4 ; i++){
            nx = x + dx[i]; ny = y + dy[i];
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || Fire[nx][ny] != INF || Map[nx][ny] == '#') continue;
            Fire[nx][ny] = Fire[x][y] + 1;
            q1.push({nx,ny});
        }
    }

    while(!q2.empty()){
        tie(x, y) = q2.front(); q2.pop();
        if(x == 0 || x == N-1 || y == 0 || y == M-1){
            cout << Visit[x][y];
            return 0;
        }

        for(int i = 0 ; i < 4 ; i++){
            nx = x + dx[i]; ny = y + dy[i];

            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;
            if(Visit[nx][ny] != 0 || Visit[x][y]+1 >= Fire[nx][ny] || Map[nx][ny] == '#') continue; 
            Visit[nx][ny] = Visit[x][y] + 1;
            q2.push({nx,ny});
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}