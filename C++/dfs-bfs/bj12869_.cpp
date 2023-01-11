#include<bits/stdc++.h>
using namespace std;

int hp[64][64][64], N, scv[3], a, b, c, ans; // 3기의 SCV를 hp 배열로 나타내는 것이 핵심!
int dam[6][3] = {
    {9,3,1},
    {9,1,3},
    {3,9,1},
    {3,1,9},
    {1,3,9},
    {1,9,3}
};

struct A{
    int a, b, c;
};

int main(){
    cin >> N;
    for(int n = 0 ; n < N ; n ++) cin >> scv[n];

    queue<A> q;
    q.push({scv[0], scv[1], scv[2]});
    hp[scv[0]][scv[1]][scv[2]] = 1;

    while(!q.empty()){
        a = q.front().a; b = q.front().b ; c = q.front().c; q.pop();
        if(hp[0][0][0] != 0) {
            cout << hp[0][0][0]-1 ;
            return 0;
        }

        for(int i = 0 ; i < 6 ; i++){
            int na = max(0, a-dam[i][0]);
            int nb = max(0, b-dam[i][1]);
            int nc = max(0, c-dam[i][2]);
            if(hp[na][nb][nc] == 0){
                hp[na][nb][nc] = hp[a][b][c] + 1;
                q.push({na,nb,nc});
            }
        }
    }

    return 0;
}