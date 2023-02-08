/*
숨바꼭질5
1. BFS에 turn 개념을 추가
2. 수빈이가 갔었던 곳을 동생이 도착했다? > 그곳은 수빈이가 +1,-1을 해서 돌아갈 수 있는 곳이다. > 홀수/짝수만 구분해서 Visit 구성
*/

#include<bits/stdc++.h>
using namespace std;

const int max_n = 500000;
int N, K, Visit[2][max_n+4], k, ok, turn;

int main(){
    cin >> N >> K;

    queue<int> q;
    Visit[0][N] = 1;
    q.push(N);
    k = K;

    while(!q.empty()){
        if(k > max_n) break;
        if(Visit[turn%2][k]){
            ok = 1;
            break;
        }

        turn++;
        k += turn;
        int q_size = q.size();
        for(int i = 0 ; i < q_size ; i++){
            int cur = q.front(); q.pop();
            for(int next : {cur+1, cur-1, 2*cur}){
                if(next < 0 || next > max_n || Visit[turn%2][next] > 0) continue;
                Visit[turn%2][next] = 1;
                q.push(next);
            }
        }
    }

    if(ok) cout << turn << '\n';
    else cout << -1 << '\n';

    return 0;
}