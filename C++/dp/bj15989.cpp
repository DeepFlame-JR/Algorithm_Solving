#include<bits/stdc++.h>
using namespace std;

int T, N, dp[10001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T; 

    dp[0] = 1;
    for(int i = 1 ; i <= 3 ; i ++){
        for(int j = 1 ; j <= 10000 ; j ++){
            if(j-i>=0) dp[j] += dp[j-i];
        }
    }
    
    for(int t = 0 ; t < T ; t++){
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}