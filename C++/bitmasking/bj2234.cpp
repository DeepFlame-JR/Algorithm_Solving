#include<bits/stdc++.h>
using namespace std;

// 방향 신경쓰자. 서.북.동.남.
const int dx[4] = {0,-1,0,1};
const int dy[4] = {-1,0,1,0};
const int max_n = 51;
int N, M, Map[max_n][max_n], Visit[max_n][max_n], room_area[max_n], mx, mx_comb;


int go(int x, int y, int room_num){
    if(Visit[x][y]) return 0; // 갈 곳이 없으면 리턴
    Visit[x][y] = room_num;
    int ret = 1;
    for(int i = 0 ; i < 4 ; i ++){
        if(!(Map[x][y] & (1<<i))){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;
            ret += go(nx, ny, room_num);
        }
    }
    return ret;
}

int main(){
    cin >> M >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j ++){
            cin >> Map[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j ++){
            if(!Visit[i][j]){
                cnt ++;
                room_area[cnt] = go(i, j, cnt);
                mx = max(mx, room_area[cnt]);
            }
        }
    }
        
    mx_comb = mx;
    for(int x = 0 ; x < N ; x++){
        for(int y = 0 ; y < M ; y ++){
            for(int i = 0 ; i < 4 ; i ++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;
                if(Visit[x][y] != Visit[nx][ny]){
                    mx_comb = max(mx_comb, room_area[Visit[x][y]] + room_area[Visit[nx][ny]]);
                }
            }
        }
    }

    cout << cnt << '\n' << mx << '\n' << mx_comb << '\n';

    return 0;
}