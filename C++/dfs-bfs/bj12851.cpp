#include<bits/stdc++.h>
using namespace std;

const int max_n = 100006;
int N, K, n, c, dp[max_n], cnt_arr[max_n], ans=987654321;
queue<pair<int, int>> q;

void check(int origin, int a, int b){
    if(a < 0 || a > 100000 || b > cnt_arr[a]) return;

    if(dp[a] == 0){
        cnt_arr[a] = b;
        q.push({a, b});
    }
    dp[a] += dp[origin];
}

int main(){
    cin >> N >> K;

    fill(cnt_arr, cnt_arr+max_n, 987654321);
    q.push({N, 0});
    dp[N] = 1; cnt_arr[N] = 0;

    while(!q.empty()){
        tie(n, c) = q.front(); q.pop();
        // cout << n << ' ' << c << '\n';

        if(c > ans) continue;

        if(n == K){
            ans = c;
        }
        
        check(n, n-1, c+1);
        check(n, n+1, c+1);
        check(n, 2*n, c+1);
    }

    cout << ans << '\n' << dp[K];

    return 0;
}