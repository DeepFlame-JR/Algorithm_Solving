#include<bits/stdc++.h>
using namespace std;


const int max_n = 104;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N, t, Map[max_n][max_n], Visit[max_n][max_n], ans, cx, cy, nx, ny, max_h, min_h = 104;

int main(){
    cin >> N;

    for(int i = 0 ; i < N ; i ++){
        for(int y = 0 ; y < N ; y++){
            cin >> t;
            Map[i][y] = t;

            max_h = max(max_h, t);
            min_h = min(min_h, t);
        }
    }

    ans = 1;
    for(int h = min_h ; h < max_h ; h++){ // 홍수의 높이마다 계산
        fill(&Visit[0][0], &Visit[0][0] + max_n*max_n, 0);

        int cnt = 0;
        for(int x = 0; x < N ; x ++){
            for(int y = 0 ; y < N; y ++){
                if(Visit[x][y] != 0 || Map[x][y] <= h) continue;

                cnt += 1;
                queue<pair<int,int>> q;
                q.push({x,y});
                Visit[x][y] = 1;

                while(!q.empty()){
                    tie(cx, cy) = q.front(); q.pop();

                    for(int i = 0 ; i < 4 ; i++){
                        nx = cx + dx[i];
                        ny = cy + dy[i];

                        if(nx < 0 || nx > N-1 || ny < 0 || ny > N-1 || Visit[nx][ny] != 0 || Map[nx][ny] <= h) continue;
                        q.push({nx, ny});
                        Visit[nx][ny] = 1;
                    }
                }

            }
        }

        ans = max(ans, cnt);
    }
    
    cout << ans << '\n';
    return 0;
}