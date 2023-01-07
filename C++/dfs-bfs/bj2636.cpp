#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int N, M, Map[104][104], Visit[104][104], ans, cnt, prev_cnt, x, y, nx, ny;

void melt(){
    fill(&Visit[0][0], &Visit[0][0]+104*104, 0);
    queue<pair<int, int>> q;

    for(int i = 0 ; i < N ; i ++){
        q.push({i, 0});
        Visit[i][0] = 1;
        
        q.push({i, M-1});
        Visit[i][M-1] = 1;
    }

    for(int j = 0 ; j < M ; j++){
        q.push({0, j});
        Visit[0][j] = 1;

        q.push({N-1, j});
        Visit[N-1][j] = 1;
    }
    
    while(!q.empty()){
        tie(x, y) = q.front() ; q.pop();
        for(int i = 0 ; i < 4 ; i ++){
            nx = x + dx[i];
            ny = y + dy[i];

            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || Visit[nx][ny] == 1) continue;

            if(Map[nx][ny] == 0){
                q.push({nx,ny});
            }
            else if(Map[nx][ny] == 1){
                cnt --; // 치즈 제거
                Map[nx][ny] = 0;
            } 
            Visit[nx][ny] = 1;
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < M ; j++){
            cin >> Map[i][j];
            if(Map[i][j] == 1) cnt ++;
        }
    }

    while(cnt > 0){
        prev_cnt = cnt;
        melt();
        ans += 1;
    }
    
    cout << ans << '\n' << prev_cnt << '\n';

    return 0;
}