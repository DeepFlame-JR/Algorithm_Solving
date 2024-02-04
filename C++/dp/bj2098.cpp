#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int max_n = 16;
int N, Map[max_n][max_n], dp[max_n][1<<max_n];

int tsp(int cur, int visit){
    if(visit == (1<<N)-1){  // 외판원이 다 돌았다.
        return Map[cur][0] ? Map[cur][0] : INF;  // 0 노드로 돌아갈 수 없으면 INF return
    }

    if(dp[cur][visit] > 0) return dp[cur][visit];  // 만약 현재 위치의 최적 값을 이미 구했다
    dp[cur][visit] = INF;

    for(int i = 0 ; i < N ; i ++){
        if(Map[cur][i] == 0) continue;  // 길이 없음
        if(visit & (1 << i)) continue;  // 이미 방문

        dp[cur][visit] = min(dp[cur][visit], Map[cur][i]+tsp(i, visit | (1<<i))); 
    }
    return dp[cur][visit];
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < N ; j++){
            cin >> Map[i][j];
        }
    }

    cout << tsp(0, 1) << '\n';

    return 0;
}