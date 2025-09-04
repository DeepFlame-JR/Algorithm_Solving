#include<bits/stdc++.h>
using namespace std;

const int max_n = 16;
const int dir_x[3][3] = {{0, 1, 0}, {0, 1, 1}, {0, 1, 1}}; // 가로, 대각선, 세로
const int dir_y[3][3] = {{1, 1, 0}, {1, 1, 0}, {0, 1, 0}};
int N, Map[max_n][max_n], dp[max_n][max_n][3];


int main(){
    cin >> N;

    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j ++){
            cin >> Map[i][j];
        }
    }

    dp[0][1][0] = 1;
    for(int x = 0 ; x < N ; x ++){  // 항상 오른쪽 아래로 움직이기 때문에 2중 for 문으로 처리할 수 있음
        for(int y = 0 ; y < N ; y ++){
            for(int dir = 0 ; dir < 3 ; dir ++){  // 현재 동작 (0: 가로, 1: 대각선, 2: 새로)
                for(int i = 0 ; i < 3 ; i ++){  // 다음 동작
                    if(dir_x[dir][i] + dir_y[dir][i] == 0) continue;
                    int nx = x+dir_x[dir][i];
                    int ny = y+dir_y[dir][i];
                    if(nx >= N || ny >= N) continue;
                    if(i == 1){
                        if(Map[nx][ny] == 1 || Map[nx-1][ny] == 1 || Map[nx][ny-1] == 1) continue;
                    }
                    else{
                        if(Map[nx][ny] == 1) continue;
                    }
                    dp[nx][ny][i] += dp[x][y][dir];
                }
            }
        }
    }

    cout << dp[N-1][N-1][0]+dp[N-1][N-1][1]+dp[N-1][N-1][2] << '\n';

    return 0;
}
