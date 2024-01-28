#include<bits/stdc++.h>
using namespace std;

int N, M, weight[101], value[101], dp[101][100001];


int main(){
    cin >> N >> M;

    for(int i = 1 ; i <= N ; i ++){
        cin >> weight[i] >> value[i];
    } 

    for(int limit = 1 ; limit <= M ; limit ++){
        for(int i = 1 ; i <= N ; i ++){
            if(weight[i] <= limit) dp[i][limit] = value[i];
            if(limit-weight[i] > 0) dp[i][limit] += dp[i][limit-weight[i]];
            dp[i][limit] = max(dp[i][limit], dp[i-1][limit]);
        }
    }

    cout << dp[N][M] << '\n';

    return 0;
}