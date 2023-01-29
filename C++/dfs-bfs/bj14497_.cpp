/*
다음 갈 곳이 막혀있다면 뚫고 가는 문제
nx, ny를 temp에 넣어주면서 Map을 0으로 만들어도 됨 (왜냐면 다시 여기는 오지 않을 것이기 때문에)
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int max_n=301;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int N, M, jx, jy, bx, by, Visit[max_n][max_n], x, y, nx, ny;
char Map[max_n][max_n];

int main(){
    cin >> N >> M >> jx >> jy >> bx >> by;
    jx--, jy--, bx--, by--;

    // cout << N << M<< jx << jy << bx << by;

    for(int i = 0; i < N; i ++){
        scanf("%s", Map[i]);
    }

    queue<pii> q; q.push({jx, jy}); Visit[jx][jy] = 1;
    int turn = 0 ;
    while(Map[bx][by] != '0'){
        turn ++;

        queue<pii> padong;
        while(!q.empty()){
            tie(x, y) = q.front(); q.pop();

            for(int i = 0 ; i < 4 ; i ++){
                nx = x+dx[i]; ny = y+dy[i];
                if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1 || Visit[nx][ny]) continue;
                if(Map[nx][ny] != '0'){
                    Map[nx][ny] = '0';
                    padong.push({ny, ny});
                }
                else {
                    q.push({nx, ny});
                }
                Visit[nx][ny] = 1;
            }
        }
        q = padong;
    }

    cout << turn << '\n';
    return 0;
}