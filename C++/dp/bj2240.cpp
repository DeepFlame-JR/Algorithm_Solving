#include<bits/stdc++.h>
using namespace std;

int N, M, tmp, arr[1001], dp[1001][2][31];

int main(){
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i ++){
        cin >> tmp;
        arr[i] = tmp-1;
    } 

    for(int time = 1 ; time <= N ; time ++){
        int pos = arr[time];
        int opposite = abs(pos-1);
        for(int w = 0 ; w <= M ; w++) {
            if(w%2 == pos) dp[time][pos][w] = dp[time-1][pos][w] + 1;  // 포지션에 가만히 있으면 자두를 먹을 수 있음
            dp[time][opposite][w] = dp[time-1][opposite][w];  
        }
        
        for(int w = 1 ; w <= M ; w++){
            if(w%2 == pos) dp[time][pos][w] = max(dp[time][pos][w], dp[time][opposite][w-1]+1);  // 자리를 옮겨서 자두를 먹는 경우
        }

        // for(int j = 0 ; j < 2 ; j++){
        //     for(int k = 0; k <= M ; k ++){
        //         cout << dp[time][j][k] << ' ';
        //     }cout << '\n';
        // }cout << '\n';
    }

    int result = 0;
    for(int j = 0 ; j < 2 ; j++){
        for(int k = 0; k <= M ; k ++){
            result = max(result, dp[N][j][k]);
        }
    }

    cout << result << '\n';

    return 0;
}