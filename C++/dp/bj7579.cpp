#include<bits/stdc++.h>
using namespace std;

int N, M, mem[101], cost[101], dp[101][10001];


int main(){
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i ++) cin >> mem[i];
    for(int i = 1 ; i <= N ; i ++) cin >> cost[i];

    for(int limit = 0 ; limit < 10001 ; limit++){
        for(int i = 1 ; i <= N ; i ++){
            if(cost[i] <= limit) dp[i][limit] = mem[i];
            if(limit-cost[i] >= 0) dp[i][limit] += dp[i-1][limit-cost[i]];

            dp[i][limit] = max(dp[i][limit], dp[i-1][limit]);
        }

        if(dp[N][limit] >= M){
            cout << limit << '\n';
            return 0;
        }
    }

    return 0;
}