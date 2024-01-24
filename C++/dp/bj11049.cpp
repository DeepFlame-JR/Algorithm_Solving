#include<bits/stdc++.h>
using namespace std;


const int INF = 1000000000;
int N, Map[501][2], DP[501][501];  

int main(){
    cin >> N;
    for(int i = 1 ; i <= N ; i++) cin >> Map[i][0] >> Map[i][1];

    for(int length = 1 ; length < N ; length ++){
        for(int start = 1 ; start+length<=N ; start ++){
            int end = start+length;
            DP[start][end] = INF;
            for(int k = start ; k <= end ; k++){  // start~k 까지 계산 + k+1~end까지 계산 + k 계산
                DP[start][end] = min(DP[start][end], DP[start][k] + DP[k+1][end] + Map[start][0]*Map[k][1]*Map[end][1]);
            }
        }
    }
    cout << DP[1][N] << '\n';

    return 0;
}