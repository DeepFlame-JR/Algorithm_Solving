#include<bits/stdc++.h>
using namespace std;

const int max_n = 100004;
int N, K, dp[max_n], pre[max_n];
queue<int> q;
stack<int> trace;

void push(int n, int cur){
    if(dp[n] == 0){
        dp[n] = dp[cur] + 1;
        pre[n] = cur;
        q.push(n);
    }
}

void go(int n){
    trace.push(n);
    if(n == N) return;
    go(pre[n]);
}

int main(){
    cin >> N >> K; 

    q.push(N);
    dp[N] = 1;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == K) break;
        
        for(int next : {cur+1, cur-1, cur*2}){
            if(next >= max_n || next < 0 || dp[next] > 0) continue;
            dp[next] = dp[cur] + 1;
            pre[next] = cur;
            q.push(next);
        }
    }

    cout << dp[K]-1 << '\n';

    go(K);
    while(!trace.empty()){
        cout << trace.top() << ' ';
        trace.pop();
    }
}
