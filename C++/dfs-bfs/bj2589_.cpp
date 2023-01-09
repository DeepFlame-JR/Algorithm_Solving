#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int N, M, ans, nx, ny, Visit[51][51];
char Map[51][51];
string temp;

void bfs(int x, int y){
    fill(&Visit[0][0], &Visit[0][0]+51*51, 0);
    queue<pair<int, int>> q;

    Visit[x][y] = 1 ; q.push({x, y});
    
    while(!q.empty()){
        tie(x, y) = q.front() ; q.pop();

        for(int i = 0 ; i < 4 ; i ++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || Visit[nx][ny] != 0 || Map[nx][ny] == 'W') continue;
            Visit[nx][ny] = Visit[x][y] + 1;
            ans = max(ans, Visit[nx][ny]);
            q.push({nx,ny});
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i ++){
        cin >> temp;
        for(int j = 0 ; j < M ; j++){
            Map[i][j] = temp[j];
        }
    }

    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < M ; j++){
            if(Map[i][j] == 'L') bfs(i, j);
        }
    }
    
    cout << ans-1 ;
}