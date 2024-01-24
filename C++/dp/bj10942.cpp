#include<bits/stdc++.h>
using namespace std;

int N, M, arr[2001], s, e, dp[2001][2001]; // s > e까지는 팰린드롬이다


int go(){
    vector<pair<int, int>> success_list;
    while(s < e){
        if(dp[s][e] == 1) break;
        if(arr[s] != arr[e]) return 0;
        success_list.push_back({s, e});
        s++;
        e--;
    }
    for (pair<int,int> item : success_list){
        dp[item.first][item.second] = 1;
    }

    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1 ;i <= N ; i ++) cin >> arr[i];

    cin >> M;
    for(int _ = 0 ; _ < M ; _ ++){
        cin >> s >> e;
        cout << go() << '\n';
    }

    return 0;
}